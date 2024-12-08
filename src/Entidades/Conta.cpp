#include "Entidades/Conta.hpp"

#include "Dominios/Codigo.hpp"
#include "Dominios/Senha.hpp"

Conta::Conta()
{
    codigo = Codigo();
    senha = Senha();
}

Conta::Conta(const Codigo& cc,
             const Senha& ss)
{
    codigo = cc;
    senha = ss;
}

bool Conta::setValor(const Codigo &novoCodigo)
{
    this -> codigo = novoCodigo;
    return true;
}

bool Conta::setValor(const Senha &novaSenha)
{
    this -> senha = novaSenha;
    return true;
}
