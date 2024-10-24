#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED

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

#endif // AVALIACAO_HPP_INCLUDED
