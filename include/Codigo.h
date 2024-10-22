#ifndef CODIGO_H
#define CODIGO_H

#include <string>

//! Classe Codigo
/*!
  Classe Codigo, string de 6 caracteres alfanum&eacute;ricos\n
  232013031 - implementa&ccdeil;&atilde;o, documenta&ccdeil;&atilde;o
*/

class Codigo
{
    private:
        std::string valor = "";
        bool validar(std::string);

    public:
        int const CODELENGTH = 6;
        bool setValor(std::string);
        std::string getValor() const;
};

inline std::string Codigo::getValor() const
{
    return valor;
}

#endif // CODIGO_H
