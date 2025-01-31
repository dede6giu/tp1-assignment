#ifndef IFCONTROLE_HPP_INCLUDED
#define IFCONTROLE_HPP_INCLUDED

#include "IFConta.hpp"
#include "IFAutenticacao.hpp"
#include "IFDados.hpp"

//! Interface Front Controle
/*!
    232002520 - implementação e documentação \n

    A IFControle é responsável pela parte de apresentação ao usuário
    dos métodos relacionados ao controle geral do programa. Ela permite
    a criação de uma nova conta, a autenticação de uma conta existente
    e a saída do programa.
*/

class IFControle {
    public:

        //! Inicia IFControle
        /*!
            Método que inicia a IFControle. O método, por padrão, pergunta
            ao usuário se deseja criar uma nova conta, autenticar uma conta
            existente ou sair do programa. \n
            Se escolher criar uma nova conta, o sistema envia o usuario para a
            tela de criacao de conta manejada por IFConta. \n
            Se escolher autenticar uma conta, o sistema envia o usuario para a
            tela de autenticacao manejada por IFAutenticacao. Se a autenticacao
            ocorrer com sucesso, o IFControle envia o usuario autenticado para
            a tela do IFDados. Se o usuario, em algum momento, sair da tela do
            IFDados, deve-se assumir que tal nao esta mais autenticado. \n
            Se escolher sair do programa, a função retorna void. \n
        */
        virtual void run() = 0;

        //! Dependência da IFConta
        /*!
            Estabelece uma referência para a IFConta como uma variável,
            permitindo uma conexão com os métodos atuantes na criação de contas.
            @param Referência à IFConta a ser salva.
        */
        virtual void setCntrIFConta(IFConta*) = 0;

        //! Dependência da IFAutenticacao
        /*!
            Estabelece uma referência para a IFAutenticacao como uma variável,
            permitindo uma conexão com os métodos atuantes na autenticação de contas.
            @param Referência à IFAutenticacao a ser salva.
        */
        virtual void setCntrIFAutenticacao(IFAutenticacao*) = 0;

        //! Dependência da IFDados
        /*!
            Estabelece uma referência para a IFDados como uma variável,
            permitindo uma conexão com os métodos atuantes na interface.
            @param Referência à IFAutenticacao a ser salva.
        */
        virtual void setCntrIFAutenticacao(IFAutenticacao*) = 0;

        //! Destrutor Virtual
        virtual ~IFControle(){};
};

#endif // IFCONTROLE_HPP_INCLUDED
