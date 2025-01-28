#include "Autenticacao.hpp"
#include <iostream>

// Construtor: inicializa algumas contas fict�cias no "banco de dados"
Autenticacao::Autenticacao() {
    bancoDeDados["1234"] = "senha123";
    bancoDeDados["5678"] = "segredo";
}


bool Autenticacao::autenticar(Conta* conta) {
    if (conta == nullptr) {
        std::cerr << "Erro: Conta inv�lida.\n";
        return false;
    }

    std::string codigo = conta->getCodigo();
    std::string senha = conta->getSenha();

    // Verifica se o c�digo existe no "banco de dados"
    auto it = bancoDeDados.find(codigo);
    if (it == bancoDeDados.end()) {
        std::cerr << "Erro: C�digo n�o encontrado.\n";
        return false;
    }


    if (it->second == senha) {
        std::cout << "Autentica��o bem-sucedida!\n";
        return true;
    } else {
        std::cerr << "Erro: Senha incorreta.\n";
        return false;
    }
}

Autenticacao::~Autenticacao() {
    std::cout << "Destrutor de Autenticacao chamado.\n";
}


