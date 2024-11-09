#include "Entidades/Atividade.hpp"
//! entidade Atividade
//! 232029274 - implementacao entidade Atividade


void Atividade::setCodigo(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

void Atividade::setNome(const Nome &novoNome) {
    this->nome = novoNome;
}

void Atividade::setData(const Data &novaData) {
    this->data = novaData;
}

void Atividade::setHorario(const Horario &novoHorario) {
    this->horario = novoHorario;
}

void Atividade::setDuracao(const Duracao &novaDuracao) {
    this->duracao = novaDuracao;
}

void Atividade::setPreco(const Dinheiro &novoPreco) {
    this->preco = novoPreco;
}

void Atividade::setAvaliacao(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}

