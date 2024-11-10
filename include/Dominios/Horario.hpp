#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

#include <string>

//! Classe Horario
/*!
  Classe Horario, string de 5 caracteres composta por "HH:mm", impressa em formato de 24h. Internamente salva como dois inteiros, um para horas e outro para minutos.\n
  232013031 - implementa&ccdeil;&atilde;o, construtores
*/

class Horario
{
    private:
        int horas;
        int minutos;
        bool validarHoras(int);
        bool validarMinutos(int);

    public:
        Horario();
        Horario(int, int);

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
