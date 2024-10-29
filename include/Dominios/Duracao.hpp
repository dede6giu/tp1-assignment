#ifndef DURACAO_H
#define DURACAO_H

//! Classe Duracao
/*!
  Classe Duracao, inteiro entre 0 e 360 \n
  232002771 - implementa&ccedil;&atilde;o, documenta&ccedil;&atilde;o.

*/

class Duracao
{
    private:
        //! Um int.
        /*! Armazena a o valor da dura&ccedil;&atilde;o. */
        int valor = 0;

        //! Duracao::validar()
        /*!
          Verifica se o valor da dura&ccedil;&atilde;o est&aacute; no intervalo de 0 a 360.
          @return bool indicando sucesso da opera&ccedil;&atilde;o.
        */
        bool validar(int);

    public:
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
        bool setValor(int);

        //! Duracao::getValor()
        /*!
          Fun&ccedil;&atilde;o para obter o valor da classe Duracao.
          @return O valor da dura&ccedil;&atilde;o.
        */
        int getValor() const;
};

inline int Duracao::getValor() const
{
    return valor;
}

#endif // DURACAO_H
