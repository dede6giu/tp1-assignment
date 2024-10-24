#ifndef DINHEIRO_H
#define DINHEIRO_H

//! Classe Dinheiro
/*!
    Classe Dinheiro, float de 0,00 a 200.000,00
    232013031 - implementa&ccdeil;&atilde;o
*/
class Dinheiro
{
    private:
        float valor = 0;
        bool validar(float);

    public:
        float const MINIMO = 0.0;
        float const MAXIMO = 200000.0;
        bool setValor(float);
        float getValor() const;
};

inline float Dinheiro::getValor() const
{
    return valor;
}

#endif // DINHEIRO_H
