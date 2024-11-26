#include "Entidades/Hospedagem.hpp"

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Dinheiro.hpp"
#include "Dominios/Avaliacao.hpp"

Hospedagem::Hospedagem(){
    codigo=Codigo();
    nome=Nome();
    diaria=Dinheiro();
    avaliacao=Avaliacao();
}

inline void Hospedagem::setValor(const Codigo& codigo)
{
    this->codigo=codigo;
}

inline void Hospedagem::setValor(const Nome& nome)
{
    this->nome=nome;
}

inline void Hospedagem::setValor(const Avaliacao& avaliacao)
{
    this->avaliacao=avaliacao;
}

inline void Hospedagem::setValor(const Dinheiro& diaria)
{
    this->diaria=diaria;
}