#include "TU/TUHorario.hpp"

using namespace std;

void TUHorario::setUp()
{
    dominio = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown()
{
    delete dominio;
}

void TUHorario::testeUniVal(string teste)
{
    dominio->setValor(teste);
    if (dominio->getValor() != teste) estado = FALHA;
}

void TUHorario::testarValido()
{
    try
    {
        for (int i = 0; i < TUHorario::VALIDO.size(); i++) {
            testeUniVal(TUHorario::VALIDO[i]);
        }

    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUHorario::testeUniInv(string teste)
{
    try
    {
        dominio->setValor(teste);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (dominio->getValor() == teste) estado = FALHA;
    }
}

void TUHorario::testarInvalido()
{
    for (int i = 0; i < TUHorario::INVALIDO.size(); i++) {
        testeUniInv(TUHorario::INVALIDO[i]);
    }
}

int TUHorario::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
