#include "Dominios/Nome.hpp"
#include <string>

Nome::Nome()
{
    nome = "";
}

Nome::Nome(std::string valor)
{
    if (!Nome::validar(valor))
    {
        return;
    }
    nome = valor;
}

bool Nome::setValor(std::string valor)
{
    if (!Nome::validar(valor))
    {
        return false;
    }
    this->nome = valor;
    return true;
}

bool Nome::validar(std::string valor)
{
    int len = valor.length();
    if (len > this->MAXLENGTH or len <= 0)
    {
        return false;
    }
    return true;
}
