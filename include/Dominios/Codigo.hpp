#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Classe Codigo
/*!
  Classe Codigo, string de 6 caracteres alfanum&eacute;ricos\n
  232013031 - implementa&ccdeil;&atilde;o, construtores
*/

class Codigo
{
    private:
        std::string codigo = "";
        bool validar(std::string);

    public:
        static int const CODELENGTH = 6;

        Codigo();
        Codigo(std::string);

        bool setValor(std::string);
        std::string getValor() const;
};

inline std::string Codigo::getValor() const
{
    return codigo;
}

#endif // CODIGO_HPP_INCLUDED
