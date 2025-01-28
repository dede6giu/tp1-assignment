#ifndef IFAUTENTICACAO_HPP_INCLUDED
#define IFAUTENTICACAO_HPP_INCLUDED

#include <string>
#include <iostream>
#include "../Entidades/Conta.hpp"
#include "IAutenticacao.hpp"

// Classe concreta que implementa a interface IAutenticacao
class Autenticacao : public IAutenticacao {
private:
    IAutenticacao* referenciaIAutenticacao;

public:

    bool autenticar(Conta* conta) override {
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

        // Simulacao de validacao no "banco de dados"
        if (codigo == "1234" && senha == "senhaSegura") {
            std::cout << "Usuário autenticado com sucesso.\n";
            return true;
        } else {
            std::cerr << "Falha na autenticação. Código ou senha incorretos.\n";
            return false;
        }
    }

    void setCntrIAutenticacao(IAutenticacao* referencia) override {
        if (referencia == nullptr) {
            std::cerr << "Referência de IAutenticacao inválida.\n";
            return;
        }
        referenciaIAutenticacao = referencia;
        std::cout << "Referência de IAutenticacao configurada com sucesso.\n";
    }

    ~Autenticacao() override {
        std::cout << "Destrutor de Autenticacao chamado.\n";
    }
};

#endif // IFAUTENTICACAO_HPP_INCLUDED

