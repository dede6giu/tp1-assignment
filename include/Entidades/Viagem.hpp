#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include <string>

//! Entidade Viagem
/*!
    232006028 - implementação \n
    232002520 - documentação
*/

class Viagem {
    private:
        //! Avaliacao (atributo)
        /*! Atributo de classe Avaliacao. */
        Avaliacao avaliacao;
        //! Codigo (atributo)
        /*! Atributo de classe Codigo. */
        Codigo codigo;
        //! Nome (atributo)
        /*! Atributo de classe Nome. */
        Nome nome;

    public:
        //! Construtor vazio
        /*! Constrói um objeto Viagem vazio. */
        Viagem();
        Viagem(const Avaliacao&, const Codigo&, const Nome&);


        //! Viagem::setValor(const Avaliaacao&)
        /*!
            Recebe um objeto Avaliacao e armazena no objeto Viagem.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);
        //! Avaliacao Viagem::getAvaliacao() const
        /*!
            Retorna o objeto Avaliacao armazenado no objeto Viagem.
            @return int valor do parâmetro avaliacao.
        */
        int getValorAvaliacao() const;

        //! Viagem::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena no objeto Viagem.
            @param const Codigo.
        */
        void setValor(const Codigo&);
        //! Codigo Viagem::getCodigo() const
        /*!
            Retorna o objeto Codigo armazenado no objeto Viagem.
            @return string valor do parâmetro codigo.
        */
        std::string getValorCodigo() const;

        //! Viagem::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena no objeto Viagem.
            @param const Nome.
        */
        void setValor(const Nome&);
        //! Nome Viagem::getNome() const
        /*!
            Retorna o objeto Nome armazenado no objeto Viagem.
            @return string valor do parâmetro nome.
        */
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
