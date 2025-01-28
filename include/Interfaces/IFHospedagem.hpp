#ifndef IFHOSPEDAGEM_HPP_INCLUDED
#define IFHOSPEDAGEM_HPP_INCLUDED

#include "IBHospedagem.hpp"
#include "Entidades/Conta.hpp"

//! Interface Front Hospedagem
/*!
    232013031 - implementação \n

    A IFHospedagem é responsável pela parte de apresentação ao usuário
    dos métodos relacionados a Hospedagem. Ela permite a escolha entre
    criação, exclusão, leitura e atualização de Hospedagem da Conta
    atualmente autenticada.
*/

class IFHospedagem
{
    public:

        //! Inicia IFHospedagem
        /*!
            Método que inicia a IFHospedagem. Ele pergunta ao usuário qual
            operação deseja realizar entre criar, excluir, ler e atualizar,
            e chama o método apropriado da IBHospedagem.
            @param Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IBHospedagem
        /*!
            Estabelece uma referência para a IBHospedagem como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBHospedagem a ser salva.
        */
        virtual void setCntrIBHospedagem(IBHospedagem*) = 0;

        //! Destrutor Virtual
        virtual ~IFHospedagem() {}
};

#endif // IFHOSPEDAGEM_HPP_INCLUDED
