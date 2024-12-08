#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Senha.hpp"

//! Entidade Conta
/*!
    232002771 - implementação, documentação. \n
    232002520 - documentação. \n
    232013031 - documentação.
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

        //! Construtor vazio.
        /*! Constrói um objeto Conta vazio.
            @sa Conta(const Codigo&, const Senha&)
        */
        Conta();

        //! Construtor paramétrico.
        /*!
            Constrói um objeto Conta e pede 2 parâmetros: um Codigo e uma Senha.
            @param const Codigo a ser armazenado.
            @param const Senha a ser armazenado.
            @sa Conta()
        */
        Conta(const Codigo&, const Senha&);


        //! bool Conta::setValor(const Codigo&)
        /*!
            Método que recebe um objeto Codigo e armazena-o como atributo do objeto.
            @param Codigo a ser armazenado.
        */
        bool setValor(const Codigo&);

        //! Codigo Conta::getCodigo()
        /*!
            Retorna o atributo Codigo armazenado no objeto.
            @return string valor do parâmetro codigo.
        */
        std::string getValorCodigo() const;


        //! bool Conta::setValor(const Senha&)
        /*!
            Método que recebe um objeto Senha e armazena-o como atributo do objeto.
            @param Senha a ser armazenado.
        */
        bool setValor(const Senha&);

        //! Senha Conta::getSenha()
        /*!
            Retorna o atributo Senha armazenado no objeto.
            @return string valor do parâmetro senha.
        */
        std::string getValorSenha() const;
};


inline std::string Conta::getValorCodigo() const
{
    return this->codigo.getValor();
}

inline std::string Conta::getValorSenha() const
{
    return this->senha.getValor();
}

#endif // CONTA_HPP_INCLUDED


