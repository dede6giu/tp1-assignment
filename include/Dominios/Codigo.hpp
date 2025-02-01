#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Dominio Codigo
/*!
    Dominio Codigo, string de 6 caracteres alfanum&eacute;ricos maiúsculos ou minúsculos sem diacríticos. \n
    232013031 - implementação, construtores, documentação. \n
    232002771 - exceções, documentação. \n
    232002520 - documentação
*/

class Codigo
{
    private:

        //! Valor de código
        /*! Atributo string referente ao código. */
        std::string codigo;

        //! Senha::validar()
        /*!
            Verifica se o tamanho da string fornecida é exatamente igual a CODELENGTH.
            Também verifica se todos os caracteres são alfanuméricos sem diacríticos.
            @param string a ser validada.
            @sa CODELENGTH
        */
        void validar(std::string);

    public:

        //! Tamanho válido de código
        /*!
          Atributo inteiro estático constante com o comprimento válido de código.
        */
        static int const CODELENGTH = 6;

        //! Construtor Vazio
        /*!
            Constrói um objeto Codigo vazio.
            @sa Codigo(std::string)
        */
        Codigo();

        //! Construtor Paramétrico
        /*!
            Recebe um valor string, o verifica e finalmente constrói um objeto
            Codigo com o valor inserido.
            @sa Codigo()
        */
        Codigo(std::string);

        //! Codigo::setValor(std::string)
        /*!
            Recebe um valor string, verifica-o e armazena-o como novo código.
            @param string que substituirá o valor codigo atual.
            @sa codigo, Codigo::validar()
        */
        void setValor(std::string);

        //! Codigo::getValor(std::string)
        /*!
            Retorna o valor atual do parâmetro código.
            @return string codigo atual do objeto.
            @sa codigo
        */
        std::string getValor() const;
};

inline std::string Codigo::getValor() const
{
    return this->codigo;
}

#endif // CODIGO_HPP_INCLUDED
