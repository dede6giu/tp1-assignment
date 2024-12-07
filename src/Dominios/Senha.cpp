#include "Dominios/Senha.hpp"
#include <set>
#include <string>
#include <algorithm>
#include <stdexcept>

Senha::Senha()
{
    senha;
}

Senha::Senha(std::string valor)
{
    Senha::validar(valor);
    senha = valor;
}

void Senha::validar(std::string valor){
    if(valor.size() != 5){
        throw std::length_error("Tamanho da Senha deve ser exatamente 5");
    }
    for (char c: valor){
        if(!isdigit(c)){
            throw std::invalid_argument("Senha deve ser composta apenas por digitos");
        }
    }

    std::set<char> numeros(valor.begin(), valor.end());

    if(numeros.size() != valor.size()){
        throw std::invalid_argument("Senha nao pode possuir digitos repetidos");
    }

    if(std::is_sorted(valor.begin(), valor.end())){
        throw std::invalid_argument("Senha nao pode ser composta por digitos crescentes");
    }

    reverse(valor.begin(), valor.end());

    if (std::is_sorted(valor.begin(), valor.end())){
        throw std::invalid_argument("Senha nao pode ser composta por digitos decrescentes");
    }
}

void Senha::setValor(std::string valor) {
    validar(valor);
    this->senha = valor;
}
