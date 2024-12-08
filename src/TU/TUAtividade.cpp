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
    Codigo codigo = Codigo(teste[0]);
    Nome nome = Nome(teste[1]);
    Data data = Data(); data.setValor(teste[2]);
    Horario horario = Horario(); horario.setValor(teste[3]);
    Duracao duracao = Duracao(stoi(teste[4]));
    Dinheiro preco = Dinheiro(stoi(teste[5]));
    Avaliacao avaliacao = Avaliacao(stoi(teste[6]));

    dominio->setValor(codigo);      // Codigo
    dominio->setValor(nome);        // Nome
    dominio->setValor(data);        // Data
    dominio->setValor(horario);     // Horario
    dominio->setValor(duracao);     // Duracao
    dominio->setValor(preco);       // Dinheiro
    dominio->setValor(avaliacao);   // Avaliacao

    if (dominio->getAtividade() != teste[7]) {
        estado = FALHA;
    }
}

void TUAtividade::testarValido()
{
    dominio = new Atividade();

    try {
        for (int i = 0; i < TUAtividade::VALIDO.size(); i++) {
            testeUniVal(TUAtividade::VALIDO[i]);
        }
    }
    catch(invalid_argument &excecao) {
        estado = FALHA;
    }
    catch(length_error &excecao) {
        estado = FALHA;
    }
}

void TUAtividade::testeUniInv(vector<string> teste)
{
    try
    {
        Codigo codigo = Codigo(teste[0]);
        Nome nome = Nome(teste[1]);
        Data data = Data(); data.setValor(teste[2]);
        Horario horario = Horario(); horario.setValor(teste[3]);
        Duracao duracao = Duracao(stoi(teste[4]));
        Dinheiro preco = Dinheiro(stoi(teste[5]));
        Avaliacao avaliacao = Avaliacao(stoi(teste[6]));

        dominio->setValor(codigo);      // Codigo
        dominio->setValor(nome);        // Nome
        dominio->setValor(data);        // Data
        dominio->setValor(horario);     // Horario
        dominio->setValor(duracao);     // Duracao
        dominio->setValor(preco);       // Dinheiro
        dominio->setValor(avaliacao);   // Avaliacao

        estado = FALHA;
    }
    catch (invalid_argument &excecao) {
        if (dominio->getAtividade() == teste[7])
            estado = FALHA;

    }
    catch (length_error &excecao) {
            if (dominio->getAtividade() == teste[7])
                estado = FALHA;
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
