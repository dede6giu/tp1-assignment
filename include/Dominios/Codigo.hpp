#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

//! Classe Codigo
/*!
  Classe Codigo, string de 6 caracteres alfanum&eacute;ricos sem diacríticos. \n
  232013031 - implementa&ccdeil;&atilde;o, construtores, documentação
*/

class Codigo
{
    private:
        //! Uma string.
        /*! Armazena o valor do codigo. */
        std::string codigo = "";

        //! Senha::validar()
        /*!
            Verifica se o tamanho da string fornecida é exatamente igual à CODELENGTH.
            Também verifica se todos os caracteres são alfanuméricos sem diacríticos.
            @param string à ser analisada.
            @return bool indicando sucesso da operação.
        */
        bool validar(std::string);

    public:
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
            @sa Codigo(), Codigo::validar()
        */
        Codigo(std::string);

        //! Codigo::setValor(std::string)
        /*!
            Recebe um valor string, o verifica e altera o valor atual do objeto.
            @param string que alterará o valor codigo atual.
            @return booleano indicando o sucesso da operação.
            @sa codigo, Codigo::validar()
        */
        bool setValor(std::string);

        //! Codigo::getValor(std::string)
        /*!
            Retorna o valor atual do parâmetro codigo.
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
