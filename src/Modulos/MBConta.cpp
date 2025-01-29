#include "../../include/Modulos/MBConta.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

MBConta::MBConta()
{
    int rc = sqlite3_open("data/Contas.db", &banco);

    if (rc != SQLITE_OK)
    {
        throw runtime_error("Falha na abertura do banco de dados. O diretorio 'data/' existe?");
    }

    string comando = "CREATE TABLE IF NOT EXISTS Contas (Codigo, Senha);";
    char* errmsg;
    rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);

    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }

    delete errmsg;
}

MBConta::~MBConta()
{
    sqlite3_close(banco);
}

bool MBConta::criar(Conta novaConta)
{
    Codigo codigo(novaConta.getValorCodigo());
    if (MBConta::ler(codigo)) return false;

    string senha = novaConta.getValorSenha();
    string comando = "INSERT INTO Contas (Codigo, Senha) VALUES ('";
    comando += novaConta.getValorCodigo();
    comando += "', '";
    comando += novaConta.getValorSenha();
    comando += "');";

    char* errmsg;
    int rc = sqlite3_exec(banco, comando.c_str(), nullptr, 0, &errmsg);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(errmsg);
    }
    delete errmsg;

    return true;
}

bool MBConta::excluir(Conta contaExcluir)
{
    Codigo codigo(contaExcluir.getValorCodigo());
    if (!MBConta::ler(codigo)) return false;

    // exclui viagens da conta
    cntrIBViagem->excluir(codigo);

    string comando = "DELETE FROM Contas WHERE Codigo='";
    comando += contaExcluir.getValorCodigo();
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

bool MBConta::ler(Codigo contaCheque)
{
    bool resultado = false;

    string comando = "SELECT Codigo FROM Contas WHERE Codigo='";
    comando += contaCheque.getValor();
    comando += "'";
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

bool MBConta::atualizar(Conta contaAtualizar, Senha novaSenha)
{
    Codigo codigo(contaAtualizar.getValorCodigo());
    if (!MBConta::ler(codigo)) return false;

    string senha = contaAtualizar.getValorSenha();
    string comando = "UPDATE Contas SET Senha='";
    comando += novaSenha.getValor();
    comando += "' WHERE Codigo='";
    comando += contaAtualizar.getValorCodigo();
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
