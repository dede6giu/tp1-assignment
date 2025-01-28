#include "MFConta.hpp"
#include <iostream>

MIFConta ::criar() override{
        if (!ibConta) {
            std::cerr << "Erro: IBConta não foi configurada.\n";
            return false;
        }

        std::cout << "Iniciando o processo de criação de conta...\n";

        std::string nome, senha;
        std::cout << "Digite o nome da conta: ";
        std::cin >> nome;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        if (ibConta->adicionarConta(nome, senha)) {
            std::cout << "Conta criada com sucesso!\n";
            return true;
        } else {
            std::cerr << "Erro ao criar a conta.\n";
            return false;
        }
    }
MIFConta::setCntrIBConta(IBConta* ibContaRef) override{
        ibConta = ibContaRef;
        std::cout << "Referência ao IBConta configurada com sucesso.\n";
    }


MIFConta :: ~MIFConta() override {
        std::cout << "Destrutor de IFContaImpl chamado.\n";
    }

