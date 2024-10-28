#include "Avaliacao.h"

//! Avaliacao::validar()
/*!
  Valida se o valor condiz com as condi&ccedil;&otilde;es de exist&ecirc;ncia.\n
  O valor deve ser de 0 a 5
  @return bool indicando se o valor &eacute; v&aacute;lido ou n&atilde;o.
*/

bool Avaliacao::validar(int valor)
{
    if (valor<0 or valor>5)
    {
        return false;
    }
    return true;
}

bool Avaliacao::setValor(int valor)
{
    if(!Avaliacao::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}
