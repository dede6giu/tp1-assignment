#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

//! Domínio Senha
/*!
    Domínio Senha \n
    232006028 - implementação \n
    232002771 - implementação por string \n
    232013031 - construtores
*/

class Senha
{
    private:
        std::string senha;
        void validar(std::string);
    public:
        Senha();
        Senha(std::string);
        void setValor(std::string);
        std::string getValor() const;
};

inline std::string Senha::getValor() const{
    return senha;
}

#endif // SENHA_HPP_INCLUDED
