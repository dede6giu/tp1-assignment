#include "MBViagem.hpp"

// Construtor vazio: inicializa valores padrões
Viagem::Viagem() {
    avaliacao = Avaliacao();
    codigo = Codigo();
    nome = Nome();
}

// Construtor parametrizado: inicializa com valores fornecidos
Viagem::Viagem(const Avaliacao& avaliacaoNovo, const Codigo& codigoNovo, const Nome& nomeNovo) {
    avaliacao = avaliacaoNovo;
    codigo = codigoNovo;
    nome = nomeNovo;
}

void Viagem::setValor(const Avaliacao& novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}

void Viagem::setValor(const Codigo& novoCodigo) {
    this->codigo = novoCodigo;
}

void Viagem::setValor(const Nome& novoNome) {
    this->nome = novoNome;
}

int Viagem::getValorAvaliacao() const {
    return this->avaliacao.getValor();
}

std::string Viagem::getValorCodigo() const {
    return this->codigo.getValor();
}

std::string Viagem::getValorNome() const {
    return this->nome.getValor();
}

Viagem::~Viagem() {
    std::cout << "Destrutor de Viagem chamado.\n";
}

