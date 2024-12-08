#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include <string>
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include "../../include/Dominios/Data.hpp"
#include "../../include/Dominios/Horario.hpp"
#include "../../include/Dominios/Duracao.hpp"
#include "../../include/Dominios/Dinheiro.hpp"
#include "../../include/Dominios/Avaliacao.hpp"

//! Entidade Atividade
/*!
    232029274 - implementação \n
    232002520 - documentação
*/

class Atividade {
    private:

        //! Codigo (atributo)
        /*! Atributo da classe Codigo. */
        Codigo codigo;

        //! Nome (atributo)
        /*! Atributo da classe Nome. */
        Nome nome;

        //! Data (atributo)
        /*! Atributo da classe Data. */
        Data data;

        //! Horario (atributo)
        /*! Atributo da classe Horario. */
        Horario horario;

        //! Duracao (atributo)
        /*! Atributo da classe Duracao. */
        Duracao duracao;

        //! Dinheiro (atributo)
        /*! Atributo da classe Dinheiro. */
        Dinheiro preco;

        //! Avaliacao (atributo)
        /*! Atributo da classe Avaliacao. */
        Avaliacao avaliacao;

    public:

        //! Construtor vazio
        /*! Constrói um objeto Atividade vazio. */
        Atividade();

        Atividade(const Codigo&, const Nome&, const Data&, const Horario&, const Duracao&, const Dinheiro&, const Avaliacao&);

        //! Atividade::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena no objeto Atividade.
            @param const Codigo.
        */
        void setValor(const Codigo &);

        //! Atividade::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena no objeto Atividade.
            @param const Nome.
        */
        void setValor(const Nome &);

        //! Atividade::setValor(const Data&)
        /*!
            Recebe um objeto Data e armazena no objeto Atividade.
            @param const Data.
        */
        void setValor(const Data &);

        //! Atividade::setValor(const Horario&)
        /*!
            Recebe um objeto Horario e armazena no objeto Atividade.
            @param const Horario.
        */
        void setValor(const Horario &);

        //! Atividade::setValor(const Duracao&)
        /*!
            Recebe um objeto Duracao e armazena no objeto Atividade.
            @param const Duracao.
        */
        void setValor(const Duracao &);

        //! Atividade::setValor(const Dinheiro&)
        /*!
            Recebe um objeto Dinheiro e armazena no objeto Atividade.
            @param const Dinheiro.
        */
        void setValor(const Dinheiro &);

        //! Atividade::setValor(const Avaliacao&)
        /*!
            Recebe um objeto Avaliacao e armazena no objeto Atividade.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao &);

        //! inline Codigo Atividade::getCodigo() const
        /*!
            Retorna o objeto Codigo da atividade.
            @return objeto Codigo armazenado no objeto Atividade.
        */
        inline Codigo Atividade::getCodigo() const { return this->codigo; }

        //! inline Nome Atividade::getNome() const
        /*!
            Retorna o objeto Nome da atividade.
            @return objeto nome armazenado no objeto Atividade.
        */
        inline Nome Atividade::getNome() const { return this->nome; }

        //! inline Data Atividade::getData() const
        /*!
            Retorna o objeto Data da atividade.
            @return objeto Data armazenado no objeto Atividade.
        */
        inline Data Atividade::getData() const { return this->data; }

        //! inline Horario Atividade::getHorario() const
        /*!
            Retorna o objeto Horario da atividade.
            @return objeto Horario armazenado no objeto Atividade.
        */
        inline Horario Atividade::getHorario() const { return this->horario; }

        //! inline Duracao Atividade::getDuracao() const
        /*!
            Retorna o objeto Duracao da atividade.
            @return objeto Duracao armazenado no objeto Atividade.
        */
        inline Duracao Atividade::getDuracao() const { return this->duracao; }

        //! inline Dinheiro Atividade::getPreco() const
        /*!
            Retorna o objeto Dinheiro com o preço da atividade.
            @return objeto Dinheiro armazenado no objeto Atividade.
        */
        inline Dinheiro Atividade::getPreco() const { return this->preco; }

        //! inline Avaliacao Atividade::getAvaliacao() const
        /*!
            Retorna o objeto Avaliacao da atividade.
            @return objeto Avaliacao armazenado no objeto Atividade.
        */
        inline Avaliacao Atividade::getAvaliacao() const { return this->avaliacao; }

        std::string getAtividade() const;
};

#endif // ATIVIDADE_HPP
