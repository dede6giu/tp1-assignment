#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Classe Codigo
/*!
  Classe Codigo, string de 6 caracteres alfanum&eacute;ricos sem diacr�ticos. \n
  232013031 - implementa&ccdeil;&atilde;o, construtores, documenta��o
*/

class Codigo
{
    private:
        //! Uma string.
        /*! Armazena o valor do codigo. */
        std::string codigo = "";

        //! Senha::validar()
        /*!
            Verifica se o tamanho da string fornecida � exatamente igual � CODELENGTH.
            Tamb�m verifica se todos os caracteres s�o alfanum�ricos sem diacr�ticos.
            @param string � ser analisada.
            @return bool indicando sucesso da opera��o.
        */
        bool validar(std::string);

    public:
        static int const CODELENGTH = 6;

        //! Construtor Vazio
        /*!
            Constr�i um objeto Codigo com valor vazio.
            @sa Codigo(std::string)
        */
        Codigo();

        //! Construtor Param�trico
        /*!
            Recebe um valor string, o verifica e finalmente constr�i um objeto
            Codigo com o valor inserido.
            @sa Codigo(), Codigo::validar()
        */
        Codigo(std::string);

        //! Codigo::setValor(std::string)
        /*!
            Recebe um valor string, o verifica e altera o valor atual do objeto.
            @param string que alterar� o valor codigo atual.
            @return booleano indicando o sucesso da opera��o.
            @sa codigo, Codigo::validar()
        */
        bool setValor(std::string);

        //! Codigo::getValor(std::string)
        /*!
            Retorna o valor atual do par�metro codigo.
            @return string codigo do objeto.
            @sa codigo
        */
        std::string getValor() const;
};

inline std::string Codigo::getValor() const
{
    return codigo;
}

#endif // CODIGO_HPP_INCLUDED
