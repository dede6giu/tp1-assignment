#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

#include <string>

//! Classe Dinheiro
/*!
    Classe Dinheiro, int de 0 a 20000000, implementado como centavos\n
    232002771 - implementa&ccdeil;&atilde;o\n
    232013031 - altera&ccedil;&otilde;es na implementa&ccdeil;&atilde;o \n
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
            Recebe um valor int e verifica se ele é válido (>= Dinheiro::MINIMO e < Dinheiro::MAXIMO).
            @param int valor a validar
            @return resultado da verificação
        */
        bool validar(int);

    public:
        //! static int const
        /*! Int estático constante com o valor mínimo de dinheiro possível. */
        static int const MINIMO = 0;
        //! static int const
        /*! Int estático constante com o valor máximo de dinheiro possível. */
        static int const MAXIMO = 20000000;

        //! Construtor vazio
        /*! Constrói um objeto Dinheiro vazio. */
        Dinheiro();
        //! Construtor paramétrico
        /*!
            Constrói um objeto Dinheiro e recebe um int com o valor de dinheiro.
            @param int dinheiro
        */
        Dinheiro(int);

        //! bool Dinheiro::setValor(int)
        /*!
            Recebe um int, verifica se é válido e guarda no objeto se a verificação tiver sucesso.
            @param int dinheiro
            @return bool indicando se a operação teve sucesso.
        */
        bool setValor(int);
        //! int Dinheiro::getValor(int)
        /*! Retorna um int com o valor do dinheiro armazenado. */
        int getValor() const;
        //! std::string Dinheiro::getValorFormatado() const
        /*! Retorna uma string do dinheiro formatado. */
        std::string getValorFormatado() const;
};

inline int Dinheiro::getValor() const
{
    return dinheiro;
}

#endif // DINHEIRO_HPP_INCLUDED
