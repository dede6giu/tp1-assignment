#ifndef DURACAO_H
#define DURACAO_H

//! Classe Duracao
/*!
  Classe Duracao, inteiro entre 0 e 360
  232002771 - implementa&ccedil;&atilde;o
*/

class Duracao
{
    private:
        int valor = 0;
        bool validar(int);

    public:
        static const int MAXIMO = 360;
        static const int MINIMO = 0;
        bool setValor(int);
        int getValor() const;
};

inline int Duracao::getValor() const
{
    return valor;
}

#endif // DURACAO_H
