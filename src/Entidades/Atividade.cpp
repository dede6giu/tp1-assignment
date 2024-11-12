#include "Entidades/Atividade.hpp"

#include "./Dominios/Codigo.hpp"
#include "./Dominios/Nome.hpp"
#include "./Dominios/Data.hpp"
#include "./Dominios/Horario.hpp"
#include "./Dominios/Duracao.hpp"
#include "./Dominios/Dinheiro.hpp"
#include "./Dominios/Avaliacao.hpp"

Atividade::Atividade()
{
    codigo = Codigo();
    nome = Nome();
    data = Data();
    horario = Horario();
    duracao = Duracao();
    preco = Dinheiro();
    avaliacao = Avaliacao();
}

void Atividade::setValor(const Codigo &novoCodigo) {
    this->codigo = novoCodigo;
}

void Atividade::setValor(const Nome &novoNome) {
    this->nome = novoNome;
}

void Atividade::setValor(const Data &novaData) {
    this->data = novaData;
}

void Atividade::setValor(const Horario &novoHorario) {
    this->horario = novoHorario;
}

void Atividade::setValor(const Duracao &novaDuracao) {
    this->duracao = novaDuracao;
}

void Atividade::setValor(const Dinheiro &novoPreco) {
    this->preco = novoPreco;
}

void Atividade::setValor(const Avaliacao &novaAvaliacao) {
    this->avaliacao = novaAvaliacao;
}

