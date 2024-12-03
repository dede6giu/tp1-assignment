#include "Dominios/Data.hpp"
#include <string>
#include <stdexcept>

Data::Data()
{
    dia = 1;
    mes = 1;
    ano = 0;
}

Data::Data(int dd, int mm, int aa)
{
    Data::setValor(dd, mm, aa);
}


void Data::validar(int dia, int mes, int ano)
{
    if (ano < 0 or ano > 99)
    {
        throw std::invalid_argument("Ano deve estar entre 00 e 99 inclusivo");
    }
    if (mes <= 0 or mes > 12)
    {
        throw std::invalid_argument("Mes deve estar entre 01 e 12 inclusivo");
    }
    if (dia <= 0)
    {
        throw std::invalid_argument("Dia deve ser maior que 0");
    }
    switch (mes)
    {
        // 31 dias
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia > 31)
            {
                throw std::invalid_argument("Dia maior que 31 em mes de 31 dias");
            }
            break;

        // 30 dias
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia > 30)
            {
                throw std::invalid_argument("Dia maior que 30 em mes de 30 dias");
            }
            break;

        // fevereiro
        case 2:
            ano += 2000;
            if ((ano % 4 == 0 and ano % 100 != 0) or ano % 400 == 0) // ano bissexto
            {
                if (dia > 29) {
                    throw std::invalid_argument("Dia maior que 29 em fevereiro bissexto");
                }
            }
            else
            {
                if (dia > 28) {
                    throw std::invalid_argument("Dia maior que 28 em fevereiro nao-bissexto");
                }
            }
            break;

        default:
            throw std::invalid_argument("Valor do mes incorreto");
    }
}

void Data::setValor(int dia, int mes, int ano)
{
    Data::validar(dia, mes, ano);
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

void Data::validar(std::string dataStr)
{
    // dataStr tem que ser do formato DD/MM/AA
    if (dataStr[2] != '/' || dataStr[5] != '/')
    {
        throw std::invalid_argument("Data deve estar no formato DD/MM/AA");
    }
    for (int i = 0; i < 8; i++) // essa condição irá cortar tudo o que vier depois do 8 caractere
    {
        if (i == 2 || i == 5) continue;
        if (!isdigit(dataStr[i]))
        {
            throw std::invalid_argument("Data deve ser composta por digitos separados por '/'");
        }
    }
}

void Data::setValor(std::string dataStr)
{
    validar(dataStr);
    int dd, mm, aa;
    std::string aux = "";
    aux += dataStr[0]; aux += dataStr[1];
    dd = stoi(aux); aux = "";
    aux += dataStr[3]; aux += dataStr[4];
    mm = stoi(aux); aux = "";
    aux += dataStr[6]; aux += dataStr[7];
    aa = stoi(aux);
    Data::setValor(dd, mm, aa);
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
