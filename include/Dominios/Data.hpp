#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

//! Classe Data
/*!
    Classe Data, formato "DD/MM/AA", salvo como três inteiros,
    tal que 01 <= DD <= 31, 01 <= MM <= 12 e 00 <= AA <= 99, seguindo as
    devidas quantidades de dias no mês.\n

    232013031 - implementação, construtores, documentação. \n
    232002520 - documentação, exceções. \n
    232002771 - documentação.
*/

class Data
{
    private:

        //! Um int
        /*! Atributo inteiro que armazena o dia. */
        int dia;

        //! Um int
        /*! Atributo inteiro que armazena o mês.*/
        int mes;

        //! Um int
        /*! Atributo inteiro que armazena o ano.*/
        int ano;

        //! Data::validar(int, int, int)
        /*!
            Recebe três valores inteiros, verifica se são valores válidos para
            dia (>0), mês (> 0 e <= 12) e ano (>=0 e >= 99), respectivamente.
            @param int dia
            @param int mes
            @param int ano
            @sa validar(std::string)
        */
        void validar(int, int, int);

        //! Data::validar(int, int, int)
        /*!
            Recebe um valor string e verifica se tal é um formato válido de data. \n
            Note que <u>não</u> verifica se o valor na data é válido.
            @param string data formatada no formato "DD/MM/AA"
            @sa validar(int, int, int)
        */
        void validar(std::string);

    public:

        //! Construtor vazio
        /*! Cria um objeto Data vazio. */
        Data();

        //! Construtor paramétrico (versão int)
        /*!
            Constrói um objeto Data. Recebe três ints com o dia, mês e ano, respectivamente.
            @param int dia
            @param int mes
            @param int ano
            @sa Data(std::string)
        */
        Data(int, int, int);

        //! Construtor paramétrico (versão string)
        /*!
            Constrói um objeto Data. Recebe um string no formato "DD/MM/AA".
            @param string data no formato "DD/MM/AA"
            @sa Data(int, int, int)
        */
        Data(std::string);

        //! int Data::getDia() const
        /*! Retorna um int com o valor do dia. */
        int getDia() const;

        //! int Data::getMes() const
        /*! Retorna um int com o valor do mês. */
        int getMes() const;

        //! int Data::getAno() const
        /*! Retorna um int com o valor do ano.*/
        int getAno() const;

        //! bool Data::setValor(int, int, int)
        /*!
            Recebe três valores inteiros para o dia, o mês e o ano, respectivamente,
            e guarda esses valores na classe, se a verificação tiver sucesso.
            @param int dia
            @param int mes
            @param int ano
        */
        void setValor(int, int, int);

        //! bool Data::setValor(std::string)
        /*!
            Recebe uma string com o novo valor do objeto data,
            e guarda esse valor na classe, se a verificação tiver sucesso.
            @param string data no formato "DD/MM/AA"
        */
        void setValor(std::string);

        //! std::string Data::getValor() const
        /*! Retorna um string com a data no formato "DD/MM/AA". */
        std::string getValor() const;
};

inline int Data::getDia() const
{
    return this->dia;
}

inline int Data::getMes() const
{
    return this->mes;
}

inline int Data::getAno() const
{
    return this->ano;
}

#endif // DATA_HPP_INCLUDED
