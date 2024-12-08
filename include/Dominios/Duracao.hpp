#ifndef DURACAO_HPP_INCLUDED
#define DURACAO_HPP_INCLUDED

//! Classe Duracao
/*!
    Classe Duracao, inteiro entre 0 e 360 \n
    232002771 - implementa&ccedil;&atilde;o, documenta&ccedil;&atilde;o, exce��es \n
    232013031 - construtores \n
    232006028 - documentação
*/

class Duracao
{
    private:
        //! Um int.
        /*! Armazena o valor da dura&ccedil;&atilde;o. */
        int duracao;

        //! Duracao::validar()
        /*!
          Verifica se o valor da dura&ccedil;&atilde;o est&aacute; no intervalo de 0 a 360.
        */
        void validar(int);

    public:
        //! Construtor vazio
        /*! Constrói um objeto Duracao vazio. */
        Duracao();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Duracao e recebe um int com o valor de duracao.
            @param int duracao.
        */
        Duracao(int);

        //! Um inteiro p&uacute;blico
        /*!
          Armazena a quantidade m&aacute;xima da dura&ccedil;&atilde;o.
          @param int valor a validar
        */
        static const int MAXIMO = 360;

        //! Duracao::setValor()
        /*!
            Recebe um int, verifica se é válido e guarda no objeto se a verificação tiver sucesso.
            @param int duracao
        */
        void setValor(int);

        //! Duracao::getValor()
        /*!
            Retorna um int com o valor da duracao armazenada.
            @return int duracao
        */
        int getValor() const;
};

inline int Duracao::getValor() const
{
    return duracao;
}

#endif // DURACAO_HPP_INCLUDED
