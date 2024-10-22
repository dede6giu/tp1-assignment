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
        static const int LIMITE = 360;
        int dias;
        bool validar(int);

    public:
        duracao(int);
        bool validacao();
        bool setDias(int);
        int getDias()const;
};

#endif // DURACAO_H
