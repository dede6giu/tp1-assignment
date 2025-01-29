#include "../../include/Entidades/Atividade.hpp"

#include "../../include/Dominios.hpp"

Atividade::Atividade()
{
    codigo = Codigo();
    nome = Nome();
    data = Data();
    horario = Horario();
    duracao = Duracao();
    preco = Dinheiro();
    avaliacao = Avaliacao();
    tag = Codigo();
    tagDestino = Codigo();
}

Atividade::Atividade(const Codigo& codigoNovo,
                     const Nome& nomeNovo,
                     const Data& dataNovo,
                     const Horario& horarioNovo,
                     const Duracao& duracaoNovo,
                     const Dinheiro& precoNovo,
                     const Avaliacao& avaliacaoNovo,
                     const Codigo& tagNova,
                     const Codigo& tagDestinoNova);
{
    codigo = codigoNovo;
    nome = nomeNovo;
    data = dataNovo;
    horario = horarioNovo;
    duracao = duracaoNovo;
    preco = precoNovo;
    avaliacao = avaliacaoNovo;
    tag = tagNova;
    tagDestino = tagDestinoNova;
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

void Atividade::setTag(Codigo novoID)
{
    this->tag = novoID;
}
void Atividade::setTagDestino(Codigo novoIDDestino)
{
    this->tagDestino = novoIDDestino;
}
