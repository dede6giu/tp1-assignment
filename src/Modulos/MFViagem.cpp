#include "Viagem.hpp"

void Viagem::run(Conta* conta) {
    if (conta == nullptr) {
        std::cerr << "Conta inválida. Não é possível realizar operações de Viagem.\n";
        return;
    }

    int escolha;
    std::cout << "Escolha uma operação para realizar:\n";
    std::cout << "1 - Criar Viagem\n";
    std::cout << "2 - Excluir Viagem\n";
    std::cout << "3 - Atualizar Viagem\n";
    std::cout << "4 - Consultar Viagem\n";
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            std::cout << "Criando Viagem...\n";
            referenciaIFViagem->criarViagem(conta);
            break;
        case 2:
            std::cout << "Excluindo Viagem...\n";
            referenciaIFViagem->excluirViagem(conta);
            break;
        case 3:
            std::cout << "Atualizando Viagem...\n";
            referenciaIFViagem->atualizarViagem(conta);
            break;
        case 4:
            std::cout << "Consultando Viagem...\n";
            referenciaIFViagem->consultarViagem(conta);
            break;
        default:
            std::cerr << "Opção inválida.\n";
            break;
    }
}

void Viagem::setCntrIBViagem(IBViagem* referencia) {
    if (referencia == nullptr) {
        std::cerr << "Referência de IBViagem inválida.\n";
        return;
    }

    referenciaIFViagem = referencia;
    std::cout << "Referência de IBViagem configurada com sucesso.\n";
}

Viagem::~Viagem() {
    std::cout << "Destrutor de Viagem chamado.\n";
}
