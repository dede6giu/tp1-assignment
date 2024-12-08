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
        Conta(const Codigo&, const Senha&);

        void setValor(const Codigo&);
        std::string getValorCodigo() const;

        void setValor(const Senha&);
        std::string getValorSenha() const;

};

inline std::string Conta::getValorCodigo() const
{
    return this->codigo.getValor();
}

inline std::string Conta::getValorSenha() const
{
    return this->senha.getValor();
}

#endif // CONTA_HPP_INCLUDED
