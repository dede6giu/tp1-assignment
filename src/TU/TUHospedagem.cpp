#include "../../include/TU/TUHospedagem.hpp"

using namespace std;

void TUHospedagem::setUp()
{
    entidade = new Hospedagem();
    estado = SUCESSO;
}

void TUHospedagem::tearDown()
{
    delete entidade;
}

void TUHospedagem::testarCenario()
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

    Dinheiro diaria;
    diaria.setValor(VALIDO_DIARIA);
    entidade->setValor(diaria);
    if (entidade->getValorDiaria() != VALIDO_DIARIA) estado = FALHA;
}

int TUHospedagem::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
