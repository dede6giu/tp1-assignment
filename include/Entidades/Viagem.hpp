#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"

//! Entidade Viagem
/*!
    232006028 - implementação
*/

class Viagem {
    private:
        Avaliacao avaliacao;
        Codigo codigo;
        Nome nome;

    public:
        Viagem();

        void setValor(const Avaliacao&);
        Avaliacao getAvaliacao() const;

        void setValor(const Codigo&);
        Codigo getCodigo() const;

        void setValor(const Nome&);
        Nome getNome() const;
};

inline Avaliacao Viagem::getAvaliacao() const {
    return this->avaliacao;
}

inline Codigo Viagem::getCodigo() const {
    return this->codigo;
}

inline Nome Viagem::getNome() const {
    return this->nome;
}

#endif // VIAGEM_HPP_INCLUDED
