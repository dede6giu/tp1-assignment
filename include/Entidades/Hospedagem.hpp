#ifndef HOSPEDAGEM_HPP_INCLUDED
#define HOSPEDAGEM__HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Avaliacao.hpp"
#include "Dominios/Dinheiro.hpp"

//! Entidade Hospedagem 
/*!
    232001667 - implementação \n
    232002520 - documentação
*/

class Hospedagem
{
private:
    //! Codigo (atributo) 
    /*! Atributo da classe Codigo. */
    Codigo codigo;
    //! Nome (atributo) 
    /*! Atributo da classe Nome. */
    Nome nome;
    //! Avaliacao (atributo) 
    /*! Atributo da classe Avaliacao. */
    Avaliacao avaliacao;
    //! Dinheiro (atributo) 
    /*! Atributo da classe Dinheiro que representa a diária do estabelecimento. */
    Dinheiro diaria;
public:
    //! Construtor vazio
    /*! Constrói um objeto Hospedagem vazio. */
    Hospedagem();

    //! Hospedagem::setValor(const Codigo&)
    /*!
        Recebe um objeto Codigo e armazena no objeto Hospedagem.
        @param const Codigo.
    */
    void setValor(const Codigo&);
    //! Codigo Hospedagem::getCodigo() const
    /*!
        Retorna o objeto Codigo armazenado no objeto Hospedagem.
        @return objeto Codigo.
    */
    inline Codigo getCodigo() const {return this->codigo;}

    //! Hospedagem::setValor(const Nome&)
    /*!
        Recebe um objeto Nome e armazena no objeto Hospedagem.
        @param const Nome.
    */
    void setValor(const Nome&);
    //! Nome Hospedagem::getNome() const
    /*!
        Retorna o objeto Nome armazenado no objeto Hospedagem.
        @return objeto Nome.
    */
    inline Nome getNome() const {return this->nome;}

    //! Hospedagem::setValor(const Avaliacao&)
    /*!
        Recebe um objeto Avaliacao e armazena no objeto Hospedagem.
        @param const Avaliacao.
    */
    void setValor(const Avaliacao&);
    //! Avaliacao Hospedagem::getAvaliacao() const
    /*!
        Retorna o objeto Codigo armazenado no objeto Hospedagem.
        @return objeto Avalliacao.
    */
    inline Avaliacao getAvaliacao() const {return this->avaliacao;}

    //! Hospedagem::setValor(const Dinheiro&)
    /*!
        Recebe um objeto Dinheiro e armazena no objeto Hospedagem como diária.
        @param const Dinheiro.
    */
    void setValor(const Dinheiro&);
    //! Dinheiro Hospedagem::getDiaria() const
    /*!
        Retorna o objeto Dinheiro (diária) da Hospedagem.
        @return objeto Dinheiro.
    */
    inline Dinheiro getDiaria() const {return this->diaria;}
};
#endif // HOSPEDAGEM_HPP
