#include "TUDinheiro.hpp"

void TUDinheiro::setUp(){
dinheiro = new Dinheiro();
estado = SUCESSO;
}

void TUDinheiro::tearDown(){
delete dinheiro;
}

void TUDinheiro::testarCenarioValorValido(){
try{
dominio->setValor(VALOR_VALIDO);
if (dominio->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUDinheiro::testarCenarioValorInvalido(){
try{
dominio->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (dominio->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUDinheiro::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}
