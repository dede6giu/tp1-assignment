#include "Duracao.h"

bool Duracao::setValor(int)
{
    if (!Duracao::validar(valor))
    {
            return false;
    }
    this->valor = valor;
    return true;
}

bool Duracao::validar(int)
{
    if (MINIMO <= valor && valor <= MAXIMO)
    {
            return true;
    }
    return false;
}
