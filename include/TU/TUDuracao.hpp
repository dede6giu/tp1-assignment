#ifndef TUDuracao_HPP_INCLUDED
#define TUDuracao_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "../../include/Dominios/Duracao.hpp"

//! TUDuracao
/*!
    232002771 - implementação
*/

class TUDuracao
{
    private:
        const std::vector<int> VALIDO = {
            0, 360, 123, 294, 300};
        const std::vector<int> INVALIDO = {
            -1, 361, 1000, -27};

        Duracao* dominio;
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


#endif // TUDuracao_HPP_INCLUDED
