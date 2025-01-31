#ifndef IBHOSPEDAGEM_HPP_INCLUDED
#define IBHOSPEDAGEM_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Hospedagem.hpp"

//! Interface Back Hospedagem
/*!
    232002771 - Implementação e Documentação \n

    A IBHospedagem é responsável pela comunicação do usuário com
    o banco de dados quanto ao controle de Hospedagem. Ela permite
    criar, excluir, ler e atualizar os dados de uma Hospedagem,
*/
class IBHospedagem
{
    public:

        //! Cria uma Hospedagem
        /*!
            Recebe os detalhes de uma nova Hospedagem e adiciona ao banco de dados.
            Verifica se a Hospedagem é única antes de realizar a operação.
            @param Hospedagem a ser criada.
            @return Sucesso da operação.
        */
        virtual bool criar(Hospedagem) = 0;

        //! Cria uma Tabela
        /*!
            Recebe um Codigo e adiciona uma nova tabela com tal Codigo ao banco
            de dados, se não já existir a tabela.
            @param Codigo da Conta.
        */
        virtual void criar(Codigo) = 0;

        //! Exclui uma Hospedagem
        /*!
            Recebe uma Hospedagem e realiza uma confirmação antes da exclusão. Se a
            Hospedagem existe, ela é removida do banco de dados. Caso
            contrário, a operação falha.
            @param Hospedagem a ser excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Hospedagem) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. Método só deve
            ser usado durante a exclusão de Conta.
            @param Codigo da Conta excluída.
        */
        virtual void excluir(Codigo) = 0;

        //! Exclui Hospedagens
        /*!
            Recebe dois Codigo. O primeiro é uma Conta, o segundo um Destino. Exclui
            da Conta associada todos os Hospedagem relacionados ao Destino.
            Método só deve ser acionado durante a exclusão de Destino.
            @param Codigo da Conta.
            @param Codigo do Destino excluído.
        */
        virtual void excluir(Codigo, Codigo) = 0;

        //! Lê uma Hospedagem
        /*!
            Verifica a existência de uma Hospedagem no banco de dados.
            @param Hospedagem a verificar.
            @return Existência da Hospedagem.
        */
        virtual bool ler(Hospedagem) = 0;

        //! Lê todos Hospedagem
        /*!
            Recebe dois Codigo. O primeiro é uma Conta, o segundo um Destino. Busca
            da Conta associada por todos Hospedagem relacionados ao Destino.
            @param Codigo da Conta.
            @param Codigo do Destino.
            @return Retorna um vetor de Hospedagem com todos os Hospedagem cadastrados
            com os Codigo informados.
        */
        virtual std::vector<Hospedagem> ler(Codigo, Codigo) = 0;

        //! Atualiza o Nome de uma Hospedagem
        /*!
            Atualiza o nome de uma Hospedagem.
            @param Hospedagem a ser atualizada.
            @param Novo Nome a ser atribuído à Hospedagem.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Hospedagem, Nome) = 0;

        //! Atualiza o Dinheiro de uma Hospedagem
        /*!
            Atualiza o Dinheiro associado a uma Hospedagem.
            @param Hospedagem a ser atualizada.
            @param Novo Dinheiro a ser atribuído à Hospedagem.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Hospedagem, Dinheiro) = 0;


        //! Atualiza a Avaliacao de uma Hospedagem
        /*!
            Atualiza a Avaliacao de uma Hospedagem.
            @param Hospedagem a ser atualizada.
            @param Nova Avaliacao a ser atribuída à Hospedagem.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Hospedagem, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBHospedagem() {}

};

#endif // IBHOSPEDAGEM_HPP_INCLUDED
