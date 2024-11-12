#include "Dominios/Duracao.hpp"

Duracao::Duracao()
{
    duracao = 0;
}

Duracao::Duracao(int valor)
{
    if (!Duracao::validar(valor))
    {
        return;
    }
    duracao = valor;
}

bool Duracao::setValor(int valor)
{
    if (!Duracao::validar(valor))
    {
        return false;
    }
    this->duracao = valor;
    return true;
}

bool Duracao::validar(int valor)
{
    if (0 <= valor && valor <= MAXIMO)
    {
        return true;
    }
    return false;
}
