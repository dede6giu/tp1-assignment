#include "TU/TUCodigo.hpp"

using namespace std;

void TUCodigo::setUp()
{
    dominio = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown()
{
    delete dominio;
}

void TUCodigo::testeUniVal(string teste)
{
    dominio->setValor(teste);
    if (dominio->getValor() != teste) estado = FALHA;
}

void TUCodigo::testarValido()
{
    try
    {
        for (int i = 0; i < TUCodigo::VALIDO.size(); i++) {
            testeUniVal(TUCodigo::VALIDO[i]);
        }

    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
    catch (length_error &excecao)
    {
        estado = FALHA;
    }
}

void TUCodigo::testeUniInv(string teste)
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
    catch (length_error &excecao)
    {
        if (dominio->getValor() == teste) estado = FALHA;
    }
}

void TUCodigo::testarInvalido()
{
    for (int i = 0; i < TUCodigo::INVALIDO.size(); i++) {
        testeUniInv(TUCodigo::INVALIDO[i]);
    }
}

int TUCodigo::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
