#include "Dados.hpp"
#include <iostream>
//! Implementar PDCurses ainda
//! Oq fazer quando o usuario escolher gerenciar cada coisa
//! Construtor
Dados::Dados() : cntrIFAtividade(nullptr), cntrIFConta(nullptr),
                 cntrIFDestino(nullptr), cntrIFHospedagem(nullptr),
                 cntrIFViagem(nullptr) {}

//! Implementação do método run
void Dados::run(Conta* conta) {
    // Exemplo de implementação do método run
    std::cout << "Bem-vindo, " << endl;
    std::cout << "Escolha uma opção:\n";
    std::cout << "1 - Gerenciar Atividades\n";
    std::cout << "2 - Gerenciar Conta\n";
    std::cout << "3 - Gerenciar Destinos\n";
    std::cout << "4 - Gerenciar Hospedagens\n";
    std::cout << "5 - Gerenciar Viagens\n";

    int opcao;
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            if (cntrIFAtividade) {
                cntrIFAtividade->gerenciarAtividades(conta);
            } else {
                std::cout << "Serviço de Atividades não disponível.\n";
            }
            break;
        case 2:
            if (cntrIFConta) {
                cntrIFConta->gerenciarConta(conta);
            } else {
                std::cout << "Serviço de Conta não disponível.\n";
            }
            break;
        case 3:
            if (cntrIFDestino) {
                cntrIFDestino->gerenciarDestinos(conta);
            } else {
                std::cout << "Serviço de Destinos não disponível.\n";
            }
            break;
        case 4:
            if (cntrIFHospedagem) {
                cntrIFHospedagem->gerenciarHospedagens(conta);
            } else {
                std::cout << "Serviço de Hospedagens não disponível.\n";
            }
            break;
        case 5:
            if (cntrIFViagem) {
                cntrIFViagem->gerenciarViagens(conta);
            } else {
                std::cout << "Serviço de Viagens não disponível.\n";
            }
            break;
        default:
            std::cout << "Opção inválida!\n";
            break;
    }
}

//! Implementação do método setCntrIFAtividade
/*!
    Define a referência para a IFAtividade.
    @param cntrIFAtividade Ponteiro para a IFAtividade.
*/
void Dados::setCntrIFAtividade(IFAtividade* cntrIFAtividade) {
    this->cntrIFAtividade = cntrIFAtividade;
}

//! Implementação do método setCntrIFConta
/*!
    Define a referência para a IFConta.
    @param cntrIFConta Ponteiro para a IFConta.
*/
void Dados::setCntrIFConta(IFConta* cntrIFConta) {
    this->cntrIFConta = cntrIFConta;
}

//! Implementação do método setCntrIFDestino
/*!
    Define a referência para a IFDestino.
    @param cntrIFDestino Ponteiro para a IFDestino.
*/
void Dados::setCntrIFDestino(IFDestino* cntrIFDestino) {
    this->cntrIFDestino = cntrIFDestino;
}

//! Implementação do método setCntrIFHospedagem
/*!
    Define a referência para a IFHospedagem.
    @param cntrIFHospedagem Ponteiro para a IFHospedagem.
*/
void Dados::setCntrIFHospedagem(IFHospedagem* cntrIFHospedagem) {
    this->cntrIFHospedagem = cntrIFHospedagem;
}

//! Implementação do método setCntrIFViagem
/*!
    Define a referência para a IFViagem.
    @param cntrIFViagem Ponteiro para a IFViagem.
*/
void Dados::setCntrIFViagem(IFViagem* cntrIFViagem) {
    this->cntrIFViagem = cntrIFViagem;
}

//! Destrutor
Dados::~Dados() {
    // Limpa as referências
    cntrIFAtividade = nullptr;
    cntrIFConta = nullptr;
    cntrIFDestino = nullptr;
    cntrIFHospedagem = nullptr;
    cntrIFViagem = nullptr;
}
