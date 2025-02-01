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
            Método que inicia a IFHospedagem. O método, por padrão, pergunta
            ao usuário se deseja manejar as Hospedagem já registrados no
            Destino recebido ou se deseja criar uma nova, ou retornar uma tela. \n
            Se desejar criar uma nova, o sistema requisita todas as informações
            necessárias para a criação de um objeto Hospedagem (com exceção do
            Codigo da Conta) e então envia o objeto para o backend. Deve
            esclarecer ao usuário se a operação falhou ou não. \n
            Se desejar visualizar as Hospedagem, o sistema deve chamar a leitura
            do backend e apresentar uma Hospedagem por vez. O usuário então deve
            escolher entre mostrar a próxima (se possível), a anterior (se
            possível), pesquisar uma Hospedagem pela tag, editar a atual ou
            excluir a atual. \n
            Se escolher retornar uma tela, a função retorna void.
            @param Conta atualmente autenticada.
            @param Codigo Tag do Destino associado.
        */
        virtual void run(Codigo, Codigo) = 0;

        //! Dependência da IBHospedagem
        /*!
            Estabelece uma referência para a IBHospedagem como uma variável,
            permitindo uma conexão com os métodos referentes a Hospedagem
            atuantes no banco de dados.
            @param Referência à IBHospedagem a ser salva.
        */
        virtual void setCntrIBHospedagem(IBHospedagem*) = 0;

        //! Destrutor Virtual
        virtual ~IFHospedagem() {}
};

#endif // IFHOSPEDAGEM_HPP_INCLUDED
