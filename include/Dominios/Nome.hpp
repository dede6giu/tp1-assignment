#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

//! Classe Nome
/*!
  Classe Nome, string de m&aacute;ximo 30 caracteres.\n
  232013031 - implementa&ccedil;&atilde;o, documenta&ccedil;&atilde;o, construtores\n
  232002771 - exceções
*/

class Nome
{
    private:
        //! Uma string.
        /*! Armazena o valor do nome. */
        std::string nome = "";

        //! Nome::validar()
        /*!
          Verifica se o valor do nome est&aacute; dentro do limite de caracteres.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
        */
        void validar(std::string);

    public:
        Nome();
        Nome(std::string);

        //! Um inteiro p&uacute;blico
        /*!
          Armazena o tamanho m&aacute;ximo do valor.
          @sa validar()
        */
        static int const MAXLENGTH = 30;

        //! Nome::setValor()
        /*!
          Armazena um novo valor dentro da classe.
          @param string novo valor.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
          @sa getValor(), Nome::validar()
        */
        void setValor(std::string);

        //! Nome::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Nome.
          @return O valor do nome
        */
        std::string getValor() const;
};

inline std::string Nome::getValor() const
{
    return nome;
}

#endif // NOME_HPP_INCLUDED
