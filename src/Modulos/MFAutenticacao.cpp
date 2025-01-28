#include "Autenticacao.hpp"

// Implementação do método de auteticacao
bool Autenticacao::autenticar(Conta* conta) {
    if (conta == nullptr) {
        std::cerr << "Conta inválida.\n";
        return false;
    }

    std::string codigo = conta->getCodigo();
    std::string senha = conta->getSenha();

    if (codigo.empty() || senha.empty()) {
        std::cerr << "Código ou senha estão vazios.\n";
        return false;
    }

    // Simulação de validação no "banco de dados"
    if (codigo == "1234" && senha == "senhaSegura") {
        std::cout << "Usuário autenticado com sucesso.\n";
        return true;
    } else {
        std::cerr << "Falha na autenticação. Código ou senha incorretos.\n";
        return false;
    }
}

void Autenticacao::setCntrIAutenticacao(IAutenticacao* referencia) {
    if (referencia == nullptr) {
        std::cerr << "Referência de IAutenticacao inválida.\n";
        return;
    }

    referenciaIAutenticacao = referencia;
    std::cout << "Referência de IAutenticacao configurada com sucesso.\n";
}

Autenticacao::~Autenticacao() {
    std::cout << "Destrutor de Autenticacao chamado.\n";
}

