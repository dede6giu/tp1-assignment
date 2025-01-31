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
            Método que inicia a IFAtividade. O método, por padrão, pergunta
            ao usuário se deseja manejar as Atividade já registrados no
            Destino recebido ou se deseja criar uma nova, ou retornar uma tela. \n
            Se desejar criar uma nova, o sistema requisita todas as informações
            necessárias para a criação de um objeto Atividade (com excessão do
            Codigo da Conta) e então envia o objeto para o backend. Deve
            esclarecer ao usuário se a operação falhou ou não. \n
            Se desejar visualizar as Atividade, o sistema deve chamar a leitura
            do backend e apresentar uma Atividade por vez. O usuário então deve
            escolher entre mostrar a próxima (se possível), a anterior (se
            possível), pesquisar uma Atividade pela tag, editar a atual ou
            excluir a atual. \n
            Se escolher retornar uma tela, a função retorna void.
            @param Conta atualmente autenticada.
            @param Codigo Tag do Destino associado.
        */
        virtual void run(Codigo, Codigo) = 0;

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
