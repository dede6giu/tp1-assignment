#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include <string>

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
        Viagem(const Avaliacao&, const Codigo&, const Nome&);


        void setValor(const Avaliacao&);
        int getValorAvaliacao() const;

        void setValor(const Codigo&);
        std::string getValorCodigo() const;

        void setValor(const Nome&);
        std::string getValorNome() const;
};

inline int Viagem::getValorAvaliacao() const {
    return this->avaliacao.getValor();
}

inline std::string Viagem::getValorCodigo() const {
    return this->codigo.getValor();
}

inline std::string Viagem::getValorNome() const {
    return this->nome.getValor();
}

#endif // VIAGEM_HPP_INCLUDED
