#include "Dinheiro.h"

bool Dinheiro::setValor(float valor)
{
    if (!Dinheiro::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}

bool Dinheiro::validar(float valor)
{
    if (MINIMO <= valor && valor <= MAXIMO)
    {
        return true;
    }
    return false;
}
