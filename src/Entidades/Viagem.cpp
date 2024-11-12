#include "Entidades/Viagem.hpp"

#include "Dominios/Avaliacao.hpp"
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"

Viagem::Viagem() {
    avaliacao = Avaliacao();
    codigo = Codigo();
    nome = Nome();
}

void Viagem::setValor(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

void Viagem::setValor(const Nome &novoNome) {
    this->nome = novoNome;
}
void Viagem::setValor(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}
