#include "dominios.hpp"

//! avaliacao validar
/*! 232001667 - metodo de validacao
*/

bool Avaliacao::validar(int valor)
{
    if (valor<0 or valor>5):
    {
        return false
    }
    else
    {
        return true
    }
}

bool Avaliacao::setValor(int valor)
{
    if(!validar(valor))
        return false;
    this-> = valor;
    return true
}
