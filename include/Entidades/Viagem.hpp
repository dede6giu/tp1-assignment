#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"

//! Entidade Viagem
/*!
    232006028 - implementação \n
    232002520 - documentação
*/

class Viagem {
    private:
        //! Objeto Avaliacao
        /*! Atributo de classe Avaliacao. */
        Avaliacao avaliacao;
        //! Objeto Codigo
        /*! Atributo de classe Codigo. */
        Codigo codigo;
        //! Objeto Nome
        /*! Atributo de classe Nome. */
        Nome nome;

    public:
        //! Construtor vazio
        /*! Constrói um objeto Viagem vazio. */
        Viagem();

        //! Viagem::setValor(const Avaliaacao&)
        /*!
            Recebe um objeto Avaliacao e armazena no objeto Viagem.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);
        //! Avaliacao Viagem::getAvaliacao() const
        /*!
            Retorna o objeto Avaliacao armazenado no objeto Viagem.
            @return objeto Avaliacao.
        */
        Avaliacao getAvaliacao() const;

        //! Viagem::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena no objeto Viagem.
            @param const Codigo.
        */
        void setValor(const Codigo&);
        //! Codigo Viagem::getCodigo() const
        /*!
            Retorna o objeto Codigo armazenado no objeto Viagem.
            @return objeto Codigo.
        */
        Codigo getCodigo() const;

        //! Viagem::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena no objeto Viagem.
            @param const Nome.
        */
        void setValor(const Nome&);
        //! Nome Viagem::getNome() const
        /*!
            Retorna o objeto Nome armazenado no objeto Viagem.
            @return objeto Nome.
        */
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
