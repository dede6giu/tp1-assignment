#ifndef IFDESTINO_HPP_INCLUDED
#define IFDESTINO_HPP_INCLUDED

#include "IBDestino.hpp"
#include "IFAtividade.hpp"
#include "IFHospedagem.hpp"
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
            Método que inicia a IFDestino. O método, por padrão, pergunta
            ao usuário se deseja manejar os Destinos já registrados na Viagem
            recebida ou se deseja criar um novo, ou retornar uma tela. \n
            Se desejar criar um novo, o sistema requisita todas as informações
            necessárias para a criação de um objeto Destino (com excessão do
            Codigo da Conta) e então envia o objeto para o backend. Deve
            esclarecer ao usuário se a operação falhou ou não. \n
            Se desejar visualizar os Destino, o sistema deve chamar a leitura
            do backend e apresentar um Destino por vez. O usuário então deve
            escolher entre mostrar o próximo (se possível), o anterior (se
            possível), pesquisar um Destino pela tag, editar o atual, excluir
            o atual, ver as Hospedagem associadas com o atual ou ver as
            Atividade associadas com o atual. \n
            Se escolher retornar uma tela, a função retorna void.
            @param Conta atualmente autenticada.
            @param Codigo Tag da Viagem associada.
        */
        virtual void run(Codigo, Codigo) = 0;

        //! Dependência da IBDestino
        /*!
            Estabelece uma referência para a IBDestino como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBDestino a ser salva.
        */
        virtual void setCntrIBDestino(IBDestino*) = 0;

        //! Dependência da IFHospedagem
        /*!
            Estabelece uma referência para a IFHospedagem como uma variável,
            permitindo uma conexão com os métodos atuantes em Hospedagem.
            @param Referência à IFHospedagem a ser salva.
        */
        virtual void setCntrIFHospedagem(IFHospedagem*) = 0;

        //! Dependência da IFAtividade
        /*!
            Estabelece uma referência para a IFAtividade como uma variável,
            permitindo uma conexão com os métodos atuantes em Atividade.
            @param Referência à IFAtividade a ser salva.
        */
        virtual void setCntrIFAtividade(IFAtividade*) = 0;

        //! Destrutor Virtual
        virtual ~IFDestino() {}
};

#endif // IFDESTINO_HPP_INCLUDED
