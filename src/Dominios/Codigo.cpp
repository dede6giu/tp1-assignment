#include "Dominios/Codigo.hpp"
#include <string>

bool Codigo::setValor(std::string valor)
{
    if (!Codigo::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}

bool Codigo::validar(std::string valor)
{
    if (valor.length() != this->CODELENGTH)
    {
        return false;
    }
    for (int i = 0; i < this->CODELENGTH; i++)
    {
        if (!isalnum(valor[i]))
        {
            return false;
        }
    }
    return true;
}
