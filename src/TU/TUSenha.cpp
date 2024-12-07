#include "TU/TUSenha.hpp"

using namespace std;

void TUSenha::setUp() {
    dominio = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete dominio;
}

void TUSenha::testeUniVal(string valor) {
    dominio->setValor(valor);
    if (dominio->getValor() != valor)
        estado = FALHA;
}

void TUSenha::testarValido() {
    try
    {
        for (int i = 0; i < VALIDO.size(); i++)
        {
            testeUniVal(VALIDO[i]);
        }
    }
    catch (invalid_argument &excecao) {
        estado = FALHA;
    }
    catch (length_error &excecao) {
        estado = FALHA;
    }
}

void TUSenha::testeUniInv(string valor) {
    try
    {
        dominio->setValor(valor);
        estado = FALHA;
    }
    catch (invalid_argument &excecao){
        if (dominio->getValor() == valor)
            estado = FALHA;
    }
    catch (length_error &excecao) {
        if (dominio->getValor() == valor)
            estado = FALHA;
    }
}

void TUSenha::testarInvalido()
{
    for (int i = 0; i < INVALIDO.size(); i++) {
        testeUniInv(INVALIDO[i]);
    }
}


int TUSenha::run() {
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
