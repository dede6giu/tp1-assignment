#include "TUAvaliacao.hpp"

void TUAvaliacao::setUp(){
avaliacao = new Avaliacao();
estado = SUCESSO;
}

void TUAvaliacao::tearDown(){
delete avaliacao;
}

void TUAvaliacao::testarCenarioValorValido(){
try{
dominio->setValor(VALOR_VALIDO);
if (dominio->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUAvaliacao::testarCenarioValorInvalido(){
try{
dominio->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (dominio->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUAvaliacao::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}
