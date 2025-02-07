#ifndef TUSENHA_HPP_INCLUDED
#define TUSENHA_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include <string>
#include "../../include/Dominios/Senha.hpp"

//! Testes de Unidade do Dominio Senha
/*!
    232002520 - implementação
*/

class TUSenha {
    private:
        const std::vector<std::string> VALIDO = {
            "01852", "26739", "32169"};
        const std::vector<std::string> INVALIDO = {
            "1432", "a2354", "11523", "12345", "65432"};

        Senha *dominio;
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

#endif // TUSENHA_HPP_INCLUDED
