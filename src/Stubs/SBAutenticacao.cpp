#include "../../include/Stubs/SBAutenticacao.hpp"
#include <iostream>

const std::string SBAutenticacao::TRIGGER_FALHA = "oiooia";

bool SBAutenticacao::autenticar(Conta contaRecebida)
{
    std::cout << std::endl   << "SBAutenticacao::autenticar"   << std::endl;
    std::cout << "Codigo = " << contaRecebida.getValorCodigo() << std::endl;
    std::cout << "Senha  = " << contaRecebida.getValorSenha()  << std::endl;

    if (contaRecebida.getValorCodigo() == TRIGGER_FALHA)
    {
        return false;
    }

    return true;
}
