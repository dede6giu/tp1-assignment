#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

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

#endif
