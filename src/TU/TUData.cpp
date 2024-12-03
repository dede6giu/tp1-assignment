#include "TU/TUData.hpp"
#include "Dominios/Data.hpp"
#include <stdexcept>
using namespace std;

void TUData::setUp()
{
    dominio = new Data();
    estado = SUCESSO;
}

void TUData::tearDown()
{
    delete dominio;
}

void TUData::testeUniVal(string teste)
{
    dominio->setValor(teste);
    if (dominio->getValor() != teste) estado = FALHA;
}

void TUData::testarValido()
{
    try
    {
        for (int i = 0; i < TUData::VALIDO.size(); i++) {
            testeUniVal(TUData::VALIDO[i]);
        }

    }
    catch(invalid_argument &excessao)
    {
        estado = FALHA;
    }
}

void TUData::testeUniInv(string teste)
{
    try
    {
        dominio->setValor(teste);
        estado = FALHA;
    }
    catch (invalid_argument &excessao)
    {
        if (dominio->getValor() == teste) estado = FALHA;
    }
}

void TUData::testarInvalido()
{
    for (int i = 0; i < TUData::INVALIDO.size(); i++) {
        testeUniInv(TUData::INVALIDO[i]);
    }
}

int TUData::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
