#ifndef IFAUTENTICACAO_HPP_INCLUDED
#define IFAUTENTICACAO_HPP_INCLUDED

#include "../Entidades/Conta.hpp"
#include "IBAutenticacao.hpp"

//! Interface Front Autenticação
/*!
    232013031 - Implementação \n

    A IFAutenticacao é responsável pela autenticação do usuário no sistema do software.
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
        virtual bool run(Conta*) = 0;

        //! Dependência da IBAutenticacao
        /*!
            Estabelece uma referência para a IBAutenticacao como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IFAutenticacao.
            @param Referência à IBAutenticacao a ser salva.
        */
        virtual void setCntrIBAutenticacao(IBAutenticacao*) = 0;

        //! Destrutor Virtual
        virtual ~IFAutenticacao(){};
};

#endif // IFAUTENTICACAO_HPP_INCLUDED
