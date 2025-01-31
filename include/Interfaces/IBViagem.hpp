#ifndef IBVIAGEM_HPP_INCLUDED
#define IBVIAGEM_HPP_INCLUDED

#include "../Entidades/Viagem.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "../Dominios/Nome.hpp"
#include "../Interfaces/IBDestino.hpp"
#include <vector>

//! Interface Back Viagem
/*!
    232002520 - implementação \n

    A IBViagem é responsável pela comunicação entre o usuário e o
    banco de dados quanto ao controle de Viagem. Ela permite criar,
    excluir, ler e atualizar Viagem.
*/

class IBViagem {
    public:

        //! Cria uma Viagem
        /*!
            Recebe os detalhes de uma nova Viagem e adiciona ao banco de dados.
            Verifica se a Viagem é única antes de realizar a operação.
            @param Viagem a ser criada.
            @return Sucesso da operação.
        */
        virtual bool criar(Viagem) = 0;

        //! Cria uma Tabela
        /*!
            Recebe um Codigo e adiciona uma nova tabela com tal Codigo ao banco
            de dados, se não já existir a tabela.
            @param Codigo da Conta.
        */
        virtual void criar(Codigo) = 0;

        //! Exclui uma Viagem
        /*!
            Recebe uma Viagem e realiza uma confirmação antes da exclusão. Se a
            Viagem existe, ela é removida do banco de dados. Caso contrário,
            a operação falha.
            @param Viagem a ser excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Viagem) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. Método só deve
            ser usado durante a exclusão de Conta.
            @param Codigo da Conta excluída.
            @return Sucesso da operação.
        */
        virtual void excluir(Codigo) = 0;

        //! Lê uma Viagem
        /*!
            Verifica a existência de uma Viagem no banco de dados.
            @param Viagem a verificar.
            @return Existência da Viagem.
        */
        virtual bool ler(Viagem) = 0;

        //! Lê todos Viagem
        /*!
            Recebe o Codigo da Conta e retorna um vetor com todos Viagem associados.
            @param Codigo da Conta.
            @return Retorna um vetor de Viagem com todos os Viagem cadastrados com
            o Codigo informado.
        */
        virtual std::vector<Viagem> ler(Codigo) = 0;

        //! Atualiza o Nome de uma Viagem
        /*!
            Atualiza o nome de uma Viagem.
            @param Viagem a ser atualizada.
            @param Novo Nome a ser atribuído à Viagem.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Viagem, Nome) = 0;

        //! Atualiza o Avaliacao de uma Viagem
        /*!
            Atualiza a avaliação de uma Viagem.
            @param Viagem a ser atualizada.
            @param Novo Avaliacao a ser atribuído à Viagem.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Viagem, Avaliacao) = 0;

        //! Dependência da IBDestino
        /*!
            Estabelece uma referência para a IBDestino como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IBDestino.
            @param Referência à IBDestino a ser salva.
        */
        virtual void setCntrIBDestino(IBDestino*) = 0;

        //! Destrutor virtual
        virtual ~IBViagem(){};
};

#endif // IBVIAGEM_HPP_INCLUDED
