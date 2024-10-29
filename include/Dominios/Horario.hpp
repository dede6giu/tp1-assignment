#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

#include <string>

//! Classe Horario
/*!
  Classe Horario, string de 5 caracteres composta por "HH:mm"\n
  232013031 - implementa&ccdeil;&atilde;o
*/

class Horario
{
    private:
        int horas;
        int minutos;
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

inline int Horario::getValorHoras() const
{
    return this->horas;
}

inline int Horario::getValorMinutos() const
{
    return this->minutos;
}

#endif // HORARIO_HPP_INCLUDED
