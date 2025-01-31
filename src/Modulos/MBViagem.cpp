#include "../../include/Modulos/MBViagem.hpp"
#include "../../include/Modulos/MBAtividade.hpp"
#include "../../include/Modulos/MBHospedagem.hpp"
#include <stdexcept>

using namespace std;

MBViagem::MBViagem()
{
    int rc = sqlite3_open("data/Viagens.db", &banco);
    if (rc != SQLITE_OK)
    {
        throw runtime_error("Falha na abertura do banco de dados. O diretorio 'data/' existe?");
    }
}

MBViagem::~MBViagem()
{
    sqlite3_close(banco);
}

bool MBViagem::criar(Viagem novaViagem)
{
    // verifica se uma viagem com mesma tag ja existe
    if (MBViagem::ler(novaViagem)) return false;

    // garante que a conta tem uma tabela
    MBViagem::criar(Codigo(novaViagem.getValorCodigo()));

    string comando = "INSERT INTO ";
    comando += novaViagem.getValorCodigo();
    comando += " (Tag, Nome, Avaliacao) VALUES ('";
    comando += novaViagem.getTag().getValor(); comando += "', '";
    comando += novaViagem.getValorNome();      comando += "', ";
    comando += novaViagem.getValorAvaliacao(); comando += ");";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

void MBViagem::criar(Codigo tabelaNova)
{
    string comando = "CREATE TABLE IF NOT EXISTS ";
    comando += tabelaNova.getValor();
    comando += " (Tag, Nome, Avaliacao);";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

bool MBViagem::excluir(Viagem viagemExcluir)
{
    // checa se a viagem existe
    if (!MBViagem::ler(viagemExcluir)) return false;

    IBAtividade* dep1 = new MBAtividade();
    IBHospedagem* dep2 = new MBHospedagem();
    cntrIBDestino->setCntrIBAtividade(dep1);
    cntrIBDestino->setCntrIBHospedagem(dep2);
    // exclui destinos associados
    cntrIBDestino->excluir(Codigo(viagemExcluir.getValorCodigo()), viagemExcluir.getTag());
    delete dep1;
    delete dep2;

    string comando = "DELETE FROM ";
    comando += viagemExcluir.getValorCodigo();
    comando += " WHERE Tag='";
    comando += viagemExcluir.getTag().getValor();
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

void MBViagem::excluir(Codigo tabelaExcluir)
{
    IBAtividade* dep1 = new MBAtividade();
    IBHospedagem* dep2 = new MBHospedagem();
    cntrIBDestino->setCntrIBAtividade(dep1);
    cntrIBDestino->setCntrIBHospedagem(dep2);
    // exclui destinos da conta
    cntrIBDestino->excluir(tabelaExcluir);
    delete dep1;
    delete dep2;

    string comando = "DROP TABLE IF EXISTS ";
    comando += tabelaExcluir.getValor();
    comando += ";";
    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;
    return;
}

bool MBViagem::ler(Viagem viagemCheque)
{
    bool resultado = false;
    Codigo contaAssociada(viagemCheque.getValorCodigo());
    Codigo tag = viagemCheque.getTag();
    // garante que a conta tem uma tabela
    MBViagem::criar(contaAssociada);

    string comando = "SELECT Tag FROM ";
    comando += contaAssociada.getValor();
    comando += " WHERE Tag='";
    comando += tag.getValor();
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
        resultado = true;
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

std::vector<Viagem> MBViagem::ler(Codigo contaCheque)
{
    vector<Viagem> resultado;
    // garante que a conta tem uma tabela
    MBViagem::criar(contaCheque);

    string comando = "SELECT Tag, Nome, Avaliacao FROM ";
    comando += contaCheque.getValor();
    comando += ";";
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
        int avaliacao = sqlite3_column_int(stmt, 2);
        Viagem aux(Avaliacao(avaliacao),
                   contaCheque,
                   Nome(nome),
                   Codigo(tag));
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

bool MBViagem::atualizar(Viagem viagemAtual, Avaliacao novoAvaliacao)
{
    // checa se a viagem existe
    if (!MBViagem::ler(viagemAtual)) return false;

    string comando = "UPDATE ";
    comando += viagemAtual.getValorCodigo();
    comando += " SET Avaliacao=";
    comando += novoAvaliacao.getValor();
    comando += " WHERE Tag='";
    comando += viagemAtual.getTag().getValor();
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

bool MBViagem::atualizar(Viagem viagemAtual, Nome novoNome)
{
    // checa se a viagem existe
    if (!MBViagem::ler(viagemAtual)) return false;

    string comando = "UPDATE ";
    comando += viagemAtual.getValorCodigo();
    comando += " SET Nome='";
    comando += novoNome.getValor();
    comando += "' WHERE Tag='";
    comando += viagemAtual.getTag().getValor();
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
