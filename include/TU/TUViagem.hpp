#ifndef TUVIAGEM_HPP_INCLUDED
#define TUVIAGEM_HPP_INCLUDED

#include <stdexcept>
#include "../../include/Entidades/Viagem.hpp"

class TUViagem
{
    private:
        const int VALIDO_AVALIACAO = 3;
        const std::string VALIDO_CODIGO = "iE4nmz";
        const std::string VALIDO_NOME = "nome de teste";

        Viagem *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUVIAGEM_HPP_INCLUDED
