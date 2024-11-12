#include "Entidades/Viagem.hpp"

#include "./Dominios/Avaliacao.hpp"
#include "./Dominios/Codigo.hpp"
#include "./Dominios/Nome.hpp"

Viagem::Viagem() {
    avaliacao = Avaliacao()
    codigo = Codigo()
    nome = Nome()
}

void Atividade::setValor(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

void Atividade::setValor(const Nome &novoNome) {
    this->nome = novoNome;
}
void Atividade::setValor(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}
