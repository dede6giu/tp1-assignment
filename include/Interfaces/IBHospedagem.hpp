#ifndef IBHOSPEDAGEM_HPP_INCLUDED
#define IBHOSPEDAGEM_HPP_INCLUDED

#include <vector>
#include "../Entidades/Conta.hpp"
#include "../Entidades/Hospedagem.hpp"

//! Interface Back Hospedagem
/*!
    232002771 - Implementa��o e Documenta��o \n

    A IBHospedagem � respons�vel pela comunica��o do usu�rio com
    o banco de dados. Ela permite criar, excluir, ler e atualizar os dados de uma Hospedagem,
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

        //! Exclui uma Hospedagem
        /*!
            Recebe uma Hospedagem e realiza uma confirma��o antes da exclus�o. Se a
            Hospedagem existe, ela � removida do banco de dados. Caso
            contr�rio, a opera��o falha.
            @param Hospedagem a ser exclu�da.
            @return Sucesso da opera��o.
        */
        virtual bool excluir(Hospedagem) = 0;

        //! L� uma Hospedagem
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
