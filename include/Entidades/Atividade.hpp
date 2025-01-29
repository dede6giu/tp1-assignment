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
    232002520 - documentação \n
    232002771 - documentação \n
    232013031 - documentação
*/

class Atividade {
    private:

        Codigo tag;

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
        /*! Constrói um objeto Atividade com todos seus parâmetros vazios.
            @sa Atividade(const Codigo&, const Nome&, const Data&, const Horario&, const Duracao&, const Dinheiro&, const Avaliacao&) */
        Atividade();

        //! Construtor paramétrico
        /*! Constrói um objeto Atividade, recebendo cada um de seus parâmetros.
            @sa Atividade() */
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

        //! inline std::string Atividade::getValorCodigo() const
        /*!
            Retorna o objeto Codigo da atividade.
            @return objeto Codigo armazenado no objeto Atividade.
        */
        inline std::string getValorCodigo() const { return this->codigo.getValor(); }

        //! inline std::string Atividade::getValorNome() const
        /*!
            Retorna o objeto Nome da atividade.
            @return objeto Nome armazenado no objeto Atividade.
        */
        inline std::string getValorNome() const { return this->nome.getValor(); }

        //! inline std::string Atividade::getValorData() const
        /*!
            Retorna o objeto Data da atividade.
            @return objeto Data armazenado no objeto Atividade.
        */
        inline std::string getValorData() const { return this->data.getValor(); }

        //! inline std::string Atividade::getValorHorario() const
        /*!
            Retorna o objeto Horario da atividade.
            @return objeto Horario armazenado no objeto Atividade.
        */
        inline std::string getValorHorario() const { return this->horario.getValor(); }

        //! inline int Atividade::getValorDuracao() const
        /*!
            Retorna o objeto Duracao da atividade.
            @return objeto Duracao armazenado no objeto Atividade.
        */
        inline int getValorDuracao() const { return this->duracao.getValor(); }

        //! inline int Atividade::getValorPreco() const
        /*!
            Retorna o objeto Dinheiro com o preço da atividade.
            @return objeto Dinheiro armazenado no objeto Atividade.
        */
        inline int getValorPreco() const { return this->preco.getValor(); }

        //! inline int getValorAvaliacao() const
        /*!
            Retorna o objeto Avaliacao da atividade.
            @return objeto Avaliacao armazenado no objeto Atividade.
        */
        inline int getValorAvaliacao() const { return this->avaliacao.getValor(); }

        inline Codigo getTag() const { return this->tag; }

        void setTag(Codigo);
};

#endif // ATIVIDADE_HPP_INCLUDED
