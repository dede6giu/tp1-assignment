#ifndef IBCONTA_HPP_INCLUDED
#define IBCONTA_HPP_INCLUDED

#include "../Entidades/Conta.hpp"
#include "../Interfaces/IBAtividade.hpp"
#include "../Interfaces/IBDestino.hpp"
#include "../Interfaces/IBHospedagem.hpp"
#include "../Interfaces/IBViagem.hpp"

//! Interface Back Conta
/*!
    232013031 - Implementação e Documentação \n

    A IBConta é responsável pela comunicação do usuário com
    o banco de dados. Ela permite criar, excluir, verificar a
    existência e atualizar uma Conta
*/

class IBConta
{
    public:

        //! Cria uma Conta
        /*!
            Processa as informações recebidas e verifica se é possível
            criar uma nova Conta.
            Se as informações foram incorretamente formatadas, ou o
            código fornecido já existe, a operação falha. Senão, ocorre
            sucesso e uma Conta é criada.
            @param Conta a ser criada.
            @return Sucesso da operação.
        */
        virtual bool criar(Conta) = 0;

        //! Exclui uma Conta
        /*!
            Recebe um Codigo. Se a Conta do Codigo existe, ocorre a exclusão.
            Senão, a operação falha.
            @param Codigo da Conta a ser excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Codigo) = 0;

        //! Lê uma Conta
        /*!
            Recebe um Codigo e verifica se uma conta com tal Codigo
            existe no banco de dados.
            @param Codigo a ser verificado.
            @return Existência da Conta.
        */
        virtual bool ler(Codigo) = 0;

        //! Atualiza a Senha de uma Conta
        /*!
            Recebe uma Conta e uma Senha. Após verificar a existência da
            Conta (e se a Senha fornecida com ela está correta), altera-se
            o valor da Senha para o novo valor fornecido. Senão, a operação
            falha.
            @param Conta que trocará de Senha.
            @param Nova Senha.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Conta, Senha) = 0;

        //! Dependência da IBViagem
        /*!
            Estabelece uma referência para a IBViagem como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IBViagem.
            @param Referência à IBViagem a ser salva.
        */
        virtual void setCntrIBViagem(IBViagem*) = 0;

        //! Destrutor Virtual
        virtual ~IBConta(){};
};

#endif // IBCONTA_HPP_INCLUDED
