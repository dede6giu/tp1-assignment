#ifndef IBHOSPEDAGEM_HPP_INCLUDED
#define IBHOSPEDAGEM_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Hospedagem.hpp"

//! Interface Back Hospedagem
/*!
    232002771 - Implementação e Documentação \n

    A IBHospedagem é responsável pela comunicação do usuário com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de uma Hospedagem,
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

        //! Exclui uma Hospedagem
        /*!
            Recebe uma Hospedagem e realiza uma confirmação antes da exclusão. Se a
            Hospedagem existe, ela é removida do banco de dados. Caso
            contrário, a operação falha.
            @param Hospedagem a ser excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Hospedagem) = 0;

        //! Lê uma Hospedagem
        /*!
            Recebe um Codigo e busca suas Hospedagem no banco de dados.
            @param Codigo chave.
            @return Retorna um vetor de Hospedagem com todas as Hospedagem cadastradas
            com o Codigo informado.
        */
        virtual std::vector<Hospedagem> ler(Codigo) = 0;

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
