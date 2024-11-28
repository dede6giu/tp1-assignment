#ifndef DURACAO_HPP_INCLUDED
#define DURACAO_HPP_INCLUDED

//! Classe Duracao
/*!
    Classe Duracao, inteiro entre 0 e 360 \n
    232002771 - implementa&ccedil;&atilde;o, documenta&ccedil;&atilde;o. \n
    232013031 - construtores
*/

class Duracao
{
    private:
        //! Um int.
        /*! Armazena a o valor da dura&ccedil;&atilde;o. */
        int duracao;

        //! Duracao::validar()
        /*!
          Verifica se o valor da dura&ccedil;&atilde;o est&aacute; no intervalo de 0 a 360.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
        */
        void validar(int);

    public:
        Duracao();
        Duracao(int);

        //! Um inteiro p&uacute;blico
        /*!
          Armazena a quantidade m&aacute;xima da dura&ccedil;&atilde;o.
          @sa validar()
        */
        static const int MAXIMO = 360;

        //! Duracao::setValor()
        /*!
          Armazena um novo valor dentro da classe.
          @param int novo valor.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
          @sa getValor(), Duracao::validar()
        */
        void setValor(int);

        //! Duracao::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Duracao.
          @return O valor da dura&ccedil;&atilde;o.
        */
        int getValor() const;
};

inline int Duracao::getValor() const
{
    return duracao;
}

#endif // DURACAO_HPP_INCLUDED
