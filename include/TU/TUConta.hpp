#ifndef TUCONTA_HPP_INCLUDED
#define TUCONTA_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "../../include/Entidades/Conta.hpp"

//! Testes de Unidade da Entidade Conta
/*!
    232013031 - implementação. \n
    232001667 - implementação.
*/

class TUConta
{
    private:
        const std::string VALIDO_CODIGO = "iE4nmz";
        const std::string VALIDO_SENHA = "89342";

        Conta *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUCONTA_HPP_INCLUDED
