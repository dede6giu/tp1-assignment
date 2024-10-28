#ifndef SENHA_H
#define SENHA_H

//! Domínio Senha
/*!
    Domínio Senha \n
    matricula - implementação
*/

class Senha {
    private:
        int senha;
        bool validar(Tipo);
    public:
        bool setValor(int);
        int getValor() const;
};

inline int Senha::getValor() const{
    return senha;
}

#endif // SENHA_H
