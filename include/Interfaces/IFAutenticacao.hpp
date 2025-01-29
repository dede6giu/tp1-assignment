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
            Inicia a autenticação. Dentro da função, requisita ao usuário um Codigo
            e uma Senha, verifica se estão corretamente formatados, e, então, envia
            essas informações para autenticação no banco de dados. Retorna true se
            a autenticação foi bem sucedida, e o parâmetro possuirá as informações
            da Conta autenticada. Senão, retorna false, e o parâmetro deve ser nulo.
            @param (OUT) Conta autenticada. Deve entrar como um objeto Conta.
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
