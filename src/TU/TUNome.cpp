#include "TUNome.hpp"

void TUNome::setUp(){
nome = new Nome();
estado = SUCESSO;
}

void TUNome::tearDown(){
delete nome;
}

void TUNome::testarCenarioValorValido(){
try{
dominio->setValor(VALOR_VALIDO);
if (dominio->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUNome::testarCenarioValorInvalido(){
try{
dominio->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (dominio->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUNome::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}
