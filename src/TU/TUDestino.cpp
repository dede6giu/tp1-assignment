#include "TU/TUDestino.hpp"

using namespace std;

void TUDestino::setUp()
{
    entidade = new Destino();
    estado = SUCESSO;
}

void TUDestino::tearDown()
{
    delete entidade;
}

void TUDestino::testarCenario()
{
    Codigo codigo;
    codigo.setValor(VALIDO_CODIGO);
    entidade->setValor(codigo);
    if (entidade->getValorCodigo() != VALIDO_CODIGO) estado = FALHA;

    Nome nome;
    nome.setValor(VALIDO_NOME);
    entidade->setValor(nome);
    if (entidade->getValorNome() != VALIDO_NOME) estado = FALHA;

    Data inicio;
    inicio.setValor(VALIDO_INICIO);
    entidade->setValor(inicio, 0);
    if (entidade->getValorInicio() != VALIDO_INICIO) estado = FALHA;

    Data fim;
    fim.setValor(VALIDO_FIM);
    entidade->setValor(fim, 1);
    if (entidade->getValorFim() != VALIDO_FIM) estado = FALHA;

    Avaliacao avaliacao;
    avaliacao.setValor(VALIDO_AVALIACAO);
    entidade->setValor(avaliacao);
    if (entidade->getValorAvaliacao() != VALIDO_AVALIACAO) estado = FALHA;
}

int TUDestino::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
