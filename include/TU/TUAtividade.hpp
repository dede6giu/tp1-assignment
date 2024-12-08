#ifndef TUATIVIDADE_HPP_INCLUDED
#define TUATIVIDADE_HPP_INCLUDED

#include <vector>
//#include
#include "../../include/Entidades/Atividade.hpp"

class TUAtividade {
private:
    const std::vector<std::vector<std::string>> VALIDO = {
        {"a124g2", "Cleber Oliveira", "07/12/24", "12:27", "27", "80", "2", "a124g2, Cleber Oliveira, 07/12/24, 12:27, 27, 80, 2"},
        {"31453s", "Humpty Dumpty", "14/02/10", "03:43", "180", "250", "3", "31453s, Humpty Dumpty, 14/02/10, 03:43, 180, 250, 3"},
        {"231gr3", "Hatsune Miku", "21/12/12", "17:30", "160", "400", "3", "231gr3, Hatsune Miku, 21/12/12, 17:30, 160, 400, 3"},
        {"3lm153", "Marcos, o Assolador de Mundos", "31/12/99", "21:45", "2", "20", "4", "3lm153, Marcos, o Assolador de Mundos, 31/12/99, 21:45, 2, 20, 4"}
    };
    const std::vector<std::vector<std::string>> INVALIDO = {
        {"das", "Joãozinho", "02/02/02", "02:02", "60", "207", "3", "das, Joãozinho, 02/02/02, 02:02, 60, 207, 3"},
        {"qw1321", "FERNANDO ANTONIO DE ARAUJO CHACON DE ALBUQUERQUE", "60", "207", "3", "qw1321, FERNANDO ANTONIO DE ARAUJO CHACON DE ALBUQUERQUE, 60, 207, 3"},
        {"qw1321", "Joãozinho", "28.12.01", "02:02", "60", "207", "3", "qw1321, Joãozinho, 28.12.01, 02:02, 60, 207, 3"},
        {"qw1321", "Joãozinho", "29/02/15", "02:02", "60", "207", "3", "qw1321, Joãozinho, 29/02/15, 02:02, 60, 207, 3"},
        {"qw1321", "Joãozinho", "31/11/22", "02:02", "60", "207", "3", "qw1321, Joãozinho, 31/11/22, 02:02, 60, 207, 3"},
        {"qw1321", "Joãozinho", "02/02/02", "24:59", "60", "207", "3", "qw1321, Joãozinho, 02/02/02, 24:59, 60, 207, 3"},
        {"qw1321", "Joãozinho", "02/02/02", "02:02", "380", "207", "3", "qw1321, Joãozinho, 02/02/02, 02:02, 380, 207, 3"},
        {"qw1321", "Joãozinho", "02/02/02", "02:02", "60", "241335010", "3", "qw1321, Joãozinho, 02/02/02, 02:02, 60, 241335010, 3"},
        {"qw1321", "Joãozinho", "02/02/02", "02:02", "60", "207", "7", "qw1321, Joãozinho, 02/02/02, 02:02, 60, 207, 7"},
    };

    Atividade *dominio;
    int estado;
    void setUp();
    void tearDown();
    void testarValido();
    void testeUniVal(std::vector<std::string>);
    void testarInvalido();
    void testeUniInv(std::vector<std::string>);

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TUATIVIDADE_HPP_INCLUDED
