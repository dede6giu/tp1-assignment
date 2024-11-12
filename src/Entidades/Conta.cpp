#include "Entidades/Conta.hpp"

bool Conta::setCodigo(const Codigo &novoCodigo)
{
    this -> codigo = novoCodigo;
    return true;
}

bool Conta::setSenha(const Senha &novaSenha)
{
    this -> senha = novaSenha;
    return true;
}
