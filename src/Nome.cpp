#include "Nome.h"

bool Nome::setValor(std::string valor)
{
    if (!Nome::validar(valor))
    {
        return false;
    }
    this->valor = valor;
    return true;
}

//! Nome::validar()
/*!
  Valida se o valor condiz com as condi&ccedil;&otilde;es de exist&ecirc;ncia.\n
  O valor deve ser maior que 0 caracteres e menor que o limite estabelecido da classe (30 caracteres)
  @return bool indicando se o valor &eacute; v&aacute;lido ou n&atilde;o.
*/

bool Nome::validar(std::string valor)
{
    int len = valor.length();
    if (len > this->MAXLENGTH or len <= 0)
    {
        return false;
    }
    return true;
}
