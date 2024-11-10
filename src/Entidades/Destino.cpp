#include "Entidades/Destino.hpp"

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Avaliacao.hpp"

Destino::Destino()
{
    codigo = Codigo();
    nome = Nome();
    inicio = Data();
    fim = Data();
    avaliacao = Avaliacao();
}

void Destino::setValor(const Codigo& novoCodigo) {
    this->codigo = novoCodigo;
}

void Destino::setValor(const Nome& novoNome) {
    this->nome = novoNome;
}

void Destino::setValor(const Avaliacao& novoAvaliacao) {
    this->avaliacao = novoAvaliacao;
}

void Destino::setValor(const Data& novoData, bool inifim) {
    if (inifim) {
        this->fim = novoData;
    } else {
        this->inicio = novoData;
    }
}
