#ifndef IBATIVIDADE_HPP_INCLUDED
#define IBATIVIDADE_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Atividade.hpp"

//! Interface Back Atividade
/*!
    232002771 - Implementação e Documentação \n

    A IBAtividade é responsável pela comunicação do usuário com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de uma Atividade,
*/
class IBAtividade
{
    public:

        //! Cria uma Atividade
        /*!
            Recebe os detalhes de uma nova Atividade e adiciona ao banco de dados.
            Verifica se a Atividade é única antes de realizar a operação.
            @param Atividade a ser criada.
            @return Sucesso da operação.
        */
        virtual bool criar(Atividade) = 0;

        //! Exclui uma Atividade
        /*!
            Recebe uma Atividade e realiza uma confirmação antes da exclusão. Se a
            Atividade existe, ela é removida do banco de dados. Caso
            contrário, a operação falha.
            @param Atividade a ser excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Atividade) = 0;

        //! Lê uma Atividade
        /*!
            Recebe um Codigo e busca suas Atividade no banco de dados.
            @param Codigo chave.
            @return Retorna um vetor de Atividade com todas as Atividade cadastradas
            com o Codigo informado.
        */
        virtual std::vector<Atividade> ler(Codigo) = 0;

        //! Atualiza o Nome de uma Atividade
        /*!
            Atualiza o nome de uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Nome a ser atribuído à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Nome) = 0;

        //! Atualiza a Data de uma Atividade
        /*!
            Atualiza a Data de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Data a ser atribuída à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Data) = 0;

        //! Atualiza o Horario de uma Atividade
        /*!
            Atualiza o horário de início de uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Horario a ser atribuído à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Horario) = 0;


        //! Atualiza a Duracao de uma Atividade
        /*!
            Atualiza a duração de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Duracao a ser atribuída à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Duracao) = 0;


        //! Atualiza o Dinheiro de uma Atividade
        /*!
            Atualiza o Dinheiro associado a uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Dinheiro a ser atribuído à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Dinheiro) = 0;


        //! Atualiza a Avaliacao de uma Atividade
        /*!
            Atualiza a Avaliacao de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Avaliacao a ser atribuída à Atividade.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Atividade, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBAtividade() {}
};

#endif // IBATIVIDADE_HPP_INCLUDED
