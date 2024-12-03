#ifndef TUDINHEIRO_HPP_INCLUDED
#define TUDINHEIRO_HPP_INCLUDED

//! Testes de unidade Dinheiro
/*!
232001667 - implementa��o de Testes de unidade do dom�nio Dinheiro
*/

#include <stdexcept>
#include "Dinheiro.hpp"

using namespace std;

class TUDinheiro {
private:
const static int VALOR_VALIDO = "777"; // Defini��o de constante para evitar n�mero m�gico.
const static int VALOR_INVALIDO = "-777"; // Defini��o de constante para evitar n�mero m�gico.
Dinheiro *dinheiro; // Refer�ncia para unidade em teste.
int estado; // Estado do teste.
void setUp(); // M�todo para criar unidade em teste.
void tearDown(); // M�todo para destruir unidade em teste.
void testarCenarioValorValido(); // Cen�rio de teste com valor v�lido.
void testarCenarioValorInvalido(); // Cen�rio de teste com valor inv�lido.

public:
const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
const static int FALHA = -1; // Defini��o de constante para reportar resultado.
int run(); // M�todo para executar teste.
};



#endif // TUDINHEIRO_HPP_INCLUDED
