#ifndef TUCODIGO_HPP_INCLUDED
#define TUCODIGO_HPP_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>
#include "../../include/Dominios/Codigo.hpp"

//! Testes de Unidade do Dominio Codigo
/*!
    232002771 - implementação.
*/

class TUCodigo
{
    private:
        const std::vector<std::string> VALIDO = {
            "AbC123", "AbCdEf", "dS03sa", "A2sPk4", "Kig3hF"};
        const std::vector<std::string> INVALIDO = {
            "ABC12", "ABCD1234", "@@@@@@", ""};

        Codigo* dominio;
        int estado;
        void setUp();
        void tearDown();
        void testarValido();
        void testeUniVal(std::string);
        void testarInvalido();
        void testeUniInv(std::string);

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


#endif // TUCODIGO_HPP_INCLUDED
