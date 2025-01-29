#include "../../include/Entidades/Hospedagem.hpp"

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include "../../include/Dominios/Dinheiro.hpp"
#include "../../include/Dominios/Avaliacao.hpp"

Hospedagem::Hospedagem()
{
    codigo = Codigo();
    nome = Nome();
    diaria = Dinheiro();
    avaliacao = Avaliacao();
    tag = Codigo();
    tagDestino = Codigo();
}

Hospedagem::Hospedagem(const Codigo& codigoNovo,
                       const Nome& nomeNovo,
                       const Avaliacao& avaliacaoNovo,
                       const Dinheiro& dinheiroNovo,
                       const Codigo& tagNova,
                       const Codigo& tagDestinoNova)
{
    codigo = codigoNovo;
    nome = nomeNovo;
    avaliacao = avaliacaoNovo;
    diaria = dinheiroNovo;
    tag = tagNova;
    tagDestino = tagDestinoNova;
}

void Hospedagem::setValor(const Codigo& codigo)
{
    this->codigo = codigo;
}

void Hospedagem::setValor(const Nome& nome)
{
    this->nome = nome;
}

void Hospedagem::setValor(const Avaliacao& avaliacao)
{
    this->avaliacao = avaliacao;
}

void Hospedagem::setValor(const Dinheiro& diaria)
{
    this->diaria = diaria;
}

void Hospedagem::setTag(Codigo novoID)
{
    this->tag = novoID;
}

void Hospedagem::setTagDestino(Codigo novoIDDestino)
{
    this->tagDestino = novoIDDestino;
}
