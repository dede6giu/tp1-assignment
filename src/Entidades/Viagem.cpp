#include "Entidades/viagem.hpp"

Viagem:: viagem() {
    avaliacao = Cvaliacao()
    codigo = Codigo()
    nome = Nome()
}

void Atividade::setCodigo(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

void Atividade::setNome(const Nome &novoNome) {
    this->nome = novoNome;
}
void Atividade::setAvaliacao(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}
