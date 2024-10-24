#ifndef AVALIACAO_H
#define AVALIACAO_H

//! Classe Avaliacao
/*!
Classe Avaliacao, inteiro v&aacute;lido entre 0 e 5 inclusivo \n
232029274 - implementacao
*/

class Avaliacao
{
    private:
            int valor;
            bool validar(int);
    public:
            bool setValor(int);
            int getValor() const;
};

inline int Avaliacao::getValor() const
{
        return valor;
}

#endif // AVALIACAO_H
