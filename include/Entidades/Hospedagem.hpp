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

        Codigo tag;
        Codigo tagDestino;

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
        /*! Constrói um objeto Hospedagem vazio.
            @sa Hospedagem(const Codigo&, const Nome&, const Avaliacao&, const Dinheiro&)
        */
        Hospedagem();

        //! Construtor paramétrico.
        /*!
            Constrói um objeto Hospedagem e pede 2 parâmetros: um Codigo, um Nome, uma Avaliacao e um Dinheiro diária, além de uma tag própria e a tag do objeto Destino associado.
            @param const Codigo a ser armazenado.
            @param const Senha a ser armazenado.
            @param const Codigo a ser armazenado como tag.
            @param const Codigo a ser armazenado como tag do objeto Destino associado.
            @sa Hospedagem()
        */
        Hospedagem(const Codigo&, const Nome&, const Avaliacao&, const Dinheiro&, const Codigo&, const Codigo&);

        //! Hospedagem::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena no objeto Hospedagem.
            @param const Codigo.
        */
        void setValor(const Codigo&);

        //! std::string Hospedagem::getCodigo() const
        /*!
            Retorna o objeto Codigo armazenado no objeto Hospedagem.
            @return string valor do objeto Codigo.
        */
        inline std::string getValorCodigo() const {return this->codigo.getValor();}

        //! Hospedagem::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena no objeto Hospedagem.
            @param const Nome.
        */
        void setValor(const Nome&);

        //! std::string Hospedagem::getNome() const
        /*!
            Retorna o objeto Nome armazenado no objeto Hospedagem.
            @return string valor do objeto Nome.
        */
        inline std::string getValorNome() const {return this->nome.getValor();}

        //! Hospedagem::setValor(const Avaliacao&)
        /*!
            Recebe um objeto Avaliacao e armazena no objeto Hospedagem.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! int Hospedagem::getAvaliacao() const
        /*!
            Retorna o objeto Avaliacao armazenado no objeto Hospedagem.
            @return int valor do objeto Avaliacao.
        */
        inline int getValorAvaliacao() const {return this->avaliacao.getValor();}

        //! Hospedagem::setValor(const Dinheiro&)
        /*!
            Recebe um objeto Dinheiro e armazena no objeto Hospedagem como diária.
            @param const Dinheiro.
        */
        void setValor(const Dinheiro&);

        //! int Hospedagem::getDiaria() const
        /*!
            Retorna o objeto Dinheiro (diária) da Hospedagem.
            @return int valor do objeto Dinheiro.
        */
        inline int getValorDiaria() const {return this->diaria.getValor();}

        //! inline std::string Hospedagem::getValorPreco() const
        /*!
            Retorna o objeto Dinheiro com o preço da hospedagem formatado.
            @return objeto Dinheiro armazenado no objeto Hospedagem.
        */
        inline std::string getValorDiariaFormatado() const { return this->diaria.getValorFormatado(); }

        inline Codigo getTag()        const { return this->tag; }
        inline Codigo getTagDestino() const { return this->tagDestino; }

        void setTag(Codigo&);
        void setTagDestino(Codigo&);
};

#endif // HOSPEDAGEM_HPP_INCLUDED
