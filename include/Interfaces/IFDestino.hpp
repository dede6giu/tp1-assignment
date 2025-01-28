#ifndef IFDESTINO_HPP_INCLUDED
#define IFDESTINO_HPP_INCLUDED

#include "IBDestino.hpp"
#include "Entidades/Conta.hpp"

//! Interface Front Destino
/*!
    232013031 - implementação \n

    A IFDestino é responsável pela parte de apresentação ao usuário
    dos métodos relacionados a Destino. Ela permite a escolha entre
    criação, exclusão, leitura e atualização de Destino da Conta
    atualmente autenticada.
*/

class IFDestino
{
    public:

        //! Inicia IFDestino
        /*!
            Método que inicia a IFDestino. Ele pergunta ao usuário qual
            operação deseja realizar entre criar, excluir, ler e atualizar,
            e chama o método apropriado da IBDestino.
            @param Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IBDestino
        /*!
            Estabelece uma referência para a IBDestino como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBDestino a ser salva.
        */
        virtual void setCntrIBDestino(IBDestino*) = 0;

        //! Destrutor Virtual
        virtual ~IFDestino() {}
};

#endif // IFDESTINO_HPP_INCLUDED
