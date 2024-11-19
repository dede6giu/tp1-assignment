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
        int dinheiro;
        bool validar(int);

    public:
        static int const MINIMO = 0;
        static int const MAXIMO = 20000000;

        Dinheiro();
        Dinheiro(int);

        bool setValor(int);
        int getValor() const;
        std::string getValorFormatado() const;
};

inline int Dinheiro::getValor() const
{
    return dinheiro;
}

#endif // DINHEIRO_HPP_INCLUDED
