#ifndef AUTENTICACAO_HPP_INCLUDED
#define AUTENTICACAO_HPP_INCLUDED

#include "IBAutenticacao.hpp"
#include <unordered_map>
#include <string>

// Classe que implementa a interface IBAutenticacao
class Autenticacao : public IBAutenticacao {
private:
    // Simula um banco de dados {codigo: senha}
    std::unordered_map<std::string, std::string> bancoDeDados;

public:
    Autenticacao();

    bool autenticar(Conta* conta) override;

    ~Autenticacao() override;
};

#endif


