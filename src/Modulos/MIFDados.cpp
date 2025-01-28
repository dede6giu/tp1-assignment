#include "IFConta.hpp"
#include "../Entidade/Conta.hpp"
#include <iostream>

class MIFConta : public IFConta {
private:
    IBConta* ibConta; // Referência para a interface de banco de dados

public:
    // Construtor
    IFContaImpl() : ibConta(nullptr) {}

    // Implementação do método criar
    bool criar() override {
        if (!ibConta) {
            std::cerr << "Erro: IBConta não foi configurada.\n";
            return false;
        }

        std::cout << "Iniciando o processo de criação de conta...\n";

        // Simulação de entrada de dados
        std::string nome, senha;
        std::cout << "Digite o nome da conta: ";
        std::cin >> nome;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        // Chama o método de criação no banco de dados
        if (ibConta->adicionarConta(nome, senha)) {
            std::cout << "Conta criada com sucesso!\n";
            return true;
        } else {
            std::cerr << "Erro ao criar a conta.\n";
            return false;
        }
    }

    // Implementação do método setCntrIBConta
    void setCntrIBConta(IBConta* ibContaRef) override {
        ibConta = ibContaRef;
        std::cout << "Referência ao IBConta configurada com sucesso.\n";
    }

    // Destrutor
    ~IFContaImpl() override {
        std::cout << "Destrutor de IFContaImpl chamado.\n";
    }
};
