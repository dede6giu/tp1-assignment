#include "../../include/Stubs/SBConta.hpp"
#include <iostream>

using namespace std;

const string SBConta::TRIGGER_FALHA_CODIGO = "oiooia";
const string SBConta::TRIGGER_FALHA_SENHA  = "12387";

bool SBConta::criar(Conta contaRecebida)
{
    cout << endl        << "SBConta::criar"               << endl;
    cout << "Codigo = " << contaRecebida.getValorCodigo() << endl;
    cout << "Senha  = " << contaRecebida.getValorSenha()  << endl;

    if (contaRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO
        || contaRecebida.getValorSenha() == TRIGGER_FALHA_SENHA)
    {
        return false;
    }
    return true;
}

bool SBConta::excluir(Conta contaRecebida)
{
    cout << endl        << "SBConta::excluir"             << endl;
    cout << "Codigo = " << contaRecebida.getValorCodigo() << endl;
    cout << "Senha  = " << contaRecebida.getValorSenha()  << endl;

    if (contaRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO
        || contaRecebida.getValorSenha() == TRIGGER_FALHA_SENHA)
    {
        return false;
    }
    return true;
}

bool SBConta::ler(Codigo codigoRecebido)
{
    cout << endl        << "SBConta::ler"            << endl;
    cout << "Codigo = " << codigoRecebido.getValor() << endl;

    if (codigoRecebido.getValor() == TRIGGER_FALHA_CODIGO)
    {
        return false;
    }
    return true;
}

bool SBConta::atualizar(Conta contaRecebida, Senha senhaNova)
{
    cout << endl               << "SBConta::atualizar"           << endl;
    cout << "Codigo        = " << contaRecebida.getValorCodigo() << endl;
    cout << "Senha Antiga  = " << contaRecebida.getValorSenha()  << endl;
    cout << "Senha Nova    = " << senhaNova.getValor()           << endl;

    if (contaRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO
        || contaRecebida.getValorSenha() == TRIGGER_FALHA_SENHA
        || senhaNova.getValor() == TRIGGER_FALHA_SENHA)
    {
        return false;
    }
    return true;
}
