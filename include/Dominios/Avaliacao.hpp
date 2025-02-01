#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED

//! Dominio Avaliacao
/*!
    Dominio Avaliacao, inteiro válido entre 0 e 5 inclusivo. \n
    232029274 - implementação. \n
    232002771 - documentação. \n
    232013031 - construtores, exceções, documentação. \n
    232002520 - documentação
*/

class Avaliacao
{
    private:

        //! Valor de avaliação
        /*! Atributo inteiro referente à avaliação. */
        int avaliacao;

        //! Avaliacao::validar()
        /*!
          Verifica se o valor da avaliação está no intervalo de 0 a 5.
          @param int valor a validar
        */
        void validar(int);

    public:

        //! Construtor Vazio
        /*!
            Constrói um objeto Avaliacao vazio.
            @sa Avaliacao(int)
        */
        Avaliacao();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Avaliacao e recebe um int com o valor de avaliação.
            @param int avaliacao.
        */
        Avaliacao(int);

        //! Avaliacao::setValor()
        /*!
          Atribui novo valor referente à avaliação, se for válido.
          @param int novo valor.
        */
        void setValor(int);

        //! Avalicao::getValor()
        /*!
          Retorna o valor da avaliação.
          @return int o valor da avaliacao.
        */
        int getValor() const;
};

inline int Avaliacao::getValor() const
{
        return avaliacao;
}

#endif // AVALIACAO_HPP_INCLUDED
