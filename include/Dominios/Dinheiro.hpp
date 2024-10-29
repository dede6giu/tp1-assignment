#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

#include <string>

//! Classe Dinheiro
/*!
    Classe Dinheiro, int de 0 a 20000000, implementado como centavos\n
    232002771 - implementa&ccdeil;&atilde;o\n
    232013031 - altera&ccedil;&otilde;es na implementa&ccdeil;&atilde;o
*/
class Dinheiro
{
    private:
        int valor;
        bool validar(int);

    public:
        int const MINIMO = 0;
        int const MAXIMO = 20000000;
        bool setValor(int);
        int getValor() const;
        std::string getValorFormatado() const;
};

inline int Dinheiro::getValor() const
{
    return valor;
}

#endif // DINHEIRO_HPP_INCLUDED
