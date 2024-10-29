#include "Dominios/Dinheiro.hpp"
#include <algorithm>
#include <string>

bool Dinheiro::setValor(int valor)
{
    if (!Dinheiro::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}

bool Dinheiro::validar(int valor)
{
    if (MINIMO <= valor && valor <= MAXIMO)
    {
        return true;
    }
    return false;
}

std::string Dinheiro::getValorFormatado() const
{
    if (this->valor < 100)
    {
        return "0," + std::to_string(this->valor);
    }
    std::string numero = std::to_string(this->valor);
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
