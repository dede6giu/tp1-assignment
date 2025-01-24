#include "../../include/Stubs/SBViagem.hpp"
#include <iostream>

const string SBConta::TRIGGER_FALHA_AVALIACAO = 20;
const string SBConta::TRIGGER_FALHA_CODIGO = "a";
const string SBConta::TRIGGER_FALHA_NOME = "";


bool SBViagem::criar(Viagem viagemRecebida) {

    cout << endl            << "SBViagem::criar"                  << endl;
    cout << "Codigo     = " << viagemRecebida.getValorCodigo()    << endl;
    cout << "Nome       = " << viagemRecebida.getValorNome()      << endl;
    cout << "Avaliacao  = " << viagemRecebida.getValorAvaliacao() << endl;

    if (viagemRecebida.getValorAvaliacao() == TRIGGER_FALHA_AVALIACAO
        || viagemRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO
        || viagemRecebida.getValorNome()   == TRIGGER_FALHA_NOME) {
        return false;
    }
    return true;
}

bool SBViagem::excluir(Viagem viagemRecebida) {

    cout << endl            << "SBViagem::excluir"             << endl;
    cout << "Codigo     = " << viagemRecebida.getValorCodigo() << endl;

    if (viagemRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO) {
        return false;
    }
    return true;
}

bool SBViagem::ler(Viagem viagemRecebida) {

    cout << endl            << "SBViagem::ler"                 << endl;
    cout << "Codigo     = " << viagemRecebida.getValorCodigo() << endl;

    if (viagemRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO) {
        return false;
    }
    return true;
}

bool SBViagem::atualizar(Viagem viagemRecebida, Avaliacao avaliacaoRecebida) {

    cout << endl                  << "SBViagem::atualizar"              << endl;
    cout << "Codigo           = " << viagemRecebida.getValorCodigo()    << endl;
    cout << "Avaliacao Antiga = " << viagemRecebida.getValorAvaliacao() << endl;
    cout << "Avaliacao Nova   = " << avaliacaoRecebida.getValor()       << endl;

    if (viagemRecebida.getValorCodigo()       == TRIGGER_FALHA_CODIGO
        || viagemRecebida.getValorAvaliacao()) == TRIGGER_FALHA_AVALIACAO
        || avaliacaoRecebida.getValor()       == TRIGGER_FALHA_AVALIACAO) {
        return false;
    }
    return true;
}

bool SBViagem::atualizar(Viagem viagemRecebida, Nome nomeRecebido) {

    cout << endl             << "SBViagem::criar"               << endl;
    cout << "Codigo      = " << viagemRecebida.getValorCodigo() << endl;
    cout << "Nome novo   = " << viagemRecebida.getValorNome()   << endl;
    cout << "Nome antigo = " << nomeRecebido.getValor()         << endl;

    if (viagemRecebida.getValorCodigo() == TRIGGER_FALHA_CODIGO
        || viagemRecebida.getValorNome() == TRIGGER_FALHA_NOME
        || nomeRecebido.getValor() == TRIGGER_FALHA_NOME) {
        return false;
    }
    return true;
}
