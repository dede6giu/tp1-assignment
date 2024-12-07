//! Classe Teste de Unidade Horario
/*!
    232002520 - implementação
*/

#ifndef TUHORARIO_HPP_INCLUDED
#define TUHORARIO_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include <string>
#include "Dominios/Horario.hpp"

class TUHorario {
private:
    const std::vector<std::string> VALIDO = {
        "12:00", "23:59", "10:32", "00:02"};
    const std::vector<std::string> INVALIDO = {
        "27:64", "40:00", "10:70", "a3:02", "10.10", "", "10:10:10"};

    Horario *dominio;
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

#endif // TUHORARIO_HPP_INCLUDED
