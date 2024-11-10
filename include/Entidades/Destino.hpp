#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Avaliacao.hpp"


//! Entidade Destino
/*!
    Entidade Destino \n
    232013031 - implementação
*/

class Destino
{
    private:
        Codigo codigo;
        Nome nome;
        Data inicio;
        Data fim;
        Avaliacao avaliacao;
        bool validar(); //!< não ainda implementado

    public:
        Destino();

        void setValor(const Codigo&);
        inline Codigo getValorCodigo() const;

        void setValor(const Nome&);
        inline Nome getValorNome() const;

        void setValor(const Avaliacao&);
        inline Avaliacao getValorAvaliacao() const;

        void setValor(const Data&, bool);
        inline Data getValorInicio() const;
        inline Data getValorFim() const;
};

inline Codigo Destino::getValorCodigo() const {
    return this->codigo;
}

inline Nome Destino::getValorNome() const {
    return this->nome;
}

inline Avaliacao Destino::getValorAvaliacao() const {
    return this->avaliacao;
}

inline Data Destino::getValorInicio() const {
    return this->inicio;
}

inline Data Destino::getValorFim() const {
    return this->fim;
}


#endif // DESTINO_HPP_INCLUDED
