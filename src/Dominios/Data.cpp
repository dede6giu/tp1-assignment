#include "Data.h"
#include <string>

bool Data::validar(int dia, int mes, int ano)
{
    if (ano < 0 or ano > 99)
    {
        return false;
    }
    if (mes <= 0 or mes > 12)
    {
        return false;
    }
    if (dia <= 0)
    {
        return false;
    }
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            // 31 dias
            if (dia > 31)
            {
                return false;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            // 30 dias
            if (dia > 30)
            {
                return false;
            }
            break;

        case 2:
            // fevereiro
            ano += 2000;
            if ((ano % 4 == 0 and ano % 100 != 0) or ano % 400 == 0) // ano bissexto
            {
                if (dia > 29) {
                    return false;
                }
            }
            else
            {
                if (dia > 28) {
                    return false;
                }
            }
            break;

        default:
            return false;
    }
    return true;
}

bool Data::setValor(int dia, int mes, int ano)
{
    if (!Data::validar(dia, mes, ano))
    {
        return false;
    }
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    return true;
}

std::string Data::getValor() const
{
    std::string resultado = "";
    if (this->dia < 10) resultado += "0";
    resultado += std::to_string(this->dia);
    resultado += "/";
    if (this->mes < 10) resultado += "0";
    resultado += std::to_string(this->mes);
    resultado += "/";
    if (this->ano < 10) resultado += "0";
    resultado += std::to_string(this->ano);
    return resultado;

}
