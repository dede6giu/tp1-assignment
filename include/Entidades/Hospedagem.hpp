#ifndef HOSPEDAGEM_HPP_INCLUDED
#define HOSPEDAGEM_HPP_INCLUDED

#include "../../include/Dominios/Avaliacao.hpp"
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Dinheiro.hpp"
#include "../../include/Dominios/Nome.hpp"


//! Entidade Hospedagem
/*!
    232001667 - implementação. \n
    232002520 - documentação. \n
    232002771 - documentação. \n
    232013031 - documentação.
*/

class Hospedagem
{
    private:

        //! Tag da hospedagem
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) da hospedagem. */
        Codigo tag;
        
        //! Tag do destino relacionado à hospedagem
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) do destino relacionado à hospedagem. */
        Codigo tagDestino;


        //! Código da hospedagem
        /*! Atributo Codigo que armazena o código da hospedagem. */
        Codigo codigo;

        //! Nome da hospedagem
        /*! Atributo Nome que armazena o nome da hospedagem. */
        Nome nome;

        //! Avaliacao da hospedagem
        /*! Atributo Avaliacao que armazena a avaliação da hospedagem. */
        Avaliacao avaliacao;

        //! Dinheiro da hospedagem
        /*! Atributo Dinheiro que representa a diária da hospedagem. */
        Dinheiro diaria;

    public:

        //! Construtor vazio
        /*! Constrói um objeto Hospedagem vazio.
            @sa Hospedagem(const Codigo&, const Nome&, const Avaliacao&, const Dinheiro&)
        */
        Hospedagem();

        //! Construtor paramétrico.
        /*!
            Constrói um objeto Hospedagem e pede 2 parâmetros: um Codigo, um Nome, uma
            Avaliacao e um Dinheiro diária, além de uma tag própria e a tag do objeto Destino associado.
            @param const Codigo a ser armazenado.
            @param const Senha a ser armazenado.
            @param const Codigo a ser armazenado como tag.
            @param const Codigo a ser armazenado como tag do objeto Destino associado.
            @sa Hospedagem()
        */
        Hospedagem(const Codigo&, const Nome&, const Avaliacao&, const Dinheiro&, const Codigo&, const Codigo&);

        //! Hospedagem::setValor(const Codigo&)
        /*!
            Recebe um Codigo e armazena no objeto Hospedagem.
            @param const Codigo.
        */
        void setValor(const Codigo&);

        //! std::string Hospedagem::getCodigo() const
        /*!
            Retorna o Codigo armazenado no objeto Hospedagem.
            @return string valor do objeto Codigo.
        */
        inline std::string getValorCodigo() const {return this->codigo.getValor();}

        //! Hospedagem::setValor(const Nome&)
        /*!
            Recebe um Nome e armazena no objeto Hospedagem.
            @param const Nome.
        */
        void setValor(const Nome&);

        //! std::string Hospedagem::getNome() const
        /*!
            Retorna o Nome armazenado no objeto Hospedagem.
            @return string valor do objeto Nome.
        */
        inline std::string getValorNome() const {return this->nome.getValor();}

        //! Hospedagem::setValor(const Avaliacao&)
        /*!
            Recebe um Avaliacao e armazena no objeto Hospedagem.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! int Hospedagem::getAvaliacao() const
        /*!
            Retorna o Avaliacao armazenado no objeto Hospedagem.
            @return int valor do objeto Avaliacao.
        */
        inline int getValorAvaliacao() const {return this->avaliacao.getValor();}

        //! Hospedagem::setValor(const Dinheiro&)
        /*!
            Recebe um Dinheiro e armazena no objeto Hospedagem como diária.
            @param const Dinheiro.
        */
        void setValor(const Dinheiro&);

        //! int Hospedagem::getDiaria() const
        /*!
            Retorna o Dinheiro (diária) da Hospedagem.
            @return int valor do objeto Dinheiro.
        */
        inline int getValorDiaria() const {return this->diaria.getValor();}

        //! inline std::string Hospedagem::getValorPreco() const
        /*!
            Retorna o valor formatado da diária da hospedagem.
            @return objeto Dinheiro armazenado no objeto Hospedagem.
        */
        inline std::string getValorDiariaFormatado() const { return this->diaria.getValorFormatado(); }


        //! inline Hospedagem::getTag()
        /* Retorna a tag do objeto Hospedagem. */
        inline Codigo getTag()        const { return this->tag; }
        
        //! inline Hospedagem::getTagDestino()
        /* Retorna a tag do Destino relacionado ao objeto Hospedagem. */
        inline Codigo getTagDestino() const { return this->tagDestino; }

        //! inline Hospedagem::setTag(Codigo&)
        /* Recebe Codigo& e armazena como nova tag. */
        void setTag(Codigo&);

        //! inline Hospedagem::setTagDestino(Codigo&)
        /* Recebe Codigo& e armazena como nova tag do Destino relacionado. */
        void setTagDestino(Codigo&);
};

#endif // HOSPEDAGEM_HPP_INCLUDED
