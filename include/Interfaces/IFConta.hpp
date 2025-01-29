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
            Deve-se requisitar do usuário um Codigo e uma Senha (válidos).
            Com esses valores cria-se uma Conta e envia-se as informações para
            o backend. Se a conta for criada com sucesso, a função deve retornar
            true, senão, false.
            @return Sucesso da operação.
        */
        virtual bool criar() = 0;

        //! Visualiza um Perfil
        /*!
            Inicia a tela que permite o usuário, já autenticado, a alterar
            sua Senha, ver seu Código atual e excluir sua Conta. \n
            Não é necessário realizar nenhuma operação para ver o Código atual.
            Ele é visível como título do painel. \n
            Ao requisitar a mudança de Senha, o usuário deve fornecer a Senha atual.
            O sistema checa se a Senha fornecida é a mesma da Conta atualmente
            autenticada, e então transmite as informações de mudança ao backend. \n
            Ao requisitar a exclusão da Conta, o usuário deve fornecer a Senha atual.
            O sistema checa se a Senha fornecida é a mesma da Conta atualmente
            autenticada, depois requisita uma confirmação antes de enviar as
            informações de exclusão para o backend.
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
