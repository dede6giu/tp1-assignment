#include "TU/TUDuracao.hpp"
#include "Dominios/Duracao.hpp"
#include <stdexcept>
using namespace std;

void TUDuracao::setUp()
{
    dominio = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown()
{
    delete dominio;
}

void TUDuracao::testeUniVal(string teste)
{
    dominio->setValor(teste);
    if (dominio->getValor() != teste) estado = FALHA;
}

void TUDuracao::testarValido()
{
    try
    {
        for (int i = 0; i < TUDuracao::VALIDO.size(); i++) {
            testeUniVal(TUDuracao::VALIDO[i]);
        }

    }
    catch(invalid_argument &excessao)
    {
        estado = FALHA;
    }
}

void TUDuracao::testeUniInv(string teste)
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

void TUDuracao::testarInvalido()
{
    for (int i = 0; i < TUDuracao::INVALIDO.size(); i++) {
        testeUniInv(TUDuracao::INVALIDO[i]);
    }
}

int TUDuracao::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
