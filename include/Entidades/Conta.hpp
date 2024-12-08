#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Senha.hpp"

//! Entidade Conta
/*!
    232002771 - implementação da entidade conta \n
    232002520 - documentação
*/

class Conta
{
    private:
        //! Codigo (atributo) 
        /*! Atributo que armazena o codigo da conta. */
        Codigo codigo;

        //! Senha (atributo)
        /*! Atributo que armazena a senha da conta. */
        Senha senha;

    public:
        //! Construtor vazio
        /*! Constrói um objeto Conta vazio. */
        Conta();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Conta e pede 2 parâmetros: Codigo e Conta.
            @param const Codigo a ser armazenado.
            @param const Senha a ser armazenado.
        */
        Conta(const Codigo&, const Senha&);


        //! bool Conta::setValor(const Codigo&)
        /*!
            Método que recebe um objeto Codigo e armazena-o como atributo do objeto.
            @param const Codigo& a ser armazenado.
        */
        bool setValor(const Codigo&);

        //! Codigo Conta::getCodigo()
        /*!
            Retorna o atributo Codigo armazenado no objeto.
            @return objeto Codigo.
        */
        Codigo getCodigo() const;


        //! bool Conta::setValor(const Senha&)
        /*!
            Método que recebe um objeto Senha e armazena-o como atributo do objeto.
            @param const Senha&
        */
        bool setValor(const Senha&);

        //! Senha Conta::getSenha()
        /*!
            Retorna o atributo Senha armazenado no objeto.
            @return objeto Senha.
        */
        Senha getSenha() const;

};


inline Codigo Conta::getCodigo() const
{
    return this->codigo;
}

inline Senha Conta::getSenha() const
{
    return this->senha;
}

#endif // CONTA_HPP_INCLUDED


