#include <stdexcept>
#include "../../include/TU/TUAtividade.hpp"

void TUAtividade::setUp()
{
    entidade = new Atividade();
    estado = SUCESSO;
}

void TUAtividade::tearDown()
{
    delete entidade;
}

void TUAtividade::testarCenario()
{
    Codigo codigo;
    codigo.setValor(VALIDO_CODIGO);
    entidade->setValor(codigo);
    if (entidade->getValorCodigo() != VALIDO_CODIGO) estado = FALHA;

    Nome nome;
    nome.setValor(VALIDO_NOME);
    entidade->setValor(nome);
    if (entidade->getValorNome() != VALIDO_NOME) estado = FALHA;

    Data data;
    data.setValor(VALIDO_DATA);
    entidade->setValor(data);
    if (entidade->getValorData() != VALIDO_DATA) estado = FALHA;

    Horario horario;
    horario.setValor(VALIDO_HORARIO);
    entidade->setValor(horario);
    if (entidade->getValorHorario() != VALIDO_HORARIO) estado = FALHA;

    Duracao duracao;
    duracao.setValor(VALIDO_DURACAO);
    entidade->setValor(duracao);
    if (entidade->getValorDuracao() != VALIDO_DURACAO) estado = FALHA;

    Dinheiro preco;
    preco.setValor(VALIDO_PRECO);
    entidade->setValor(preco);
    if (entidade->getValorPreco() != VALIDO_PRECO) estado = FALHA;

    Avaliacao avaliacao;
    avaliacao.setValor(VALIDO_AVALIACAO);
    entidade->setValor(avaliacao);
    if (entidade->getValorAvaliacao() != VALIDO_AVALIACAO) estado = FALHA;
}

int TUAtividade::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
