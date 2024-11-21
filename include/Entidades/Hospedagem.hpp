#ifndef HOSPEDAGEM_HPP_INCLUDED
#define HOSPEDAGEM__HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Avaliacao.hpp"
#include "Dominios/Dinheiro.hpp"

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
    inline Codigo getCodigo() const {return this->codigo;}

    void setValor(const Nome&);
    inline Nome getNome() const {return this->nome;}

    void setValor(const Avaliacao&);
    inline Avaliacao getAvaliacao() const {return this->avaliacao;}

    void setValor(const Dinheiro&);
    inline Dinheiro getDiaria() const {return this->diaria;}
};

#endif // HOSPEDAGEM_HPP
