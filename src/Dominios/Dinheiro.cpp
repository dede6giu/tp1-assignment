#include "Dominios/Dinheiro.hpp"
#include <algorithm>
#include <string>

Dinheiro::Dinheiro()
{
    dinheiro = 0;
}

Dinheiro::Dinheiro(int valor)
{
    if (!Dinheiro::validar(valor))
    {
        return;
    }
    dinheiro = valor;
}

bool Dinheiro::setValor(int valor)
{
    if (!Dinheiro::validar(valor))
    {
        return false;
    }
    this->dinheiro = valor;
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
