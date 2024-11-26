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
    Senha::validar(valor)
    senha = valor;
}

void Senha::validar(std::string valor){
    if(valor.size() != 5){
        throw invalid_argument("Argumento invalido.");
    }
    for (char c: valor){
        if(!isdigit(c)){
            throw invalid_argument("Argumento invalido.");
        }
    }

    std::set<char> numeros(valor.begin(), valor.end());

    if(numeros.size() != valor.size()){
        throw invalid_argument("Argumento invalido.");
    }

    if(std::is_sorted(valor.begin(), valor.end())){
        throw invalid_argument("Argumento invalido.");
    }

    reverse(valor.begin(), valor.end());

    if (std::is_sorted(valor.begin(), valor.end())){
        throw invalid_argument("Argumento invalido.");
    }
}

void Senha::setValor(std::string valor) {
    validar(valor)
    this->senha = valor;
}
