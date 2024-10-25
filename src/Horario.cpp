#include "Horario.h"
#include <string>

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
