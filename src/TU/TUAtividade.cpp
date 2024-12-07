#include <stdexcept>
#include "TU/TUAtividade.hpp"

#include <iostream>
using namespace std;

void TUAtividade::setUp()
{
    dominio = new Atividade();
    estado = SUCESSO;
}

void TUAtividade::tearDown()
{
    delete dominio;
}

void TUAtividade::testeUniVal(vector<string> teste)
{
    dominio->getCodigo().setValor(teste[0]); // Codigo
    dominio->getNome().setValor(teste[1]); // Nome
    dominio->getData().setValor(teste[2]); // Data
    dominio->getHorario().setValor(teste[3]); // Horario
    dominio->getDuracao().setValor(stoi(teste[4])); // Duracao
    dominio->getPreco().setValor(stoi(teste[5])); // Dinheiro
    dominio->getAvaliacao().setValor(stoi(teste[6])); // Avaliacao

    if (dominio->getAtividade() != teste[7])
        estado = FALHA;
}

void TUAtividade::testarValido()
{
    try {
        for (int i = 0; i < TUAtividade::VALIDO.size(); i++) {
            testeUniVal(TUAtividade::VALIDO[i]);
        }
    }
    catch(invalid_argument &excecao) {
        estado = FALHA;
        cout << excecao.what();
    }
}

void TUAtividade::testeUniInv(vector<string> teste)
{
    try
    {
        dominio->getCodigo().setValor(teste[0]); // Codigo
        dominio->getNome().setValor(teste[1]); // Nome
        dominio->getData().setValor(teste[2]); // Data
        dominio->getHorario().setValor(teste[3]); // Horario
        dominio->getDuracao().setValor(stoi(teste[4])); // Duracao
        dominio->getPreco().setValor(stoi(teste[5])); // Dinheiro
        dominio->getAvaliacao().setValor(stoi(teste[6])); // Avaliacao

        estado = FALHA;
    }
    catch (invalid_argument &excecao) {
        if (dominio->getAtividade() == teste[7])
            estado = FALHA;
            cout << excecao.what();
    }
    catch (length_error &excecao) {
            if (dominio->getAtividade() == teste[7])
            estado = FALHA;
            cout << excecao.what();
    }
}

void TUAtividade::testarInvalido()
{
    for (int i = 0; i < TUAtividade::INVALIDO.size(); i++) {
        testeUniInv(TUAtividade::INVALIDO[i]);
    }
}

int TUAtividade::run()
{
    setUp();
    testarValido();
    testarInvalido();
    tearDown();
    return estado;
}
