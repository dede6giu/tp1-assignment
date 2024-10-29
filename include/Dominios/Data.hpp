#ifndef DATA_H
#define DATA_H

#include <string>

//! Classe Data
/*!
    Classe Data, formato DD/MM/AA, salvo como tr&ecirc;s inteiros,
    tal que 01 <= DD <= 31, 01 <= MM <= 12 e 00 <= AA <= 99, seguindo as
    devidas quantidades de dias no m&ecirc;s.\n

    232013031 - implementa&ccdeil;&atilde;o
*/

class Data
{
    private:
        int dia;
        int mes;
        int ano;
        bool validar(int, int, int);

    public:
        int getDia() const;
        int getMes() const;
        int getAno() const;
        bool setValor(int, int, int);
        std::string getValor() const;
};

inline int Data::getDia() const
{
    return this->dia;
}

inline int Data::getMes() const
{
    return this->mes;
}

inline int Data::getAno() const
{
    return this->ano;
}

#endif // DATA_H
