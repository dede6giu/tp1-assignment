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
        std::string nome;

        //! Nome::validar()
        /*!
          Verifica se o valor de uma string est&aacute; dentro do limite MAXLENGTH.
          @param string a ser verificada.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
        */
        void validar(std::string);

    public:
        //! Um inteiro p&uacute;blico estático
        /*!
          Armazena o tamanho m&aacute;ximo do valor.
          @sa validar()
        */
        static int const MAXLENGTH = 30;

        //! Construtor Vazio
        /*!
            Constrói um objeto Nome com valor vazio.
            @sa Nome(std::string)
        */
        Nome();

        //! Construtor Paramétrico
        /*!
            Recebe um valor string, o verifica e finalmente constrói um objeto
            Nome com o valor inserido.
            @param string usada para construir o objeto.
            @sa Nome(), Nome::validar()
        */
        Nome(std::string);

        //! Nome::setValor()
        /*!
          Armazena um novo valor dentro da classe após sua verificação.
          @param string novo valor.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
          @sa getValor(), Nome::validar()
        */
        void setValor(std::string);

        //! Nome::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Nome.
          @return string parâmetro nome do objeto.
        */
        std::string getValor() const;
};

inline std::string Nome::getValor() const
{
    return nome;
}

#endif // NOME_HPP_INCLUDED
