#ifndef IFATIVIDADE_HPP_INCLUDED
#define IFATIVIDADE_HPP_INCLUDED

#include "IBAtividade.hpp"
#include "Entidades/Conta.hpp"

//! Interface Front Atividade
/*!
    232013031 - implementação \n

    A IFAtividade é responsável pela parte de apresentação ao usuário
    dos métodos relacionados a Atividade. Ela permite a escolha entre
    criação, exclusão, leitura e atualização de Atividade da Conta
    atualmente autenticada.
*/

class IFAtividade
{
    public:

        //! Inicia IFAtividade
        /*!
            Método que inicia a IFAtividade. Ele pergunta ao usuário qual
            operação deseja realizar entre criar, excluir, ler e atualizar,
            e chama o método apropriado da IBAtividade.
            @param Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IBAtividade
        /*!
            Estabelece uma referência para a IBAtividade como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBAtividade a ser salva.
        */
        virtual void setCntrIBAtividade(IBAtividade*) = 0;

        //! Destrutor Virtual
        virtual ~IFAtividade(){};
};

#endif // IFATIVIDADE_HPP_INCLUDED
