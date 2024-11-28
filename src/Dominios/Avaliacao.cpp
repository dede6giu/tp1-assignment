#include "Dominios/Avaliacao.hpp"
#include <stdexcept>

Avaliacao::Avaliacao()
{
    avaliacao = 0;
}

Avaliacao::Avaliacao(int valor)
{
    Avaliacao::setValor(valor);
}

void Avaliacao::validar(int valor)
{
    if (valor < 0 or valor > 5)
    {
        throw std::invalid_argument("Valor deve ser um inteiro entre 0 e 5 inclusivo");
    }
}

void Avaliacao::setValor(int valor)
{
    Avaliacao::validar(valor);
    this->avaliacao = valor;
}
