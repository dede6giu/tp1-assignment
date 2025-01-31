#include "../include/Modulos/MBAutenticacao.hpp"
#include "../include/Modulos/MBConta.hpp"
#include "../include/Modulos/MBViagem.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

MBAutenticacao::MBAutenticacao()
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

    cntrIBConta = new MBConta();
}

MBAutenticacao::~MBAutenticacao()
{
    sqlite3_close(banco);
    delete cntrIBConta;
}

bool MBAutenticacao::autenticar(Conta contaAutenticar)
{
    Codigo codigo(contaAutenticar.getValorCodigo());
    // if (!cntrIBConta->ler(codigo)) return false;

    string comando = "SELECT Senha FROM Contas WHERE Codigo='";
    comando += contaAutenticar.getValorCodigo();
    comando += "'";
    sqlite3_stmt *stmt;
    bool resultado = false;

    int rc = sqlite3_prepare_v2(banco, comando.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        throw runtime_error(sqlite3_errmsg(banco));
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        const char* p = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        string senhaCorreta(p);
        if (contaAutenticar.getValorSenha() == senhaCorreta) resultado = true;
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
