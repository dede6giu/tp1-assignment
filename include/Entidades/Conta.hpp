#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Senha.hpp"

//! Entidade Conta
/*!
    232002771 - implementação da entidade conta
*/

class Conta
{
    private:
        Codigo codigo;
        Senha senha;

    public:
        Conta();
        Conta(Codigo&, Senha&);

        bool setCodigo(const Codigo&);
        Codigo getCodigo() const;

        bool setSenha(const Senha&);
        Senha getSenha() const;

};


inline Codigo Conta::getCodigo() const
{
    return codigo;
}

inline Senha Conta::getSenha() const
{
    return senha;
}

#endif // CONTA_HPP_INCLUDED
