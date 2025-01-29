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

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. Método só deve
            ser usado durante a exclusão de Conta.
            @param Codigo da Conta excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Codigo) = 0;

        //! Exclui Destinos
        /*!
            Recebe dois Codigo. O primeiro é uma Conta, o segundo uma Viagem. Exclui
            da Conta associada todos os Destino que possuem a Viagem como pai. Método
            só deve ser acionado durante a exclusão de Viagem.
            @param Codigo da Conta.
            @param Codigo da Viagem excluída.
            @return Sucesso da operação.
        */
        virtual bool excluir(Codigo, Codigo) = 0;

        //! Lê todos Destino
        /*!
            Recebe dois Codigo. O primeiro é uma Conta, o segundo uma Viagem. Busca
            da Conta associada por todos Destino que possuem a Viagem como pai.
            @param Codigo da Conta.
            @param Codigo da Viagem.
            @return Retorna um vetor de Destino com todos os Destino cadastrados
            com os Codigo informados.
        */
        virtual std::vector<Destino> ler(Codigo, Codigo) = 0;

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
