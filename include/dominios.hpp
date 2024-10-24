#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

//! Classe Avaliacao
/*!
232029274 - implementacao
*/

class Avaliacao {
    private:
            int valor;
            bool validar(int);
    public:
            bool setValor(int);
            int getValor() const;
};

inline int Avaliacao::getValor() const{
        return valor;
}

#endif // DOMINIOS_HPP_INCLUDED
