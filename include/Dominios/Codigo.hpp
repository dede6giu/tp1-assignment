#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Dominio Codigo
/*!
    Dominio Codigo, string de 6 caracteres alfanum&eacute;ricos maiúsculos ou minúsculos sem diacríticos. \n
    232013031 - implementação, construtores, documentação. \n
    232002771 - exceções, documentação.
*/

class Codigo
{
    private:

        //! Uma string.
        /*! Armazena o valor do Codigo. */
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

        //! Um inteiro público
        /*!
          Armazena o valor máximo da valiação.
        */
        static int const CODELENGTH = 6;

        //! Construtor Vazio
        /*!
            Constrói um objeto Codigo com valor vazio.
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
            Recebe um valor string, verifica-o e altera o valor atual do objeto pelo novo.
            @param string que substituirá o valor codigo atual.
            @sa codigo, Codigo::validar()
        */
        void setValor(std::string);

        //! Codigo::getValor(std::string)
        /*!
            Retorna o valor atual do parâmetro codigo.
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
