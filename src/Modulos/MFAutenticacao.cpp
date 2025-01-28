#include "Autenticacao.hpp"

// Implementa��o do m�todo de auteticacao
bool Autenticacao::autenticar(Conta* conta) {
    if (conta == nullptr) {
        std::cerr << "Conta inv�lida.\n";
        return false;
    }

    std::string codigo = conta->getCodigo();
    std::string senha = conta->getSenha();

    if (codigo.empty() || senha.empty()) {
        std::cerr << "C�digo ou senha est�o vazios.\n";
        return false;
    }

    // Simula��o de valida��o no "banco de dados"
    if (codigo == "1234" && senha == "senhaSegura") {
        std::cout << "Usu�rio autenticado com sucesso.\n";
        return true;
    } else {
        std::cerr << "Falha na autentica��o. C�digo ou senha incorretos.\n";
        return false;
    }
}

void Autenticacao::setCntrIAutenticacao(IAutenticacao* referencia) {
    if (referencia == nullptr) {
        std::cerr << "Refer�ncia de IAutenticacao inv�lida.\n";
        return;
    }

    referenciaIAutenticacao = referencia;
    std::cout << "Refer�ncia de IAutenticacao configurada com sucesso.\n";
}

Autenticacao::~Autenticacao() {
    std::cout << "Destrutor de Autenticacao chamado.\n";
}

