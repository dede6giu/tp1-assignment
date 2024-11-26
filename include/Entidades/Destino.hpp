#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Avaliacao.hpp"


//! Entidade Destino
/*!
    Entidade Destino \n
    232013031 - implementa��o \n
    232002520 - documenta��o
*/

class Destino
{
    private:
        //! Codigo (atributo)
        /*! Atributo que armazena o objeto Codigo do Destino.*/
        Codigo codigo;

        //! Nome (atributo)
        /*! Atributo que armazena o objeto Nome do Destino. */
        Nome nome;

        //! Data (atributo)
        /*! Atributo que armazena o objeto Data de in�cio do Destino */
        Data inicio;

        //! Data (atributo)
        /*! Atributo que armazena o objeto Data de fim do Destino. */
        Data fim;

        //! Avaliacao (atributo)
        /*! Atributo que armazena o objeto Avaliacao do Destino. */
        Avaliacao avaliacao;

        //! bool Destino::validar()
        /*! */
        bool validar(); //!< n�o ainda implementado

    public:
        //! Construtor vazio
        /*! Constr�i um objeto Destino vazio. */
        Destino();


        //! void Destino::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena-o como atributo do objeto.
            @param const Codigo&
        */
        void setValor(const Codigo&);

        //! inline Codigo Destino::getValorCodigo()
        /*!
            Retorna o objeto Codigo armazenado no objeto.
            @return objeto Codigo.
        */
        inline Codigo getValorCodigo() const;


        //! void Destino::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena-o como atributo do objeto.
            @param const Nome& a ser armazenado.
        */
        void setValor(const Nome&);

        //! inline Nome Destino::getValorNome()
        /*!
            Retorna o objeto Nome armazenado no objeto.
            @return objeto Nome.
        */
        inline Nome getValorNome() const;


        //! void Destino::setValor(const Avaliacao&)
        /*!
            Recebe um objeto Avaliacao e armazena-o como atributo do objeto.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! inline Avaliacao Destino::getValorAvaliacao()
        /*!
            Retorna o objeto Avaliacao armazenado no objeto.
            @return objeto Avaliacao.
        */
        inline Avaliacao getValorAvaliacao() const;


        //! void Destino::setValor(const Data&, bool)
        /*!
            Recebe um objeto Data e um bool e armazena-os como atributos do objeto.
            @param const Data& a ser armazenado.
            @param bool (se vale 0, � a data de in�cio; se vale 1, � a data de fim).
        */
        void setValor(const Data&, bool);

        //! inline Data Destino::getValorInicio()
        /*!
            Retorna o objeto Data de in�cio armazenado no objeto.
            @return objeto Data.
        */
        inline Data getValorInicio() const;

        //! inline Data Destino::getValorFim()
        /*!
            Retorna o objeto Data de fim armazenado no objeto.
            @return objeto Data.
        */
        inline Data getValorFim() const;
};

inline Codigo Destino::getValorCodigo() const {
    return this->codigo;
}

inline Nome Destino::getValorNome() const {
    return this->nome;
}

inline Avaliacao Destino::getValorAvaliacao() const {
    return this->avaliacao;
}

inline Data Destino::getValorInicio() const {
    return this->inicio;
}

inline Data Destino::getValorFim() const {
    return this->fim;
}


#endif // DESTINO_HPP_INCLUDED
