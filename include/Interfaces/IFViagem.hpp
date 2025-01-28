#ifndef IFVIAGEM_HPP_INCLUDED
#define IFVIAGEM_HPP_INCLUDED

#include "IBViagem.hpp"
#include "Entidades/Conta.hpp"

//! Interface Front Viagem
/*!
    232002520 - implementação \n
    232013031 - documentação \n

    A IFViagem é responsável pela parte de apresentação ao usuário
    dos métodos relacionados a Viagem. Ela permite a escolha entre
    criação, exclusão, leitura e atualização de Viagem da Conta
    atualmente autenticada.
*/

class IFViagem {
    public:

        //! Inicia IFViagem
        /*!
            Método que inicia a IFViagem. Ele pergunta ao usuário qual
            operação deseja realizar entre criar, excluir, ler e atualizar,
            e chama o método apropriado da IBViagem.
            @param Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IBViagem
        /*!
            Estabelece uma referência para a IBViagem como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBViagem a ser salva.
        */
        virtual void setCntrIBViagem(IBViagem*) = 0;

        //! Destrutor Virtual
        virtual ~IFViagem(){};
};

#endif // IFVIAGEM_HPP_INCLUDED
