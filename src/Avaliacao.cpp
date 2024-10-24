#include "Avaliacao.h"

bool Avaliacao::validar(int valor)
{
    if (valor<0 or valor>5)
    {
        return false;
    }
    return true;
}

bool Avaliacao::setValor(int valor)
{
    if(!Avaliacao::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}
