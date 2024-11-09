#include "atividade.hpp"

//! entidade Atividade
/*!
    232029274 - implementacao entidade Atividade
*/

void Atividade::setCodigo(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

Codigo Atividade::getCodigo() const {
    return codigo;
}

void Atividade::setNome(const Nome &novoNome) {
    this->nome = novoNome;
}

Nome Atividade::getNome() const {
    return nome;
}

void Atividade::setData(const Data &novaData) {
    this->data = novaData;
}

Data Atividade::getData() const {
    return data;
}

void Atividade::setHorario(const Horario &novoHorario) {
    this->horario = novoHorario;
}

Horario Atividade::getHorario() const {
    return horario;
}

void Atividade::setDuracao(const Duracao &novaDuracao) {
    this->duracao = novaDuracao;
}

Duracao Atividade::getDuracao() const {
    return duracao;
}

void Atividade::setPreco(const Dinheiro &novoPreco) {
    this->preco = novoPreco;
}

Dinheiro Atividade::getPreco() const {
    return preco;
}

void Atividade::setAvaliacao(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}

Avaliacao Atividade::getAvaliacao() const {
    return avaliacao;
}

