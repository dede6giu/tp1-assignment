#include "Dominios/Dinheiro.hpp"
#include <algorithm>
#include <string>
#include <stdexcept>

Dinheiro::Dinheiro()
{
    dinheiro = 0;
}

Dinheiro::Dinheiro(int valor)
{
    validar(valor);
    dinheiro = valor;
}

void Dinheiro::setValor(int valor)
{
    validar(valor);
    this->dinheiro = valor;
}

void Dinheiro::validar(int valor)
{
    if (!(MINIMO <= valor && valor <= MAXIMO))
    {
        throw std::invalid_argument("O Dinheiro deve ser um real entre 0,00 e 200.000,00");
    }
}

std::string Dinheiro::getValorFormatado() const
{
    if (this->dinheiro < 100)
    {
        return "0," + std::to_string(this->dinheiro);
    }
    std::string numero = std::to_string(this->dinheiro);
    int i = numero.length() - 1;
    std::string resultado = "";
    resultado += numero[i]; i--;
    resultado += numero[i];
    resultado += ",";
    int cnt = 0;
    while (i--)
    {
        if (cnt == 3)
        {
            cnt = 0;
            resultado += ".";
        }
        cnt++;
        resultado += numero[i];
    }
    std::reverse(resultado.begin(), resultado.end());
    return resultado;
}
