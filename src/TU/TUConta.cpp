#include "TU/TUConta.hpp"

using namespace std;

void TUConta::setUp()
{
    entidade = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown()
{
    delete entidade;
}

void TUConta::testarCenario()
{
    Codigo codigo;
    codigo.setValor(VALIDO_CODIGO);
    entidade->setValor(codigo);
    if (entidade->getValorCodigo() != VALIDO_CODIGO) estado = FALHA;

    Senha senha;
    senha.setValor(VALIDO_SENHA);
    entidade->setValor(senha);
    if (entidade->getValorSenha() != VALIDO_SENHA) estado = FALHA;
}

int TUConta::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
