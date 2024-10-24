#include "Duracao.h"

bool Duracao::setValor(int valor)
{
    if (!Duracao::validar(valor))
    {
            return false;
    }
    this->valor = valor;
    return true;
}

bool Duracao::validar(int valor)
{
    if (MINIMO <= valor && valor <= MAXIMO)
    {
            return true;
    }
    return false;
}
