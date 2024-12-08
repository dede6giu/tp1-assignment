#include "../../include/Entidades/Destino.hpp"

#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include "../../include/Dominios/Data.hpp"
#include "../../include/Dominios/Avaliacao.hpp"

Destino::Destino()
{
    codigo = Codigo();
    nome = Nome();
    inicio = Data();
    fim = Data();
    avaliacao = Avaliacao();
}

Destino::Destino(const Codigo& codigoNovo,
                 const Nome& nomeNovo,
                 const Data& inicioNovo,
                 const Data& fimNovo,
                 const Avaliacao& avaliacaoNovo)
{
    codigo = codigoNovo;
    nome = nomeNovo;
    inicio = inicioNovo;
    fim = fimNovo;
    avaliacao = avaliacaoNovo;
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
