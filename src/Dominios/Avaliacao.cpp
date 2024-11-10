#include "Dominios/Avaliacao.hpp"

Avaliacao::Avaliacao()
{
    avaliacao = 0;
}

Avaliacao::Avaliacao(int valor)
{
    if(!Avaliacao::validar(valor))
    {
        return;
    }
    this->avaliacao = valor;
}

bool Avaliacao::validar(int valor)
{
    if (valor < 0 or valor > 5)
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
    this->avaliacao = valor;
    return true;
}
