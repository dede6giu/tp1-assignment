#ifndef TUAVALIACAO_HPP_INCLUDED
#define TUAVALIACAO_HPP_INCLUDED

#include <stdexcept>
#include "../../include/Dominios/Avaliacao.hpp"
#include <vector>

//! Testes de Unidade do Dominio Avaliacao
/*!
    232013031 - implementação. \n
    232001667 - implementação.
*/

class TUAvaliacao {
    private:
        const std::vector<int> VALIDO = {0, 1, 2, 3, 4, 5};
        const std::vector<int> INVALIDO = {-1, 6, 70, -100};
        Avaliacao *dominio;
        int estado;
        void setUp();
        void tearDown();
        void testarValido();
        void testeUniVal(int);
        void testarInvalido();
        void testeUniInv(int);
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUAVALIACAO_HPP_INCLUDED
