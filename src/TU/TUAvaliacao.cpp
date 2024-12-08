#include "../../include/TU/TUAvaliacao.hpp"

using namespace std;

void TUAvaliacao::setUp()
{
    dominio = new Avaliacao();
    estado = SUCESSO;
}

void TUAvaliacao::tearDown(){
    delete dominio;
}

void TUAvaliacao::testeUniVal(int valor)
{
    dominio->setValor(valor);
    if (dominio->getValor() != valor) estado = FALHA;
}

void TUAvaliacao::testarValido()
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

void TUAvaliacao::testeUniInv(int valor)
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

void TUAvaliacao::testarInvalido()
{
    for (int i = 0; i < INVALIDO.size(); i++)
    {
        testeUniInv(INVALIDO[i]);
    }
}

int TUAvaliacao::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
