#ifndef SENHA_H
#define SENHA_H

#include <string>

//! Domínio Senha
/*!
    Domínio Senha \n
    232006028 - implementação \n
    232002771 - implementação por string
*/

class Senha {
    private:
        std::string senha;
        bool validar(std::string);
    public:
        bool setValor(std::string);
        std::string getValor() const;
};

inline std::string Senha::getValor() const{
    return senha;
}

#endif // SENHA_H
