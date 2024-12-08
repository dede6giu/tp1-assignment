#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include "../../include/Dominios/Data.hpp"
#include "../../include/Dominios/Avaliacao.hpp"


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

    public:
        //! Construtor vazio
        /*! Constr�i um objeto Destino vazio. */
        Destino();

        Destino(const Codigo&, const Nome&, const Data&, const Data&, const Avaliacao&);

        //! void Destino::setValor(const Codigo&)
        /*!
            Recebe um objeto Codigo e armazena-o como atributo do objeto.
            @param const Codigo&
        */
        void setValor(const Codigo&);

        //! inline Codigo Destino::getValorCodigo()
        /*!
            Retorna o objeto Codigo armazenado no objeto.
            @return string valor do Codigo.
        */
        inline std::string getValorCodigo() const;


        //! void Destino::setValor(const Nome&)
        /*!
            Recebe um objeto Nome e armazena-o como atributo do objeto.
            @param const Nome& a ser armazenado.
        */
        void setValor(const Nome&);

        //! inline Nome Destino::getValorNome()
        /*!
            Retorna o objeto Nome armazenado no objeto.
            @return string valor do Nome.
        */
        inline std::string getValorNome() const;


        //! void Destino::setValor(const Avaliacao&)
        /*!
            Recebe um objeto Avaliacao e armazena-o como atributo do objeto.
            @param const Avaliacao.
        */
        void setValor(const Avaliacao&);

        //! inline Avaliacao Destino::getValorAvaliacao()
        /*!
            Retorna o objeto Avaliacao armazenado no objeto.
            @return int valor do Avaliacao.
        */
        inline int getValorAvaliacao() const;


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
            @return string valor do parâmetro inicio (Data).
        */
        inline std::string getValorInicio() const;

        //! inline Data Destino::getValorFim()
        /*!
            Retorna o objeto Data de fim armazenado no objeto.
            @return string valor do parâmetro fim (Data).
        */
        inline std::string getValorFim() const;
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
