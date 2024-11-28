#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

//! Classe Data
/*!
    Classe Data, formato DD/MM/AA, salvo como tr&ecirc;s inteiros,
    tal que 01 <= DD <= 31, 01 <= MM <= 12 e 00 <= AA <= 99, seguindo as
    devidas quantidades de dias no m&ecirc;s.\n

    232013031 - implementa&ccdeil;&atilde;o, construtores
*/

class Data
{
    private:
        int dia;
        int mes;
        int ano;
        void validar(int, int, int);

    public:
        Data();
        Data(int, int, int);

        int getDia() const;
        int getMes() const;
        int getAno() const;
        void setValor(int, int, int);
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

#endif // DATA_HPP_INCLUDED
