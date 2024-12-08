#include "Dominios/Codigo.hpp"
#include <string>
#include <stdexcept>

Codigo::Codigo()
{
    codigo;
}

Codigo::Codigo(std::string valor)
{
    setValor(valor);
}

void Codigo::setValor(std::string valor)
{
    validar(valor);
    this->codigo = valor;
}

void Codigo::validar(std::string valor)
{
    if (valor.length() != this->CODELENGTH)
    {
        throw std::length_error("Tamanho do Codigo deve ser exatamente 6");
    }
    for (int i = 0; i < this->CODELENGTH; i++)
    {
        if (!isalnum(valor[i]))
        {
            throw std::invalid_argument("Codigo deve ser composto apenas por letras e digitos");
        }
    }
}
