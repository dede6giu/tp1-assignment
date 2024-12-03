#ifndef TUNOME_HPP_INCLUDED
#define TUNOME_HPP_INCLUDED

//! Teste de unidade Nome
/*!
232001667 - implementa��o de Testes de unidade do dom�nio Nome
*/

#include <stdexcept>
#include "Nome.hpp"

using namespace std;

class TUNome {
private:
const static string VALOR_VALIDO = "PERSONADISTURBINGTHEPEACE"; // Defini��o de constante para evitar n�mero m�gico.
const static string VALOR_INVALIDO = "bruhbruhbruhbruhbruhbruhbruhbruh"; // Defini��o de constante para evitar n�mero m�gico.
Nome *nome; // Refer�ncia para unidade em teste.
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


#endif // TUNOME_HPP_INCLUDED
