#include "../../include/Modulos/MBDestino.hpp"
#include "../../include/Modulos/MBAtividade.hpp"
#include "../../include/Modulos/MBHospedagem.hpp"
#include <stdexcept>

using namespace std;

MBDestino::MBDestino()
{
    int rc = sqlite3_open("data/Destinos.db", &banco);
    if (rc != SQLITE_OK)
    {
        throw runtime_error("Falha na abertura do banco de dados. O diretorio 'data/' existe?");
    }
    cntrIBAtividade = new MBAtividade();
    cntrIBHospedagem = new MBHospedagem();
}

MBDestino::~MBDestino()
{
    sqlite3_close(banco);
    delete cntrIBAtividade;
    delete cntrIBHospedagem;
}

bool MBDestino::criar(Destino novoDestino)
{
    // verifica se um destino com mesma tag ja existe
    if (MBDestino::ler(novoDestino)) return false;

    string comando = "INSERT INTO ";
    comando += novoDestino.getValorCodigo();
    comando += " (Tag, TagViagem, Nome, Inicio, Fim, Avaliacao) VALUES ('";
    comando += novoDestino.getTag().getValor();            comando += "', '";
    comando += novoDestino.getTagViagem().getValor();      comando += "', '";
    comando += novoDestino.getValorNome();                 comando += "', '";
    comando += novoDestino.getValorInicio();               comando += "', '";
    comando += novoDestino.getValorFim();                  comando += "', '";
    comando += to_string(novoDestino.getValorAvaliacao()); comando += "');";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

void MBDestino::criar(Codigo tabelaNova)
{
    string comando = "CREATE TABLE IF NOT EXISTS \"";
    comando += tabelaNova.getValor();
    comando += "\" (Tag, TagViagem, Nome, Inicio, Fim, Avaliacao);";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

bool MBDestino::excluir(Destino destinoExcluir)
{
    // checa se o destino existe
    if (!MBDestino::ler(destinoExcluir)) return false;

    // exclui atividades associadas
    cntrIBAtividade->excluir(Codigo(destinoExcluir.getValorCodigo()), destinoExcluir.getTag());
    // exclui hospedagem associadas
    cntrIBHospedagem->excluir(Codigo(destinoExcluir.getValorCodigo()), destinoExcluir.getTag());

    string comando = "DELETE FROM ";
    comando += destinoExcluir.getValorCodigo();
    comando += " WHERE Tag='";
    comando += destinoExcluir.getTag().getValor();
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

void MBDestino::excluir(Codigo tabelaExcluir)
{
    // exclui atividades da conta
    cntrIBAtividade->excluir(tabelaExcluir);
    // exclui hospedagens da conta
    cntrIBHospedagem->excluir(tabelaExcluir);

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

void MBDestino::excluir(Codigo contaExcluir, Codigo viagemExcluir)
{
    vector<string> destinos;

    string comando = "SELECT Tag FROM ";
    comando += contaExcluir.getValor();
    comando += " WHERE TagViagem='";
    comando += viagemExcluir.getValor();
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
        string aux(p);
        destinos.push_back(aux);
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

    for (auto itr = destinos.begin(); itr != destinos.end(); itr++)
    {
        // exclui atividades associadas
        cntrIBAtividade->excluir(contaExcluir, Codigo(*itr));
        // exclui hospedagem associadas
        cntrIBHospedagem->excluir(contaExcluir, Codigo(*itr));
    }

    comando = "DELETE FROM ";
    comando += contaExcluir.getValor();
    comando += " WHERE TagViagem='";
    comando += viagemExcluir.getValor();
    comando += "';";

    char* errmsg;
    rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return;
}

bool MBDestino::ler(Destino destinoCheque)
{
    bool resultado = false;
    Codigo contaAssociada(destinoCheque.getValorCodigo());
    Codigo tag = destinoCheque.getTag();
    // garante que a conta tem uma tabela
    MBDestino::criar(contaAssociada);

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

std::vector<Destino> MBDestino::ler(Codigo contaCheque, Codigo viagemCheque)
{
    vector<Destino> resultado;
    // garante que a conta tem uma tabela
    MBDestino::criar(contaCheque);

    string comando = "SELECT Tag, Nome, Inicio, Fim, Avaliacao FROM ";
    comando += contaCheque.getValor();
    comando += " WHERE TagViagem='";
    comando += viagemCheque.getValor();
    comando += "';";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(banco, comando.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        string err = sqlite3_errmsg(banco);
        throw runtime_error(err);
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        const char* p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        string tag(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        string nome(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        string inicio(p);
        p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        string fim(p);
        int avaliacao = sqlite3_column_int(stmt, 4);
        Destino aux(contaCheque,
                    Nome(nome),
                    Data(inicio),
                    Data(fim),
                    Avaliacao(avaliacao),
                    Codigo(tag),
                    viagemCheque);
        resultado.push_back(aux);
    }
    if (rc != SQLITE_DONE)
    {
        string err = sqlite3_errmsg(banco);
        throw runtime_error(err);
    }
    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK)
    {
        string err = sqlite3_errmsg(banco);
        throw runtime_error(err);
    }

    return resultado;
}

bool MBDestino::atualizar(Destino destinoAtual, Nome novoNome)
{
    // checa se o destino existe
    if (!MBDestino::ler(destinoAtual)) return false;

    string comando = "UPDATE ";
    comando += destinoAtual.getValorCodigo();
    comando += " SET Nome='";
    comando += novoNome.getValor();
    comando += "' WHERE Tag='";
    comando += destinoAtual.getTag().getValor();
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

bool MBDestino::atualizar(Destino destinoAtual, Data novaData, bool fim)
{
    // checa se o destino existe
    if (!MBDestino::ler(destinoAtual)) return false;

    string comando = "UPDATE ";
    comando += destinoAtual.getValorCodigo();
    if (fim)
    {
        comando += " SET Inicio='";
    }
    else
    {
        comando += " SET Fim='";
    }
    comando += novaData.getValor();
    comando += "' WHERE Tag='";
    comando += destinoAtual.getTag().getValor();
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

bool MBDestino::atualizar(Destino destinoAtual, Avaliacao novaAvaliacao)
{
    // checa se o destino existe
    if (!MBDestino::ler(destinoAtual)) return false;

    string comando = "UPDATE ";
    comando += destinoAtual.getValorCodigo();
    comando += " SET Avaliacao='";
    comando += to_string(novaAvaliacao.getValor());
    comando += "' WHERE Tag='";
    comando += destinoAtual.getTag().getValor();
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
