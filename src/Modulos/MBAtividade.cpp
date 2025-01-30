#include "../../include/Modulos/MBAtividade.hpp"
#include <stdexcept>

using namespace std;

MBAtividade::MBAtividade()
{
    int rc = sqlite3_open("data/Atividades.db", &banco);
    if (rc != SQLITE_OK)
    {
        throw runtime_error("Falha na abertura do banco de dados. O diretorio 'data/' existe?");
    }
}

MBAtividade::~MBAtividade()
{
    sqlite3_close(banco);
}

bool MBAtividade::criar(Atividade novoAtividade)
{
    // verifica se uma Atividade com mesma tag ja existe
    if (MBAtividade::ler(novoAtividade)) return false;

    string comando = "INSERT INTO ";
    comando += novoAtividade.getValorCodigo();
    comando += " (Tag, TagDestino, Nome, Data, Horario, Duracao, Preco, Avaliacao) VALUES ('";
    comando += novoAtividade.getTag().getValor();        comando += "', '";
    comando += novoAtividade.getTagDestino().getValor(); comando += "', '";
    comando += novoAtividade.getValorNome();             comando += "', '";
    comando += novoAtividade.getValorData();             comando += "', '";
    comando += novoAtividade.getValorHorario();          comando += "', ";
    comando += novoAtividade.getValorDuracao();          comando += ", ";
    comando += novoAtividade.getValorPreco();            comando += ", ";
    comando += novoAtividade.getValorAvaliacao();        comando += ");";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

void MBAtividade::criar(Codigo tabelaNova)
{
    string comando = "CREATE TABLE IF NOT EXISTS ";
    comando += tabelaNova.getValor();
    comando += " (Tag, TagDestino, Nome, Data, Horario, Duracao, Preco, Avaliacao);";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

bool MBAtividade::excluir(Atividade atividadeExcluir)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeExcluir)) return false;

    string comando = "DELETE FROM ";
    comando += atividadeExcluir.getValorCodigo();
    comando += " WHERE Tag='";
    comando += atividadeExcluir.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return true;
}

void MBAtividade::excluir(Codigo tabelaExcluir)
{
    string comando = "DROP TABLE IF EXISTS ";
    comando += tabelaExcluir.getValor();
    comando += " ;";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

void MBAtividade::excluir(Codigo contaExcluir, Codigo destinoExcluir)
{
    string comando = "DELETE FROM ";
    comando += contaExcluir.getValor();
    comando += " WHERE TagDestino='";
    comando += destinoExcluir.getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return;
}

bool MBAtividade::ler(Atividade atividadeCheque)
{
    bool resultado = false;
    Codigo contaAssociada(atividadeCheque.getValorCodigo());
    Codigo tag = atividadeCheque.getTag();
    // garante que a conta tem uma tabela
    MBAtividade::criar(contaAssociada);

    string comando = "SELECT Tag FROM ";
    comando += contaAssociada.getValor();
    comando += " WHERE Tag='";
    comando += tag.getValor();
    comando += "';";

    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(banco, comando.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        resultado = true;
    }
    if (rc != SQLITE_DONE)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }
    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }

    return resultado;
}

std::vector<Atividade> MBAtividade::ler(Codigo contaCheque, Codigo destinoCheque)
{
    vector<Atividade> resultado;
    // garante que a conta tem uma tabela
    MBAtividade::criar(contaCheque);

    string comando = "SELECT Tag, TagDestino, Nome, Data, Horario, Duracao, Preco, Avaliacao FROM ";
    comando += contaCheque.getValor();
    comando += " WHERE TagDestino='";
    comando += destinoCheque.getValor();
    comando += "';";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(banco, comando.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        const char* p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        string tag(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        string tagdestino(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        string nome(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        string data(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        string horario(p);
        int duracao = sqlite3_column_int(stmt, 5);
        int preco = sqlite3_column_int(stmt, 6);
        int avaliacao = sqlite3_column_int(stmt, 7);
        Atividade aux(contaCheque,
                      Nome(nome),
                      Data(data),
                      Horario(horario),
                      Duracao(duracao),
                      Dinheiro(preco),
                      Avaliacao(avaliacao),
                      Codigo(tag),
                      Codigo(tagdestino));
        resultado.push_back(aux);
    }
    if (rc != SQLITE_DONE)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }
    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }

    return resultado;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Nome novoNome)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Nome='";
    comando += novoNome.getValor();
    comando += "' WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Data novoData)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Data='";
    comando += novoData.getValor();
    comando += "' WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Horario novoHorario)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Horario='";
    comando += novoHorario.getValor();
    comando += "' WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Duracao novoDuracao)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Duracao=";
    comando += novoDuracao.getValor();
    comando += " WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Dinheiro novoDinheiro)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Dinheiro=";
    comando += novoDinheiro.getValor();
    comando += " WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBAtividade::atualizar(Atividade atividadeAtual, Avaliacao novoAvaliacao)
{
    // checa se a atividade existe
    if (!MBAtividade::ler(atividadeAtual)) return false;

    string comando = "UPDATE ";
    comando += atividadeAtual.getValorCodigo();
    comando += " SET Avaliacao=";
    comando += novoAvaliacao.getValor();
    comando += " WHERE Tag='";
    comando += atividadeAtual.getTag().getValor();
    comando += "';";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}
