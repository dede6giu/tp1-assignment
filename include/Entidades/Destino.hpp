#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include "../../include/Dominios/Data.hpp"
#include "../../include/Dominios/Avaliacao.hpp"



//! Entidade Destino
/*!
    Entidade Destino \n
    232013031 - implementação \n
    232002520 - documentação \n
    232002771 - documentação
*/

class Destino
{
    private:

        //! Tag do destino
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) do destino. */
        Codigo tag;
        //! Tag da viagem relacionada ao destino
        /*! Atributo Codigo que armazena a tag (no contexto do bando de dados) da viagem relacionada ao destino. */
        Codigo tagViagem;


        //! Código do destino
        /*! Atributo Codigo que armazena o código do destino.*/
        Codigo codigo;

        //! Nome do destino
        /*! Atributo Nomeque armazena o nome do destino. */
        Nome nome;

        //! Data de início do destino
        /*! Atributo Data que armazena a data de início do destino */
        Data inicio;

        //! Data de fim do destino
        /*! Atributo Data que armazena a data de fim do destino. */
        Data fim;

        //! Avaliação do destino
        /*! Atributo Avaliacao que armazena a avaliação do destino. */
        Avaliacao avaliacao;

    public:
        //! Construtor vazio
        /*! Constrói um objeto Destino vazio.
            @sa Destino(const Codigo&, const Nome&, const Data&, const Data&, const Avaliacao&)
        */
        Destino();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Destino e pede como parâmetros: um Codigo, um Nome, uma Data de início, uma Data de fim e uma Avaliacao, além de uma tag própria e a tag do objeto Viagem associado.
            @param const Codigo a ser armazenado.
            @param const Nome a ser armazenado.
            @param const Data de inicio a ser armazenada.
            @param const Data de fim a ser armazenada.
            @param const Avaliacao a ser armazenado.
            @param const Codigo a ser armazenado como tag.
            @param const Codigo a ser armazenado como tag do objeto Viagem associado.
            @sa Destino()
        */
        Destino(const Codigo&, const Nome&, const Data&, const Data&, const Avaliacao&, const Codigo&, const Codigo&);

        //! void Destino::setValor(const Codigo&)
        /*!
            Recebe um Codigo e armazena-o como atributo do Destino.
            @param const Codigo&
        */
        void setValor(const Codigo&);

        //! inline Codigo Destino::getValorCodigo()
        /*!
            Retorna o Codigo armazenado no objeto.
            @return string valor do Codigo.
        */
        inline std::string getValorCodigo() const;


        //! void Destino::setValor(const Nome&)
        /*!
            Recebe um Nome e armazena-o como atributo do Destino.
            @param const Nome& a ser armazenado.
        */
        void setValor(const Nome&);

        //! inline Nome Destino::getValorNome()
        /*!
            Retorna o Nome armazenado no objeto.
            @return string valor do Nome.
        */
        inline std::string getValorNome() const;


        //! void Destino::setValor(const Avaliacao&)
        /*!
            Recebe um Avaliacao e armazena-o como atributo do Destino.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! inline Avaliacao Destino::getValorAvaliacao()
        /*!
            Retorna o Avaliacao armazenado no objeto.
            @return int valor do Avaliacao.
        */
        inline int getValorAvaliacao() const;


        //! void Destino::setValor(const Data&, bool)
        /*!
            Recebe um Data e um bool e armazena-os como atributos do Destino.
            @param const Data& a ser armazenado.
            @param bool (se vale 0, é a data de início; se vale 1, é a data de fim).
        */
        void setValor(const Data&, bool);

        //! inline Data Destino::getValorInicio()
        /*!
            Retorna o Data de início armazenado no Destino.
            @return string valor do parâmetro início (Data).
        */
        inline std::string getValorInicio() const;

        //! inline Data Destino::getValorFim()
        /*!
            Retorna o Data de fim armazenado no objeto.
            @return string valor do parâmetro fim (Data).
        */
        inline std::string getValorFim() const;


        //! inline Codigo::getTag()
        /* Retorna a tag do objeto Destino. */
        inline Codigo getTag()       const { return this->tag; }
        
        //! inline Codigo::getTagViagem()
        /* Retorna a tag do Viagem relacionado ao objeto Destino. */
        inline Codigo getTagViagem() const { return this->tagViagem; }

        //! void Codigo::setTag(Codigo&)
        /* Recebe Codigo& e armazena como nova tag. */
        void setTag(Codigo&);
        //! void Codigo::setTagViagem(Codigo&)
        /* Recebe Codigo& e armazena como nova tag da Viagem relacionada. */
        void setTagViagem(Codigo&);
};

inline std::string Destino::getValorCodigo() const {
    return this->codigo.getValor();
}

inline std::string Destino::getValorNome() const {
    return this->nome.getValor();
}

inline int Destino::getValorAvaliacao() const {
    return this->avaliacao.getValor();
}

inline std::string Destino::getValorInicio() const {
    return this->inicio.getValor();
}

inline std::string Destino::getValorFim() const {
    return this->fim.getValor();
}


#endif // DESTINO_HPP_INCLUDED
