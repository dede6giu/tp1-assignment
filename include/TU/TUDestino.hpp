#ifndef TUDESTINO_HPP_INCLUDED
#define TUDESTINO_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include "Entidades/Destino.hpp"

class TUDestino
{
    private:
        const std::string VALIDO_CODIGO = "iE4nmz";
        const std::string VALIDO_NOME = "nome de teste";
        const std::string VALIDO_INICIO = "04/04/04";
        const std::string VALIDO_FIM = "05/05/05";
        const int VALIDO_AVALIACAO = 3;

        Destino *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUDESTINO_HPP_INCLUDED
