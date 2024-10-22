#ifndef DURACAO_H
#define DURACAO_H

//! Classe duração
/*! 232002771 - implementação
*/

class duracao{
    private:
        static const int LIMITE = 360;
        int dias;
        bool validar(int);

    protected:

    public:

        duracao(int);
        bool validacao();
        bool setDias(int);
        int getDias()const;
};

#endif // DURACAO_H
