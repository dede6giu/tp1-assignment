#include "Dominios/Duracao.hpp"
#include <stdexcept>

Duracao::Duracao()
{
    duracao = 0;
}

Duracao::Duracao(int valor)
{
    validar(valor);
    duracao = valor;
}

void Duracao::setValor(int valor)
{
    validar(valor);
    this->duracao = valor;
}

void Duracao::validar(int valor)
{
    if (!(0 <= valor && valor <= MAXIMO))
    {
        throw std::invalid_argument("A Duracao deve ser um inteiro entre 0 e 360");
    }
}
