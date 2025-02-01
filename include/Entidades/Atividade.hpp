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

        //! Tag da atividade
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) da atividade. */
        Codigo tag;
        //! Tag do destino relacionado à atividade
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) do destino relacionado à atividade. */
        Codigo tagDestino;


        //! Código da atividade
        /*! Atributo Codigo referente ao código da Atividade. */
        Codigo codigo;

        //! Nome da atividade
        /*! Atributo Nome referente ao nome da Atividade. */
        Nome nome;

        //! Data da atividade
        /*! Atributo Data referente à data da Atividade. */
        Data data;

        //! Horário da atividade
        /*! Atributo Horario referente ao horário da Atividade. */
        Horario horario;

        //! Duração da atividade
        /*! Atributo referente á Duração da Atividade. */
        Duracao duracao;

        //! Custo da atividade
        /*! Atributo Dinheiro referente ao custo da Atividade. */
        Dinheiro preco;

        //! Avaliação da atividade
        /*! Atributo Avaliacao referente à avaliação da Atividade. */
        Avaliacao avaliacao;

    public:

        //! Construtor vazio
        /*! Constrói um objeto Atividade com todos seus parâmetros vazios.
            @sa Atividade(const Codigo&, const Nome&, const Data&, const Horario&, const Duracao&, const Dinheiro&, const Avaliacao&) */
        Atividade();

        //! Construtor paramétrico
        /*! Constrói um objeto Atividade, recebendo cada um de seus parâmetros, além de uma tag própria e a tag do objeto Destino associado.
            @param const Codigo&.
            @param const Nome&.
            @param const Data&.
            @param const Horario&.
            @param const Duracao&.
            @param const Dinheiro&.
            @param const Avaliacao&.
            @param const Codigo& a ser armazenado como tag.
            @param const Codigo& a ser armazenado como tag do objeto Destino associado.
            @sa Atividade()
        */
        Atividade(const Codigo&, const Nome&, const Data&, const Horario&, const Duracao&, const Dinheiro&, const Avaliacao&, const Codigo&, const Codigo&);

        //! Atividade::setValor(const Codigo&)
        /*!
            Recebe um Codigo e armazena no objeto Atividade.
            @param const Codigo.
        */
        void setValor(const Codigo &);

        //! Atividade::setValor(const Nome&)
        /*!
            Recebe um Nome e armazena no objeto Atividade.
            @param const Nome.
        */
        void setValor(const Nome &);

        //! Atividade::setValor(const Data&)
        /*!
            Recebe um Data e armazena no objeto Atividade.
            @param const Data.
        */
        void setValor(const Data &);

        //! Atividade::setValor(const Horario&)
        /*!
            Recebe um Horario e armazena no objeto Atividade.
            @param const Horario.
        */
        void setValor(const Horario &);

        //! Atividade::setValor(const Duracao&)
        /*!
            Recebe um Duracao e armazena no objeto Atividade.
            @param const Duracao.
        */
        void setValor(const Duracao &);

        //! Atividade::setValor(const Dinheiro&)
        /*!
            Recebe um Dinheiro e armazena no objeto Atividade.
            @param const Dinheiro.
        */
        void setValor(const Dinheiro &);

        //! Atividade::setValor(const Avaliacao&)
        /*!
            Recebe um Avaliacao e armazena no objeto Atividade.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao &);

        //! inline std::string Atividade::getValorCodigo() const
        /*!
            Retorna o Codigo da atividade.
            @return Codigo armazenado no Atividade.
        */
        inline std::string getValorCodigo() const { return this->codigo.getValor(); }

        //! inline std::string Atividade::getValorNome() const
        /*!
            Retorna o Nome da atividade.
            @return Nome armazenado no Atividade.
        */
        inline std::string getValorNome() const { return this->nome.getValor(); }

        //! inline std::string Atividade::getValorData() const
        /*!
            Retorna o Data da atividade.
            @return Data armazenado no Atividade.
        */
        inline std::string getValorData() const { return this->data.getValor(); }

        //! inline std::string Atividade::getValorHorario() const
        /*!
            Retorna o Horario da atividade.
            @return Horario armazenado no Atividade.
        */
        inline std::string getValorHorario() const { return this->horario.getValor(); }

        //! inline int Atividade::getValorDuracao() const
        /*!
            Retorna o Duracao da atividade.
            @return Duracao armazenado no Atividade.
        */
        inline int getValorDuracao() const { return this->duracao.getValor(); }

        //! inline int Atividade::getValorPreco() const
        /*!
            Retorna o Dinheiro com o preço da atividade.
            @return Dinheiro armazenado no Atividade.
        */
        inline int getValorPreco() const { return this->preco.getValor(); }

        //! inline std::string Atividade::getValorPreco() const
        /*!
            Retorna o Dinheiro com o preço da atividade formatado.
            @return Dinheiro armazenado no Atividade.
        */
        inline std::string getValorPrecoFormatado() const { return this->preco.getValorFormatado(); }

        //! inline int getValorAvaliacao() const
        /*!
            Retorna o Avaliacao da atividade.
            @return Avaliacao armazenado no Atividade.
        */
        inline int getValorAvaliacao() const { return this->avaliacao.getValor(); }


        //! inline Atividade::getTag()
        /* Retorna a tag do objeto Atividade. */
        inline Codigo getTag()        const { return this->tag; }

        //! inline Atividade::getTagDestino()
        /* Retorna a tag do Destino relacionado ao objeto Atividade. */
        inline Codigo getTagDestino() const { return this->tagDestino; }

        //! void Atividade::setTag(Codigo&)
        /* Recebe Codigo& e armazena como nova tag. */
        void setTag(Codigo&);

        //! void Atividade::setTagDestino(Codigo&)
        /* Recebe Codigo& e armazena como nova tag do Destino relacionado. */
        void setTagDestino(Codigo&);
};

#endif // ATIVIDADE_HPP_INCLUDED
