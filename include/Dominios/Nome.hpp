#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

//! Dominio Nome
/*!
    Dominio Nome, string de no máximo 30 caracteres.\n
    232013031 - implementação, documentação, construtores\n
    232002771 - exceções, documentação \n
    232006028 - documentação
*/

class Nome
{
    private:

        //! Uma string.
        /*! Armazena o valor do nome. */
        std::string nome;

        //! Nome::validar()
        /*!
          Verifica se o valor de uma string está dentro do limite MAXLENGTH.
          @param string a ser verificada.
        */
        void validar(std::string);

    public:

        //! Um inteiro público estático
        /*!
          Armazena o tamanho máximo do valor.
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
            @sa Nome()
        */
        Nome(std::string);

        //! Nome::setValor()
        /*!
          Armazena um novo valor dentro da classe após sua verificação.
          @param string novo valor.
          @return bool indicando sucesso da operação.
          @sa getValor()
        */
        void setValor(std::string);

        //! Nome::getValor()
        /*!
          Função para obter o valor da classe Nome.
          @return string parâmetro nome do objeto.
        */
        std::string getValor() const;
};

inline std::string Nome::getValor() const
{
    return nome;
}

#endif // NOME_HPP_INCLUDED
