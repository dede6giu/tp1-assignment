#include "../../include/TU/TUNome.hpp"

using namespace std;

void TUNome::setUp()
{
    dominio = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete dominio;
}

void TUNome::testeUniVal(string valor)
{
    dominio->setValor(valor);
    if (dominio->getValor() != valor) estado = FALHA;
}

void TUNome::testarValido()
{
    try
    {
        for (int i = 0; i < VALIDO.size(); i++)
        {
            testeUniVal(VALIDO[i]);
        }
    }
    catch(length_error &excecao)
    {
        estado = FALHA;
    }
}

void TUNome::testeUniInv(string valor)
{
    try
    {
        dominio->setValor(valor);
        estado = FALHA;
    }
    catch(length_error &excecao){
        if (dominio->getValor() == valor)
        estado = FALHA;
    }
}

void TUNome::testarInvalido()
{
    for (int i = 0; i < INVALIDO.size(); i++)
    {
        testeUniInv(INVALIDO[i]);
    }
}

int TUNome::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
