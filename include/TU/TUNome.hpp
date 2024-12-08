#ifndef TUNOME_HPP_INCLUDED
#define TUNOME_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include <string>
#include "../../include/Dominios/Nome.hpp"

//! TUNome
/*!
    232001667 - implementação \n
    232013031 - implementação
*/

class TUNome {
    private:
        const std::vector<std::string> VALIDO = {"disturbing the peace", "123456789012345678901234567890", "@r-8&jk ~ a ]"};
        const std::vector<std::string> INVALIDO = {"", "1234567890123456789012345678901"};
        Nome *dominio;
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

#endif // TUNOME_HPP_INCLUDED
