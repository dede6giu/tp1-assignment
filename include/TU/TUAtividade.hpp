#ifndef TUATIVIDADE_HPP_INCLUDED
#define TUATIVIDADE_HPP_INCLUDED

#include <vector>
#include "../../include/Entidades/Atividade.hpp"

//! Testes de Unidade da Entidade Atividade
/*!
    232029274 - implementação. \n
    232002520 - implementação.
*/

class TUAtividade
{
    private:
        const std::string VALIDO_CODIGO = "iE4nmz";
        const std::string VALIDO_NOME = "nome de teste";
        const std::string VALIDO_DATA = "12/12/12";
        const std::string VALIDO_HORARIO = "15:30";
        const int VALIDO_DURACAO = 50;
        const int VALIDO_PRECO = 200;
        const int VALIDO_AVALIACAO = 3;

        Atividade *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


#endif // TUATIVIDADE_HPP_INCLUDED
