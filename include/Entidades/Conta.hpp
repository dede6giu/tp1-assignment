#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Senha.hpp"

//! Entidade Conta
/*
    232002771 - implementação da entidade conta
*/

class Conta
{
    private:
        Codigo codigo;
        Senha senha;

    public:
        Conta(Codigo codigo, Senha senha);
        bool setCodigo(const Codigo&);
        Codigo getCodigo() const;
        bool setSenha(const Senha&);
        Senha getSenha() const;

};

#endif // CONTA_HPP_INCLUDED
