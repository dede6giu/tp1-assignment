#ifndef IFCONTA_HPP_INCLUDED
#define IFCONTA_HPP_INCLUDED

#include "../Entidades/Conta.hpp"
#include "IBConta.hpp"

//! Interface Front Conta
/*!
    232013031 - Implementação \n

    A IFC é responsável pela chamada do método que inicia
    a criação de Conta.
*/

class IFConta
{
    public:

        //! Cria uma conta
        /*!
            Move o usuário para a tela de criação de Conta.
            Após o término do processo, retorna o usuário à tela principal,
            onde tal decidirá entre criar outra Conta ou autenticar.
            @return Sucesso da operação.
        */
        virtual bool criar() = 0;

        //! Dependência da IBC
        /*!
            Estabelece uma referência para a IBConta como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IFConta.
            @param Referência à IBAutenticacao a ser salva.
        */
        virtual void setCntrIBConta(IBConta*) = 0;

        //! Destrutor Virtual
        virtual ~IFConta(){};
};

#endif // IFCONTA_HPP_INCLUDED
