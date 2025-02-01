#ifndef IFVIAGEM_HPP_INCLUDED
#define IFVIAGEM_HPP_INCLUDED

#include "IBViagem.hpp"
#include "IFDestino.hpp"
#include "../Entidades/Conta.hpp"

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
            Método que inicia a IFViagem. O método, por padrão, pergunta
            ao usuário se deseja manejar as Viagem já registradas ou se
            deseja criar uma nova, ou retornar uma tela. \n
            Se desejar criar uma nova, o sistema requisita todas as informações
            necessárias para a criação de um objeto Viagem (com exceção do
            Codigo da Conta) e então envia os resultados para o backend. Deve
            esclarecer ao usuário se a operação falhou ou não. \n
            Se desejar visualizar as Viagem, o sistema deve chamar a leitura
            do backend e apresentar uma por vez. O usuário então deve escolher entre
            mostrar a próxima (se possível), a anterior (se possível), pesquisar uma
            Viagem pela tag, editar a atual, excluir a atual ou ver os Destino
            associados com a atual. \n
            Se escolher retornar uma tela, a função retorna void.
            @param Conta atualmente autenticada.
        */
        virtual void run(Codigo) = 0;

        //! Dependência da IBViagem
        /*!
            Estabelece uma referência para a IBViagem como uma variável,
            permitindo uma conexão com os métodos referentes a Viagem
            atuantes no banco de dados.
            @param Referência à IBViagem a ser salva.
        */
        virtual void setCntrIBViagem(IBViagem*) = 0;

        //! Dependência da IFDestino
        /*!
            Estabelece uma referência para a IFDestino como uma variável,
            permitindo uma conexão com os métodos referentes a Destino
            atuantes em Destino.
            @param Referência à IFDestino a ser salva.
        */
        virtual void setCntrIFDestino(IFDestino*) = 0;

        //! Destrutor Virtual
        virtual ~IFViagem(){};
};

#endif // IFVIAGEM_HPP_INCLUDED
