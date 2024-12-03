#ifndef TUAVALIACAO_HPP_INCLUDED
#define TUAVALIACAO_HPP_INCLUDED

//! Testes de unidade Avaliacao
/*!
232001667 - implementação de Testes de unidade do domínio Avaliacao
*/

#include <stdexcept>
#include "Avaliacao.hpp"

using namespace std;

class TUAvaliacao {
private:
const static int VALOR_VALIDO = "2"; // Definição de constante para evitar número mágico.
const static int VALOR_INVALIDO = "-69"; // Definição de constante para evitar número mágico.
Avaliacao *avaliacao; // Referência para unidade em teste.
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


#endif // TUAVALIACAO_HPP_INCLUDED
