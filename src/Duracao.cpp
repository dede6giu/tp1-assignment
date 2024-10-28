#include "Duracao.h"

bool Duracao::setValor(int valor)
{
    if (!Duracao::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}

//! Duracao::validar()
/*!
  Valida se o valor condiz com as condi&ccedil;&otilde;es de exist&ecirc;ncia.\n
  O valor deve ser de 0 ao limite estabelecido dentro da classe (360)
  @return bool indicando se o valor &eacute; v&aacute;lido ou n&atilde;o.
*/


bool Duracao::validar(int valor)
{
    if (0 <= valor && valor <= MAXIMO)
    {
        return true;
    }
    return false;
}
