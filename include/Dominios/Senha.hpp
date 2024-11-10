#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

//! Domínio Senha
/*!
    Domínio Senha \n
    232006028 - implementação. \n
    232002771 - implementação por string. \n
    232013031 - construtores, documentação.
*/

class Senha
{
    private:
        //! Uma string.
        /*! Armazena o valor da senha. */
        std::string senha;

        //! Senha::validar()
        /*!
            Verifica se o tamanho da string fornecida é exatamente igual à VALIDLEN,
            se todos os caracteres são dígitos distintos e se os cinco dígitos não
            estão em ordem (de)cresente.
            @param string à ser analisada.
            @return bool indicando sucesso da operação
        */
        bool validar(std::string);
    public:
        //! Um inteiro constante estático.
        /*! Armazena o valor do tamanho da senha. */
        static const int VALIDLEN = 5;

        //! Construtor Vazio
        /*!
            Constrói um objeto Senha com valor vazio.
            @sa Senha(std::string)
        */
        Senha();

        //! Construtor Paramétrico
        /*!
            Recebe um valor string, o verifica e finalmente constrói um objeto
            Senha com o valor inserido.
            @sa Senha(), Senha::validar()
        */
        Senha(std::string);

        //! Senha::setValor(std::string)
        /*!
            Recebe um valor string, o verifica e altera o valor atual do objeto.
            @param string que alterará o valor da senha atual
            @return booleano indicando o sucesso da operação.
            @sa senha, Senha::validar()
        */
        bool setValor(std::string);

        //! Senha::getValor()
        /*!
            Retorna o valor atual do parâmetro senha.
            @return string senha do objeto.
            @sa senha
        */
        std::string getValor() const;
};

inline std::string Senha::getValor() const
{
    return senha;
}

#endif // SENHA_HPP_INCLUDED
