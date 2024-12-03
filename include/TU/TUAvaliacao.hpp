#ifndef TUAVALIACAO_HPP_INCLUDED
#define TUAVALIACAO_HPP_INCLUDED

//! Testes de unidade Avaliacao
/*!
232001667 - implementa��o de Testes de unidade do dom�nio Avaliacao
*/

#include <stdexcept>
#include "Avaliacao.hpp"

using namespace std;

class TUAvaliacao {
private:
const static int VALOR_VALIDO = "2"; // Defini��o de constante para evitar n�mero m�gico.
const static int VALOR_INVALIDO = "-69"; // Defini��o de constante para evitar n�mero m�gico.
Avaliacao *avaliacao; // Refer�ncia para unidade em teste.
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


#endif // TUAVALIACAO_HPP_INCLUDED
