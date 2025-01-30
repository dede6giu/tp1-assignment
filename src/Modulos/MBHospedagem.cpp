#include "../../include/Modulos/MBHospedagem.hpp"
#include <stdexcept>

using namespace std;

MBHospedagem::MBHospedagem()
{
    int rc = sqlite3_open("data/Hospedagens.db", &banco);
    if (rc != SQLITE_OK)
    {
        throw runtime_error("Falha na abertura do banco de dados. O diretorio 'data/' existe?");
    }
}

MBHospedagem::~MBHospedagem()
{
    sqlite3_close(banco);
}

bool MBHospedagem::criar(Hospedagem novoHospedagem)
{
    // verifica se uma Hospedagem com mesma tag ja existe
    if (MBHospedagem::ler(novoHospedagem)) return false;

    string comando = "INSERT INTO ";
    comando += novoHospedagem.getValorCodigo();
    comando += " (Tag, TagDestino, Nome, Avaliacao, Diaria) VALUES ('";
    comando += novoHospedagem.getTag().getValor();        comando += "', '";
    comando += novoHospedagem.getTagDestino().getValor(); comando += "', '";
    comando += novoHospedagem.getValorNome();             comando += "', ";
    comando += novoHospedagem.getValorAvaliacao();        comando += ", ";
    comando += novoHospedagem.getValorDiaria();           comando += ");";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

void MBHospedagem::criar(Codigo tabelaNova)
{
    string comando = "CREATE TABLE IF NOT EXISTS ";
    comando += tabelaNova.getValor();
    comando += " (Tag, TagDestino, Nome, Avaliacao, Diaria);";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

bool MBHospedagem::excluir(Hospedagem hospedagemExcluir)
{
    // checa se a hospedagem existe
    if (!MBHospedagem::ler(hospedagemExcluir)) return false;

    string comando = "DELETE FROM ";
    comando += hospedagemExcluir.getValorCodigo();
    comando += " WHERE Tag='";
    comando += hospedagemExcluir.getTag().getValor();
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

void MBHospedagem::excluir(Codigo tabelaExcluir)
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

void MBHospedagem::excluir(Codigo contaExcluir, Codigo destinoExcluir)
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

bool MBHospedagem::ler(Hospedagem hospedagemCheque)
{
    bool resultado = false;
    Codigo contaAssociada(hospedagemCheque.getValorCodigo());
    Codigo tag = hospedagemCheque.getTag();
    // garante que a conta tem uma tabela
    MBHospedagem::criar(contaAssociada);

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

std::vector<Hospedagem> MBHospedagem::ler(Codigo contaCheque, Codigo destinoCheque)
{
    vector<Hospedagem> resultado;
    // garante que a conta tem uma tabela
    MBHospedagem::criar(contaCheque);

    string comando = "SELECT Tag, TagDestino, Nome, Avaliacao, Diaria FROM ";
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
        int avaliacao = sqlite3_column_int(stmt, 3);
        int diaria = sqlite3_column_int(stmt, 4);
        Hospedagem aux(contaCheque,
                       Nome(nome),
                       Avaliacao(avaliacao),
                       Dinheiro(diaria),
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

bool MBHospedagem::atualizar(Hospedagem hospedagemAtual, Nome novoNome)
{
    // checa se a hospedagem existe
    if (!MBHospedagem::ler(hospedagemAtual)) return false;

    string comando = "UPDATE ";
    comando += hospedagemAtual.getValorCodigo();
    comando += " SET Nome='";
    comando += novoNome.getValor();
    comando += "' WHERE Tag='";
    comando += hospedagemAtual.getTag().getValor();
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

bool MBHospedagem::atualizar(Hospedagem hospedagemAtual, Dinheiro novoDiaria)
{
    // checa se a hospedagem existe
    if (!MBHospedagem::ler(hospedagemAtual)) return false;

    string comando = "UPDATE ";
    comando += hospedagemAtual.getValorCodigo();
    comando += " SET Diaria=";
    comando += novoDiaria.getValor();
    comando += " WHERE Tag='";
    comando += hospedagemAtual.getTag().getValor();
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

bool MBHospedagem::atualizar(Hospedagem hospedagemAtual, Avaliacao novoAvaliacao)
{
    // checa se a hospedagem existe
    if (!MBHospedagem::ler(hospedagemAtual)) return false;

    string comando = "UPDATE ";
    comando += hospedagemAtual.getValorCodigo();
    comando += " SET Avaliacao=";
    comando += novoAvaliacao.getValor();
    comando += " WHERE Tag='";
    comando += hospedagemAtual.getTag().getValor();
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
