#ifndef IFCONTROLE_HPP_INCLUDED
#define IFCONTROLE_HPP_INCLUDED

#include "IFConta.hpp"
#include "../Interfaces/IFAutenticacao.hpp"
#include "Entidades/Conta.hpp"

//! Interface Front Controle
/*!
    232002520 - implementa��o e documenta��o \n

    A IFControle � respons�vel pela parte de apresenta��o ao usu�rio
    dos m�todos relacionados ao controle geral do programa. Ela permite
    a cria��o de uma nova conta, a autentica��o de uma conta existente
    e a sa�da do programa.
*/

class IFControle {
    public:

        //! Inicia IFControle
        /*!
            M�todo que inicia a IFControle. O m�todo, por padr�o, pergunta
            ao usu�rio se deseja criar uma nova conta, autenticar uma conta
            existente ou sair do programa. \n
            Se escolher criar uma nova conta, o sistema requisita todas as
            informa��es necess�rias para a cria��o de um objeto Conta e ent�o
            envia os resultados para o backend. Deve esclarecer ao usu�rio se
            a opera��o falhou ou n�o. \n
            Se escolher autenticar uma conta, o sistema requisita as informa��es
            de autentica��o (como login e senha) e tenta autenticar a conta. Deve
            esclarecer ao usu�rio se a opera��o falhou ou n�o. \n
            Se escolher sair do programa, a fun��o retorna void.\n
        */
        virtual void run() = 0;

        //! Depend�ncia da IFConta
        /*!
            Estabelece uma refer�ncia para a IFConta como uma vari�vel,
            permitindo uma conex�o com os m�todos atuantes na cria��o de contas.
            @param Refer�ncia � IFConta a ser salva.
        */
        virtual void setCntrIFConta(IFConta*) = 0;

        //! Depend�ncia da IFAutenticacao
        /*!
            Estabelece uma refer�ncia para a IFAutenticacao como uma vari�vel,
            permitindo uma conex�o com os m�todos atuantes na autentica��o de contas.
            @param Refer�ncia � IFAutenticacao a ser salva.
        */
        virtual void setCntrIFAutenticacao(IFAutenticacao*) = 0;

        //! Destrutor Virtual
        virtual ~IFControle(){};
};

#endif // IFCONTROLE_HPP_INCLUDED
