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
}

Hospedagem::Hospedagem(const Codigo& codigoNovo,
                       const Nome& nomeNovo,
                       const Avaliacao& avaliacaoNovo,
                       const Dinheiro& dinheiroNovo)
{
    codigo = codigoNovo;
    nome = nomeNovo;
    avaliacao = avaliacaoNovo;
    diaria = dinheiroNovo;
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
