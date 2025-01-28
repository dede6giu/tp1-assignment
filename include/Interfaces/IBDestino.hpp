#ifndef IBDESTINO_HPP_INCLUDED
#define IBDESTINO_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Destino.hpp"

//! Interface Back Destino
/*!
    232002771 - Implementação e Documentação \n

    A IBDestino é responsável pela comunicação do usuário com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de um Destino,
*/
class IBDestino
{
    public:

        //! Cria uma Destino
        /*!
            Recebe os detalhes de umo novo Destino e adiciona ao banco de dados.
            Verifica se o Destino é único antes de realizar a operação.
            @param Destino a ser criado.
            @return Sucesso da operação.
        */
        virtual bool criar(Destino) = 0;

        //! Exclui um Destino
        /*!
            Recebe um Destino e raliza uma confirmação antes da exclusão. Se o
            Destino existe, ele é removido do banco de dados. Caso
            contrário, a operação falha.
            @param Destino a ser excluído.
            @return Sucesso da operação.
        */
        virtual bool excluir(Destino) = 0;

        //! Lê um Destino
        /*!
            Recebe um Codigo e busca seus Destino no banco de dados.
            @param Codigo chave.
            @return Retorna um vetor de Destino com todos os Destino cadastrados
            com o Codigo informado.
        */
        virtual std::vector<Destino> ler(Codigo) = 0;

        //! Atualiza o Nome de um Destino
        /*!
            Atualiza o nome de um Destino.
            @param Destino a ser atualizado.
            @param Novo Nome a ser atribuído ao Destino.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Destino, Nome) = 0;

        //! Atualiza a Data de um Destino
        /*!
            Atualiza a Data de início ou fim de um Destino.
            @param Destino a ser atualizado.
            @param Nova Data a ser atribuída ao Destino.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Destino, Data) = 0;

        //! Atualiza a Avaliacao de um Destino
        /*!
            Atualiza a Avaliacao de um Destino.
            @param Destino a ser atualizada.
            @param Nova Avaliacao a ser atribuída ao Destino.
            @return Sucesso da operação.
        */
        virtual bool atualizar(Destino, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBDestino() {}
};

#endif // IBDESTINO_HPP_INCLUDED
