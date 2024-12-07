#ifndef TUDINHEIRO_HPP_INCLUDED
#define TUDINHEIRO_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "Dominios/Dinheiro.hpp"

//! TUDinheiro
/*!
    232001667 - implementação \n
    232013031 - implementação
*/

class TUDinheiro {
    private:
        const std::vector<int> VALIDO = {0, 1, 100, 100000, 20000000, 12345678, 19999999};
        const std::vector<int> INVALIDO = {-100, 200000001, -1, 123456789};
        Dinheiro *dominio;
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

#endif // TUDINHEIRO_HPP_INCLUDED
