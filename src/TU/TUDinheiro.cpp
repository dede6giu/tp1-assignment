#include "TU/TUDinheiro.hpp"

using namespace std;

void TUDinheiro::setUp()
{
    dominio = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown(){
    delete dominio;
}

void TUDinheiro::testeUniVal(int valor)
{
    dominio->setValor(valor);
    if (dominio->getValor() != valor) estado = FALHA;
}

void TUDinheiro::testarValido()
{
    try
    {
        for (int i = 0; i < VALIDO.size(); i++)
        {
            testeUniVal(VALIDO[i]);
        }
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUDinheiro::testeUniInv(int valor)
{
    try
    {
        dominio->setValor(valor);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dominio->getValor() == valor)
        estado = FALHA;
    }
}

void TUDinheiro::testarInvalido()
{
    for (int i = 0; i < INVALIDO.size(); i++)
    {
        testeUniInv(INVALIDO[i]);
    }
}

int TUDinheiro::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
