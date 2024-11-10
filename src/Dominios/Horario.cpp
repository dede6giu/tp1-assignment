#include "Dominios/Horario.hpp"
#include <string>

Horario::Horario()
{
    horas = 0;
    minutos = 0;
}

Horario::Horario(int hh, int mm)
{
    if (!Horario::validarHoras(hh))
    {
        return;
    }
    if (!Horario::validarHoras(mm))
    {
        return;
    }
    horas = hh;
    minutos = mm;
}

bool Horario::validarHoras(int valor)
{
    if (valor < 0 or valor >= 24)
    {
        return false;
    }
    return true;
}

bool Horario::validarMinutos(int valor)
{
    if (valor < 0 or valor >= 60)
    {
        return false;
    }
    return true;
}

bool Horario::setValorHoras(int valor)
{
    if (!Horario::validarHoras(valor))
    {
        return false;
    }
    this->horas = valor;
    return true;
}

bool Horario::setValorMinutos(int valor)
{
    if (!Horario::validarMinutos(valor))
    {
        return false;
    }
    this->minutos = valor;
    return true;
}

bool Horario::setValor(int horas, int minutos)
{
    if (Horario::validarHoras(horas))
    {
        if (Horario::validarMinutos(minutos))
        {
            this->horas = horas;
            this->minutos = minutos;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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
