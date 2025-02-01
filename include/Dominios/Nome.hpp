#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

//! Dominio Nome
/*!
    Dominio Nome, string de no máximo 30 caracteres.\n
    232013031 - implementação, documentação, construtores\n
    232002771 - exceções, documentação \n
    232006028 - documentação \n
    232002520 - documentação
*/

class Nome
{
    private:

        //! Valor de nome
        /*! Atributo string que armazena o valor do nome. */
        std::string nome;

        //! Nome::validar()
        /*!
          Verifica se o valor de uma string está dentro do limite MAXLENGTH.
          @param string a ser verificada.
        */
        void validar(std::string);

    public:

        //! Tamanho máximo de nome
        /*!
          Atributo inteiro estático constante que armazena o tamanho máximo do valor.
        */
        static int const MAXLENGTH = 30;

        //! Construtor Vazio
        /*!
            Constrói um objeto Nome vazio.
            @sa Nome(std::string)
        */
        Nome();

        //! Construtor Paramétrico
        /*!
            Recebe um valor string, o verifica e finalmente constrói um objeto
            Nome com o valor inserido.
            @param string usada para construir o objeto.
            @sa Nome()
        */
        Nome(std::string);

        //! Nome::setValor()
        /*!
          Recebe um valor string, verifica-o e o armazena como novo nome dentro da classe.
          @param string novo valor.
          @return bool indicando sucesso da operação.
          @sa getValor()
        */
        void setValor(std::string);

        //! Nome::getValor()
        /*!
          Retorna o nome armazenado na classe.
          @return string com valor do novo nome.
        */
        std::string getValor() const;
};

inline std::string Nome::getValor() const
{
    return nome;
}

#endif // NOME_HPP_INCLUDED
