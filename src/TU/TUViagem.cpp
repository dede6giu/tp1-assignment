#include "../../include/TU/TUViagem.hpp"

void TUViagem::setUp()
{
    entidade = new Viagem();
    estado = SUCESSO;
}

void TUViagem::tearDown()
{
    delete entidade;
}

void TUViagem::testarCenario()
{
    Codigo codigo;
    codigo.setValor(VALIDO_CODIGO);
    entidade->setValor(codigo);
    if (entidade->getValorCodigo() != VALIDO_CODIGO) estado = FALHA;

    Nome nome;
    nome.setValor(VALIDO_NOME);
    entidade->setValor(nome);
    if (entidade->getValorNome() != VALIDO_NOME) estado = FALHA;

    Avaliacao avaliacao;
    avaliacao.setValor(VALIDO_AVALIACAO);
    entidade->setValor(avaliacao);
    if (entidade->getValorAvaliacao() != VALIDO_AVALIACAO) estado = FALHA;
}

int TUViagem::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
