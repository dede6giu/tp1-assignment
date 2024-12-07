#include "Dominios/Nome.hpp"
#include <string>
#include <stdexcept>

Nome::Nome()
{
    nome;
}

Nome::Nome(std::string valor)
{
    Nome::setValor(valor);
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
        throw std::length_error("Tamanho de Nome deve ser entre 1 a 30 inclusivo");
    }
}
