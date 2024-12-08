#ifndef TUHOSPEDAGEM_HPP_INCLUDED
#define TUHOSPEDAGEM_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "../../include/Entidades/Hospedagem.hpp"

class TUHospedagem
{
    private:
        const std::string VALIDO_CODIGO = "iE4nmz";
        const std::string VALIDO_NOME = "nome de teste";
        const int VALIDO_AVALIACAO = 3;
        const int VALIDO_DIARIA = 25410;

        Hospedagem *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUHOSPEDAGEM_HPP_INCLUDED
