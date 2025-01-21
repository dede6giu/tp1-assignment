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
            Indica o início do processamento de autenticação. Ou seja, dentro da função,
            receberá um Código e uma Senha, verifica se estão corretamente formatados, e
            então envia essas informações para autenticação no banco de dados.
            @param Recebe um ponteiro nulo que receberá a Conta caso seja
            autenticada. Senão, continua nulo.
            @return Sucesso da operação.
        */
        virtual bool autenticar(Conta*) = 0;
};

#endif // IFAUTENTICACAO_HPP_INCLUDED
