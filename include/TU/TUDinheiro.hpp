#ifndef TUDINHEIRO_HPP_INCLUDED
#define TUDINHEIRO_HPP_INCLUDED

//! Testes de unidade Dinheiro
/*!
232001667 - implementação de Testes de unidade do domínio Dinheiro
*/

#include <stdexcept>
#include "Dinheiro.hpp"

using namespace std;

class TUDinheiro {
private:
const static int VALOR_VALIDO = "777"; // Definição de constante para evitar número mágico.
const static int VALOR_INVALIDO = "-777"; // Definição de constante para evitar número mágico.
Dinheiro *dinheiro; // Referência para unidade em teste.
int estado; // Estado do teste.
void setUp(); // Método para criar unidade em teste.
void tearDown(); // Método para destruir unidade em teste.
void testarCenarioValorValido(); // Cenário de teste com valor válido.
void testarCenarioValorInvalido(); // Cenário de teste com valor inválido.

public:
const static int SUCESSO = 0; // Definição de constante para reportar resultado.
const static int FALHA = -1; // Definição de constante para reportar resultado.
int run(); // Método para executar teste.
};



#endif // TUDINHEIRO_HPP_INCLUDED
