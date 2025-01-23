#include "../../include/Stubs/SBAutenticacao.hpp"
#include <iostream>

using namespace std;

const string SBAutenticacao::TRIGGER_FALHA = "oiooia";

bool SBAutenticacao::autenticar(Conta contaRecebida)
{
    cout << endl        << "SBAutenticacao::autenticar"   << endl;
    cout << "Codigo = " << contaRecebida.getValorCodigo() << endl;
    cout << "Senha  = " << contaRecebida.getValorSenha()  << endl;

    if (contaRecebida.getValorCodigo() == TRIGGER_FALHA)
    {
        return false;
    }

    return true;
}
