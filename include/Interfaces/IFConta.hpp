#ifndef IFCONTA_HPP_INCLUDED
#define IFCONTA_HPP_INCLUDED

#include "../Entidades/Conta.hpp"
#include "IBConta.hpp"

//! Interface Front Conta
/*!
    232013031 - implementação \n

    A IFConta é responsável pela chamada do método que inicia a criação de Conta.
*/

class IFConta
{
    public:

        //! Cria uma conta
        /*!
            Move um usuário não-autenticado para a tela de criação de Conta.
            Após o término do processo, retorna o usuário à tela principal.
            @return Sucesso da operação.
        */
        virtual bool criar() = 0;

        //! Visualiza um Perfil
        /*!
            Inicia a tela que permite o usuário, já autenticado, a alterar
            sua Senha, ver seu Código e Senha atuais e excluir sua Conta.
            @param Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IBConta
        /*!
            Estabelece uma referência para a IBConta como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IFConta.
            @param Referência à IBConta a ser salva.
        */
        virtual void setCntrIBConta(IBConta*) = 0;

        //! Destrutor Virtual
        virtual ~IFConta(){};
};

#endif // IFCONTA_HPP_INCLUDED
