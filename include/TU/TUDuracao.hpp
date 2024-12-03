#ifndef TUDuracao_HPP_INCLUDED
#define TUDuracao_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "Dominios/Duracao.hpp"

//! TUDuracao
/*!
    232002771 - implementação
*/

class TUDuracao
{
    private:
        const std::vector<std::int> VALIDO = {
            0, 360, 123, 294, 300};
        const std::vector<std::int> INVALIDO = {
            -1, 361, 1000, -27};

        Duracao* dominio;
        int estado;
        void setUp();
        void tearDown();
        void testarValido();
        void testeUniVal(std::int);
        void testarInvalido();
        void testeUniInv(std::int);

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


#endif // TUDuracao_HPP_INCLUDED
