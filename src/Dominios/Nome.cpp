#include "Dominios/Nome.hpp"
#include <string>
#include <stdexcept>

Nome::Nome()
{
    nome = "";
}

Nome::Nome(std::string valor)
{
    validar(valor);
    this->nome = valor;
}

void Nome::setValor(std::string valor)
{
    validar(valor);
    this->nome = valor;
}

void Nome::validar(std::string valor)
{
    int len = valor.length();
    if (len > this->MAXLENGTH or len <= 0)
    {
        throw std::invalid_argument("Tamanho do Nome deve conter no minimo 1 caracter e no maximo 30 caracteres");
    }
}
