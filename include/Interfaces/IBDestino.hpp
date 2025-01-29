#ifndef IBDESTINO_HPP_INCLUDED
#define IBDESTINO_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Destino.hpp"

//! Interface Back Destino
/*!
    232002771 - Implementa��o e Documenta��o \n

    A IBDestino � respons�vel pela comunica��o do usu�rio com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de um Destino,
*/
class IBDestino
{
    public:

        //! Cria uma Destino
        /*!
            Recebe os detalhes de umo novo Destino e adiciona ao banco de dados.
            Verifica se o Destino � �nico antes de realizar a opera��o.
            @param Destino a ser criado.
            @return Sucesso da opera��o.
        */
        virtual bool criar(Destino) = 0;

        //! Exclui um Destino
        /*!
            Recebe um Destino e raliza uma confirma��o antes da exclus�o. Se o
            Destino existe, ele � removido do banco de dados. Caso
            contr�rio, a opera��o falha.
            @param Destino a ser exclu�do.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Destino) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. M�todo s� deve
            ser usado durante a exclus�o de Conta.
            @param Codigo da Conta exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Codigo) = 0;

        //! Exclui Destinos
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo uma Viagem. Exclui
            da Conta associada todos os Destino que possuem a Viagem como pai. M�todo
            s� deve ser acionado durante a exclus�o de Viagem.
            @param Codigo da Conta.
            @param Codigo da Viagem exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Codigo, Codigo) = 0;

        //! L� todos Destino
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo uma Viagem. Busca
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
            @param Novo Nome a ser atribu�do ao Destino.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Destino, Nome) = 0;

        //! Atualiza a Data de um Destino
        /*!
            Atualiza a Data de in�cio ou fim de um Destino.
            @param Destino a ser atualizado.
            @param Nova Data a ser atribu�da ao Destino.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Destino, Data) = 0;

        //! Atualiza a Avaliacao de um Destino
        /*!
            Atualiza a Avaliacao de um Destino.
            @param Destino a ser atualizada.
            @param Nova Avaliacao a ser atribu�da ao Destino.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Destino, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBDestino() {}
};

#endif // IBDESTINO_HPP_INCLUDED
