#include "Entidades/Atividade.hpp"

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Horario.hpp"
#include "../Dominios/Duracao.hpp"
#include "../Dominios/Dinheiro.hpp"
#include "../Dominios/Avaliacao.hpp"

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

