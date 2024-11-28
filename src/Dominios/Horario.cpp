#include "Dominios/Horario.hpp"
#include <string>
#include <stdexcept>

Horario::Horario()
{
    horas = 0;
    minutos = 0;
}

Horario::Horario(int hh, int mm)
{
    Horario::setValor(hh, mm);
}

void Horario::validarHoras(int valor)
{
    if (valor < 0 or valor >= 24)
    {
        throw std::invalid_argument("Horas deve estar entre 00 e 23 inclusivo");
    }
}

void Horario::validarMinutos(int valor)
{
    if (valor < 0 or valor >= 60)
    {
        throw std::invalid_argument("Minutos deve estar entre 00 e 59 inclusivo");
    }
}

void Horario::setValorHoras(int valor)
{
    Horario::validarHoras(valor);
    this->horas = valor;
}

void Horario::setValorMinutos(int valor)
{
    Horario::validarMinutos(valor);
    this->minutos = valor;
}

void Horario::setValor(int horas, int minutos)
{
    Horario::validarHoras(horas);
    Horario::validarMinutos(minutos);
    this->horas = horas;
    this->minutos = minutos;
}

std::string Horario::getValor() const
{
    std::string resultado = "";
    if (this->horas < 10) resultado += "0";
    resultado += std::to_string(this->horas);
    resultado += ":";
    if (this->minutos < 10) resultado += "0";
    resultado += std::to_string(this->minutos);
    return resultado;
}
