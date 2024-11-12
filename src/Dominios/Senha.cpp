#include "Dominios/Senha.hpp"
#include <set>
#include <string>
#include <algorithm>

Senha::Senha()
{
    senha = "";
}

Senha::Senha(std::string valor)
{
    if (!Senha::validar(valor))
    {
        return;
    }
    senha = valor;
}

bool Senha::validar(std::string valor){
    if(valor.size() != 5){
        return false;
    }
    for (char c: valor){
        if(!isdigit(c)){
            return false;
        }
    }

    std::set<char> numeros(valor.begin(), valor.end());

    if(numeros.size() != valor.size()){
        return false;
    }

    if(std::is_sorted(valor.begin(), valor.end())){
        return false;
    }

    reverse(valor.begin(), valor.end());

    if (std::is_sorted(valor.begin(), valor.end())){
        return false;
    }

    return true;
}

bool Senha::setValor(std::string valor) {
    if(!validar(valor)){
        return false;
    }
    this->senha = valor;
    return true;
}
