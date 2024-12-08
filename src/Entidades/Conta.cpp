#include "../../include/Entidades/Conta.hpp"

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Senha.hpp"

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

void Conta::setValor(const Codigo &novoCodigo)
{
    this -> codigo = novoCodigo;
}

void Conta::setValor(const Senha &novaSenha)
{
    this -> senha = novaSenha;
}
