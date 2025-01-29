#include "../../include/Entidades/Viagem.hpp"

Viagem::Viagem()
{
    avaliacao = Avaliacao();
    codigo = Codigo();
    nome = Nome();
    tag = Codigo();
}

Viagem::Viagem(const Avaliacao& avaliacaoNovo,
               const Codigo& codigoNovo,
               const Nome& nomeNovo,
               const Codigo& tagNovo)
{
    avaliacao = avaliacaoNovo;
    codigo = codigoNovo;
    nome = nomeNovo;
    tag = tagNovo;
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
