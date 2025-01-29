#ifndef IBATIVIDADE_HPP_INCLUDED
#define IBATIVIDADE_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Atividade.hpp"

//! Interface Back Atividade
/*!
    232002771 - Implementa��o e Documenta��o \n

    A IBAtividade � respons�vel pela comunica��o do usu�rio com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de uma Atividade,
*/
class IBAtividade
{
    public:

        //! Cria uma Atividade
        /*!
            Recebe os detalhes de uma nova Atividade e adiciona ao banco de dados.
            Verifica se a Atividade � �nica antes de realizar a opera��o.
            @param Atividade a ser criada.
            @return Sucesso da opera��o.
        */
        virtual bool criar(Atividade) = 0;

        //! Exclui uma Atividade
        /*!
            Recebe uma Atividade e realiza uma confirma��o antes da exclus�o. Se a
            Atividade existe, ela � removida do banco de dados. Caso
            contr�rio, a opera��o falha.
            @param Atividade a ser exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Atividade) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. M�todo s� deve
            ser usado durante a exclus�o de Conta.
            @param Codigo da Conta exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Codigo) = 0;

        //! Exclui Atividades
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo um Destino. Exclui
            da Conta associada todas as Atividade que possuem o Destino como pai. M�todo
            s� deve ser acionado durante a exclus�o de Destino.
            @param Codigo da Conta.
            @param Codigo do Destino exclu�do.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Codigo, Codigo) = 0;

        //! L� todos Atividade
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo um Destino. Busca
            da Conta associada por todos Atividade que possuem o Destino como pai.
            @param Codigo da Conta.
            @param Codigo do Destino.
            @return Retorna um vetor de Atividade com todos os Atividade cadastrados
            com os Codigo informados.
        */
        virtual std::vector<Atividade> ler(Codigo, Codigo) = 0;

        //! Atualiza o Nome de uma Atividade
        /*!
            Atualiza o nome de uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Nome a ser atribu�do � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Nome) = 0;

        //! Atualiza a Data de uma Atividade
        /*!
            Atualiza a Data de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Data a ser atribu�da � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Data) = 0;

        //! Atualiza o Horario de uma Atividade
        /*!
            Atualiza o hor�rio de in�cio de uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Horario a ser atribu�do � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Horario) = 0;


        //! Atualiza a Duracao de uma Atividade
        /*!
            Atualiza a dura��o de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Duracao a ser atribu�da � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Duracao) = 0;


        //! Atualiza o Dinheiro de uma Atividade
        /*!
            Atualiza o Dinheiro associado a uma Atividade.
            @param Atividade a ser atualizada.
            @param Novo Dinheiro a ser atribu�do � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Dinheiro) = 0;


        //! Atualiza a Avaliacao de uma Atividade
        /*!
            Atualiza a Avaliacao de uma Atividade.
            @param Atividade a ser atualizada.
            @param Nova Avaliacao a ser atribu�da � Atividade.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Atividade, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBAtividade() {}
};

#endif // IBATIVIDADE_HPP_INCLUDED
