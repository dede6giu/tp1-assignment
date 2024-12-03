#ifndef TUNOME_HPP_INCLUDED
#define TUNOME_HPP_INCLUDED

//! Teste de unidade Nome
/*!
232001667 - implementação de Testes de unidade do domínio Nome
*/

#include <stdexcept>
#include "Nome.hpp"

using namespace std;

class TUNome {
private:
const static string VALOR_VALIDO = "PERSONADISTURBINGTHEPEACE"; // Definição de constante para evitar número mágico.
const static string VALOR_INVALIDO = "bruhbruhbruhbruhbruhbruhbruhbruh"; // Definição de constante para evitar número mágico.
Nome *nome; // Referência para unidade em teste.
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


#endif // TUNOME_HPP_INCLUDED
