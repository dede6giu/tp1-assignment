#include "../../include/Dominios/Dinheiro.hpp"
#include <algorithm>
#include <string>
#include <stdexcept>

Dinheiro::Dinheiro()
{
    dinheiro;
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
        throw std::invalid_argument("O Dinheiro deve ser um inteiro entre 0 e 20000000 inclusivo");
    }
}

std::string Dinheiro::getValorFormatado() const
{
    std::string resultado = "";
    std::string numero = std::to_string(this->dinheiro);
    if (this->dinheiro < 100)
    {
        resultado += "0,";
        if (this->dinheiro < 10) resultado += "0";
        return resultado + numero;
    }
    int i = numero.length() - 1;
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
