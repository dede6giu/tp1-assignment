#ifndef IBAUTENTICACAO_HPP_INCLUDED
#define IBAUTENTICACAO_HPP_INCLUDED

//! Interface Back Autenticação
/*!
    232013031 - Implementação \n

    A IBA é responsável pela autenticação do usuário no sistema do software.
    Ela se comunica com o banco de dados para checar se a Conta fornecida existe.
*/

class IBAutenticacao
{
    public:

        //! Autentica o usuário
        /*!
            O método recebe um Código e uma Senha, ou seja, uma Conta.
            Ele checa se a Senha é a associada ao Código fornecido no banco de
            dados e, se sim, retorna true. Se o código não existe, ou a senha
            está incorreta, retorna false.
            @param Conta a ser autenticada.
            @return Sucesso da operação.
        */
        virtual bool autenticar(Conta) = 0;
};

#endif // IBAUTENTICACAO_HPP_INCLUDED
