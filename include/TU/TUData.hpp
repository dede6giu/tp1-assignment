#ifndef TUDATA_HPP_INCLUDED
#define TUDATA_HPP_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>
#include "../../include/Dominios/Data.hpp"

//! Testes de Unidade do Dominio Data
/*!
    232013031 - implementação.
*/


class TUData
{
    private:
        const std::vector<std::string> VALIDO = {
            "29/02/24", "12/12/12", "31/08/99", "30/09/00", "29/02/00"};
        const std::vector<std::string> INVALIDO = {
            "99/01/01", "00/01/01", "01/99/01", "01/00/01", "29/02/23", "32/01/18", "31/04/72", "01/01/00/01", "", "aa/aa/aa", "a0/b0/c0", "datainvalida"};

        Data* dominio;
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


#endif // TUDATA_HPP_INCLUDED
