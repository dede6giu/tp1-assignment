#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Classe Codigo
/*!
  Classe Codigo, string de 6 caracteres alfanum&eacute;ricos\n
  232013031 - implementa&ccdeil;&atilde;o, construtores \n
  232002771 - exceções
*/

class Codigo
{
    private:
        std::string codigo = "";
        void validar(std::string);

    public:
        static int const CODELENGTH = 6;

        Codigo();
        Codigo(std::string);

        void setValor(std::string);
        std::string getValor() const;
};

inline std::string Codigo::getValor() const
{
    return this->codigo;
}

#endif // CODIGO_HPP_INCLUDED
