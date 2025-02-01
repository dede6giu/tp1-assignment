#ifndef DURACAO_HPP_INCLUDED
#define DURACAO_HPP_INCLUDED

//! Dominio Duracao
/*!
    Dominio Duracao, inteiro entre 0 e 360 \n
    232002771 - implementação, documentação, exceções \n
    232013031 - construtores \n
    232006028 - documentação \n
    232002520 - documentação
*/

class Duracao
{
    private:
        //! Valor de duração
        /*! Atributo inteiro referente ao valor da duração. */
        int duracao;

        //! Duracao::validar()
        /*!
          Verifica se o valor da duração está no intervalo de 0 a 360.
        */
        void validar(int);

    public:
        //! Valor máximo de duração
        /*!
          Atributo inteiro estático constante com o valor máximo possível de duração.
        */
        static const int MAXIMO = 360;

        //! Construtor vazio
        /*! Constrói um objeto Duracao vazio. */
        Duracao();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Duracao, recebe e armazena um int com o valor de duracao.
            @param int com o valor de duração.
        */
        Duracao(int);

        //! Duracao::setValor()
        /*!
            Recebe um int, verifica se é válido e guarda no objeto se a verificação tiver sucesso.
            @param int com novo valor de duração.
        */
        void setValor(int);

        //! Duracao::getValor()
        /*!
            Retorna um int com o valor da duracao armazenada.
            @return int com o valor atual de duração.
        */
        int getValor() const;
};

inline int Duracao::getValor() const
{
    return duracao;
}

#endif // DURACAO_HPP_INCLUDED
