#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

#include <string>

//! Classe Horario
/*!
  Classe Horario, string de 5 caracteres composta por "HH:mm", impressa em formato de 24h. Internamente salva como dois inteiros, um para horas e outro para minutos.\n
  232013031 - implementa&ccdeil;&atilde;o, construtores, exce��es\n
  232002520 - implementação
*/

class Horario
{
    private:
        int horas;
        int minutos;
        void validar(std::string);
        void validarHoras(int);
        void validarMinutos(int);

    public:
        Horario();
        Horario(std::string);
        Horario(int, int);

        void setValor(int, int);
        void setValor(std::string);
        void setValorHoras(int);
        void setValorMinutos(int);
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
