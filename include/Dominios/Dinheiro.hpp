#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

#include <string>

//! Classe Dinheiro
/*!
    Classe Dinheiro, int de 0 a 20000000 inclusivo, implementado como centavos. \n
    232002771 - implementa&ccdeil;&atilde;o, exceções, documentação. \n
    232013031 - implementa&ccdeil;&atilde;o, documentação. \n
    232002520 - documentação
*/

class Dinheiro
{
    private:

        //! int
        /*! Atributo int que armazena o valor de dinheiro. */
        int dinheiro;

        //! bool Dinheiro::validar(int)
        /*!
            Recebe um valor int e verifica se ele é válido (>= Dinheiro::MINIMO e <= Dinheiro::MAXIMO).
            @param int valor a validar
        */
        void validar(int);

    public:

        //! static int const
        /*! int estático constante com o valor mínimo de dinheiro possível.
            @sa MAXIMO */
        static int const MINIMO = 0;

        //! static int const
        /*! int estático constante com o valor máximo de dinheiro possível.
            @sa MINIMO */
        static int const MAXIMO = 20000000;

        //! Construtor vazio
        /*! Constrói um objeto Dinheiro vazio.
            @sa Dinheiro(int) */
        Dinheiro();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Dinheiro e recebe um int com o valor de dinheiro em centavos.
            @param int dinheiro em centavos.
            @sa Dinheiro()
        */
        Dinheiro(int);

        //! void Dinheiro::setValor(int)
        /*!
            Recebe um int, verifica se é válido e guarda no objeto se a verificação tiver sucesso.
            @param int dinheiro
        */
        void setValor(int);

        //! int Dinheiro::getValor(int) const
        /*!
            Retorna um int com o valor do dinheiro armazenado.
            @return int dinheiro
            @sa getValorFormatado()
        */
        int getValor() const;

        //! std::string Dinheiro::getValorFormatado() const
        /*!
            Retorna uma string do dinheiro no formato "ddd.ddd.ddd,dd" onde "d" é um dígito de 0 a 9 que pode ou não existir.
            Se o valor do inteiro dinheiro é menor que 100 (centavos), retorna-se "0,dd".
            Os pontos e a vírgula só são adicionados mediante necessidade.
            @return string formatada.
            @sa getValor()
        */
        std::string getValorFormatado() const;
};

inline int Dinheiro::getValor() const
{
    return dinheiro;
}

#endif // DINHEIRO_HPP_INCLUDED
