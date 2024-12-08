#include "Dominios/Horario.hpp"
#include <stdexcept>

Horario::Horario()
{
    horas;
    minutos;
}

Horario::Horario(std::string horas)
{
    Horario::setValor(horas);
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

void Horario::validar(std::string dataStr)
{
    if (dataStr.size() > 5) {
        throw std::length_error("Tamanho do Horario deve ser exatamente 5");
    }
    if (dataStr[2] != ':') {
        throw std::invalid_argument("As horas e os minutos deve ser separados por ':'");
    }

    for (int i = 0; i < 5; i++) // essa condição irá cortar tudo o que vier depois do 6 caractere
    {
        if (i == 2) continue;
        if (!isdigit(dataStr[i]))
        {
            throw std::invalid_argument("Horario deve ser composto por digitos separados por ':', no formato hh:mm");
        }
    }
}

void Horario::setValor(std::string dataStr)
{
    validar(dataStr);
    int hh, mm;
    std::string aux = "";
    aux += dataStr[0]; aux += dataStr[1];
    hh = stoi(aux); aux = "";
    aux += dataStr[3]; aux += dataStr[4];
    mm = stoi(aux); aux = "";
    Horario::setValor(hh, mm);
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
