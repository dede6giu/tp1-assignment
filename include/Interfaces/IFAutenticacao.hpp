#ifndef IFAUTENTICACAO_HPP_INCLUDED
#define IFAUTENTICACAO_HPP_INCLUDED

//! Interface Front Autenticação
/*!
    232013031 - Implementação \n

    A IFA é responsável pela autenticação do usuário no sistema do software.
*/

class IFAutenticacao
{
    public:

        //! Autentica o usuário
        /*!
            O método recebe do usuário um código e uma senha.
            Ele checa se a senha é a associada ao código fornecido e, se sim, retorna true.
            Se o código não existe, ou a senha está incorreta, retorna false.
            @param código da conta
            @param senha da conta
            @return sucesso da operação
        */
        virtual bool autenticar(Codigo, Senha) = 0;
};


#endif // IFAUTENTICACAO_HPP_INCLUDED
