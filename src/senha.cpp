#include "dominios.hpp"
#include <set>
#include <algorithm>

bool Senha::validar(string senha){
    if (senha.size() != 5){
        return false;
    }
    for (char c: senha){
        if(!isdigit(c)){
        return false;
        }
        }
    set<char> numeros(senha.begin, senha.end)
    if (numeros.size() != senha.size()){
        return false;
    }
    if (is_sorted(senha.begin, senha.end)){
        return false;
    }
    if (is_sorted(senha).begin, senha.end){
        return false
    }
    }


    return true;
}
bool Senha::setValor(int senha) {
    if (!validar(int)){
        return false;
    }
    this->senha = senha;
    return true;
}
