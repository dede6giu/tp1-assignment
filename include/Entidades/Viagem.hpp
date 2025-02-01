#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include "../../include/Dominios/Avaliacao.hpp"
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"

#include <string>

//! Entidade Viagem
/*!
    232006028 - implementação \n
    232002520 - documentação \n
    232002771 - documentação
*/

class Viagem {
    private:

        //! Tag da viagem
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) da viagem. */
        Codigo tag;


        //! Avaliação da viagem
        /*! Atributo Avaliacao que armazena a avaliação da viagem. */
        Avaliacao avaliacao;

        //! Código da viagem
        /*! Atributo Codigo que armazena o código da viagem. */
        Codigo codigo;

        //! Nome da viagem
        /*! Atributo Nome que armazena o nome da viagem. */
        Nome nome;

    public:

        //! Construtor vazio
        /*! Constrói um objeto Viagem vazio.
            @sa Viagem(const Avaliacao&, const Codigo&, const Nome&)
         */
        Viagem();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Viagem e pede como parâmetros: uma Avaliacao, um Codigo e um Nome.
            @param const Avaliacao a ser armazenado.
            @param const Codigo a ser armazenado.
            @param const Nome a ser armazenado.
            @sa Viagem()
        */
        Viagem(const Avaliacao&, const Codigo&, const Nome&, const Codigo&);


        //! Viagem::setValor(const Avaliaacao&)
        /*!
            Recebe um Avaliacao e armazena no objeto Viagem.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! Avaliacao Viagem::getAvaliacao() const
        /*!
            Retorna o Avaliacao armazenado no objeto Viagem.
            @return int valor do parâmetro avaliacao.
        */
        int getValorAvaliacao() const;

        //! Viagem::setValor(const Codigo&)
        /*!
            Recebe um Codigo e armazena no objeto Viagem.
            @param const Codigo.
        */
        void setValor(const Codigo&);

        //! Codigo Viagem::getCodigo() const
        /*!
            Retorna o Codigo armazenado no objeto Viagem.
            @return string valor do parâmetro codigo.
        */
        std::string getValorCodigo() const;

        //! Viagem::setValor(const Nome&)
        /*!
            Recebe um Nome e armazena no objeto Viagem.
            @param const Nome.
        */
        void setValor(const Nome&);
        //! Nome Viagem::getNome() const
        /*!
            Retorna o Nome armazenado no objeto Viagem.
            @return string valor do parâmetro nome.
        */
        std::string getValorNome() const;

        //! inline Viagem::getTag()
        /* Retorna a tag do objeto Viagem. */
        inline Codigo getTag() const { return this->tag; }

        //! inline Viagem::getTag()
        /* Recebe Codigo& e armazena como nova tag. */
        void setTag(Codigo);
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
