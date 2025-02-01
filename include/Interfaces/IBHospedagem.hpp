#ifndef IBHOSPEDAGEM_HPP_INCLUDED
#define IBHOSPEDAGEM_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Hospedagem.hpp"

//! Interface Back Hospedagem
/*!
    232002771 - Implementa��o e Documenta��o \n

    A IBHospedagem � respons�vel pela comunica��o do usu�rio com
    o banco de dados quanto ao controle de Hospedagem. Ela permite
    criar, excluir, ler e atualizar os dados de uma Hospedagem,
*/
class IBHospedagem
{
    public:

        //! Cria uma Hospedagem
        /*!
            Recebe os detalhes de uma nova Hospedagem e adiciona ao banco de dados.
            Verifica se a Hospedagem � �nica antes de realizar a opera��o.
            @param Hospedagem a ser criada.
            @return Sucesso da opera��o.
        */
        virtual bool criar(Hospedagem) = 0;

        //! Cria uma Tabela
        /*!
            Recebe um Codigo e adiciona uma nova tabela com tal Codigo ao banco
            de dados, se n�o j� existir a tabela.
            @param Codigo da Conta.
        */
        virtual void criar(Codigo) = 0;

        //! Exclui uma Hospedagem
        /*!
            Recebe uma Hospedagem e realiza uma confirma��o antes da exclus�o. Se a
            Hospedagem existe, ela � removida do banco de dados. Caso
            contr�rio, a opera��o falha.
            @param Hospedagem a ser exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Hospedagem) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. M�todo s� deve
            ser usado durante a exclus�o de Conta.
            @param Codigo da Conta exclu�da.
        */
        virtual void excluir(Codigo) = 0;

        //! Exclui Hospedagens
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo um Destino. Exclui
            da Conta associada todos os Hospedagem relacionados ao Destino.
            M�todo s� deve ser acionado durante a exclus�o de Destino.
            @param Codigo da Conta.
            @param Codigo do Destino exclu�do.
        */
        virtual void excluir(Codigo, Codigo) = 0;

        //! L� uma Hospedagem
        /*!
            Verifica a exist�ncia de uma Hospedagem no banco de dados.
            @param Hospedagem a verificar.
            @return Exist�ncia da Hospedagem.
        */
        virtual bool ler(Hospedagem) = 0;

        //! L� todos Hospedagem
        /*!
            Recebe dois Codigo. O primeiro � uma Conta, o segundo um Destino. Busca
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
            @param Novo Nome a ser atribu�do � Hospedagem.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Hospedagem, Nome) = 0;

        //! Atualiza o Dinheiro de uma Hospedagem
        /*!
            Atualiza o Dinheiro associado a uma Hospedagem.
            @param Hospedagem a ser atualizada.
            @param Novo Dinheiro a ser atribu�do � Hospedagem.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Hospedagem, Dinheiro) = 0;


        //! Atualiza a Avaliacao de uma Hospedagem
        /*!
            Atualiza a Avaliacao de uma Hospedagem.
            @param Hospedagem a ser atualizada.
            @param Nova Avaliacao a ser atribu�da � Hospedagem.
            @return Sucesso da opera��o.
        */
        virtual bool atualizar(Hospedagem, Avaliacao) = 0;

        //! Destrutor Virtual
        virtual ~IBHospedagem() {}

};

#endif // IBHOSPEDAGEM_HPP_INCLUDED
