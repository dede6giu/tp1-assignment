#include "Dominios/Senha.hpp"
#include <set>
#include <string>
#include <algorithm>

bool Senha::validar(std::string senha){
    if(senha.size() != 5){
        return false;
    }
    for (char c: senha){
        if(!isdigit(c)){
            return false;
        }
    }

    std::set<char> numeros(senha.begin(), senha.end());

    if(numeros.size() != senha.size()){
        return false;
    }

    if(std::is_sorted(senha.begin(), senha.end())){
        return false;
    }

    reverse(senha.begin(), senha.end());

    if (std::is_sorted(senha.begin(), senha.end())){
        return false;
    }

    return true;
}
bool Senha::setValor(std::string senha) {
    if(!validar(senha)){
        return false;
    }
    this->senha = senha;
    return true;
}
