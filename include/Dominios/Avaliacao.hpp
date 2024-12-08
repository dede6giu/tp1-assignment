#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED

//! Dominio Avaliacao
/*!
    Dominio Avaliacao, inteiro v&aacute;lido entre 0 e 5 inclusivo. \n
    232029274 - implementa&ccedil;&atilde;o. \n
    232002771 - documenta&ccedil;&atilde;o. \n
    232013031 - construtores, exceções, documentação.
*/

class Avaliacao
{
    private:

        //! Um int.
        /*! Armazena o valor da avalia&ccedil;&atilde;o. */
        int avaliacao;

        //! Avaliacao::validar()
        /*!
          Verifica se o valor da avalia&ccedil;&atilde;o est&aacute; no intervalo de 0 a 5.
          @param int valor a validar
        */
        void validar(int);

    public:

        //! Construtor Vazio
        /*!
            Constrói um objeto Avaliacao com valor vazio.
            @sa Avaliacao(int)
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
        */
        void setValor(int);

        //! Avalicao::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Avaliacao.
          @return int o valor da avalia&ccedil;&atilde;o.
        */
        int getValor() const;
};

inline int Avaliacao::getValor() const
{
        return avaliacao;
}

#endif // AVALIACAO_HPP_INCLUDED
