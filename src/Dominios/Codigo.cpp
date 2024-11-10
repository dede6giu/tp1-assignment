#include "Dominios/Codigo.hpp"
#include <string>

Codigo::Codigo() {
    codigo = "";
}

Codigo::Codigo(std::string valor) {
    if (!validar(valor)) {
        return;
    }
    codigo = codigo;
}

bool Codigo::setValor(std::string valor)
{
    if (!Codigo::validar(valor))
    {
        return false;
    }
    this->codigo = valor;
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
