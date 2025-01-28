#include "../../include/Entidades/Viagem.hpp"

Viagem::Viagem()
{
    avaliacao = Avaliacao();
    codigo = Codigo();
    nome = Nome();
}

Viagem::Viagem(const Avaliacao& avaliacaoNovo,
               const Codigo& codigoNovo,
               const Nome& nomeNovo)
{
    avaliacao = avaliacaoNovo;
    codigo = codigoNovo;
    nome = nomeNovo;
}

void Viagem::setValor(const Codigo &novoCodigo)
{
    this->codigo = novoCodigo;
}

void Viagem::setValor(const Nome &novoNome)
{
    this->nome = novoNome;
}

void Viagem::setValor(const Avaliacao &novaAvaliacao)
{
    this->avaliacao = novaAvaliacao;
}

void Viagem::setTag(Codigo novoID)
{
    this->tag = novoID;
}
