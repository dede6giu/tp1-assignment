#include "../../include/TU/TUDuracao.hpp"

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

void TUDuracao::testeUniVal(int teste)
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

void TUDuracao::testeUniInv(int teste)
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
