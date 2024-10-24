#ifndef HORARIO_H
#define HORARIO_H

#include <string>

//! Classe Horario
/*!
  Classe Horario, string de 5 caracteres composta por "HH:mm"\n
  232013031 - implementa&ccdeil;&atilde;o
*/

class Horario
{
    private:
        int horas = 0;
        int minutos = 0;
        bool validarHoras(int);
        bool validarMinutos(int);

    public:
        bool setValor(int, int);
        bool setValorHoras(int);
        bool setValorMinutos(int);
        std::string getValor() const;
        int getValorHoras() const;
        int getValorMinutos() const;
};

inline std::string Horario::getValor() const
{
    std::string resultado = "";
    if (this->horas < 10) resultado += "0";
    resultado += std::to_string(this->horas);
    resultado += ":";
    if (this->minutos < 10) resultado += "0";
    resultado += std::to_string(this->minutos);
    return resultado;
}

inline int Horario::getValorHoras() const
{
    return this->horas;
}

inline int Horario::getValorMinutos() const
{
    return this->minutos;
}

#endif // HORARIO_H
