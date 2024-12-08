#ifndef HOSPEDAGEM_HPP_INCLUDED
#define HOSPEDAGEM_HPP_INCLUDED

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Dinheiro.hpp"
#include "Dominios/Nome.hpp"

/*!
    Entidade de Hospedagem
    232001667 - implementação
*/

class Hospedagem
{
    private:
        Codigo codigo;
        Nome nome;
        Avaliacao avaliacao;
        Dinheiro diaria;

    public:
        Hospedagem();

        void setValor(const Codigo&);
        inline std::string getValorCodigo() const {return this->codigo.getValor();}

        void setValor(const Nome&);
        inline std::string getValorNome() const {return this->nome.getValor();}

        void setValor(const Avaliacao&);
        inline int getValorAvaliacao() const {return this->avaliacao.getValor();}

        void setValor(const Dinheiro&);
        inline int getValorDiaria() const {return this->diaria.getValor();}
};

#endif // HOSPEDAGEM_HPP_INCLUDED
