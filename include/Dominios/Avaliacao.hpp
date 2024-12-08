#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED

//! Classe Avaliacao
/*!
    Classe Avaliacao, inteiro v&aacute;lido entre 0 e 5 inclusivo \n
    232029274 - implementa&ccedil;&atilde;o. \n
    232002771 - documenta&ccedil;&atilde;o. \n
    232013031 - construtores, exceções
*/

class Avaliacao
{
    private:
        //! Um int.
        /*! Armazena a o valor da avalia&ccedil;&atilde;o. */
        int avaliacao;

        //! Avaliacao::validar()
        /*!
          Verifica se o valor da avalia&ccedil;&atilde;o est&aacute; no intervalo de 0 a 5.
          @param int valor a validar
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
        */
        void validar(int);

    public:
        //! Construtor Vazio
        /*!
            Constr�i um objeto Avaliacao com valor vazio.
            @sa Avaliacao(std::string)
        */
        Avaliacao();
        //! Construtor paramétrico
        /*!
            Constrói um objeto Avaliacao e recebe um int com o valor de avaliacao.
            @param int avaliacao.
        */
        Avaliacao(int);

        //! Avaliacao::setValor()
        /*!
          Armazena um novo valor dentro da classe.
          @param int novo valor.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
          @sa getValor(), Avaliacao::validar()
        */
        void setValor(int);

        //! Avalicao::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Avaliacao.
          @return O valor da avalia&ccedil;&atilde;o.
        */
        int getValor() const;
};

inline int Avaliacao::getValor() const
{
        return avaliacao;
}

#endif // AVALIACAO_HPP_INCLUDED
