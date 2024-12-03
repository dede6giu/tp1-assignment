#ifndef TUAVALIACAO_HPP_INCLUDED
#define TUAVALIACAO_HPP_INCLUDED

//! Testes de unidade Avaliacao
/*!
    232001667 - implementação
*/

#include <stdexcept>
#include "Dominios/Avaliacao.hpp"

using namespace std;

class TUAvaliacao {
    private:
        const static int VALOR_VALIDO = "2";
        const static int VALOR_INVALIDO = "-69";
        Avaliacao *avaliacao; 
        int estado; 
        void setUp(); 
        void tearDown(); 
        void testarCenarioValorValido(); 
        void testarCenarioValorInvalido(); 
    public:
        const static int SUCESSO = 0; 
        const static int FALHA = -1; 
        int run(); 
};

#endif // TUAVALIACAO_HPP_INCLUDED
