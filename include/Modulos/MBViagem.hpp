#ifndef MBVIAGEM_HPP_INCLUDED
#define MBVIAGEM_HPP_INCLUDED

#include <string>
#include <iostream>
#include "../../include/Dominios/Avaliacao.hpp"
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"

class Viagem {
private:
    Avaliacao avaliacao;
    Codigo codigo;
    Nome nome;

public:
    // Construtor vazio
    Viagem();

    // Construtor parametrizado
    Viagem(const Avaliacao&, const Codigo&, const Nome&);

    void setValor(const Avaliacao&);
    void setValor(const Codigo&);
    void setValor(const Nome&);

    int getValorAvaliacao() const;
    std::string getValorCodigo() const;
    std::string getValorNome() const;

    ~Viagem();
};

#endif

