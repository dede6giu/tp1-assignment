#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

//! Classe Data
/*!
    Classe Data, formato DD/MM/AA, salvo como tr&ecirc;s inteiros,
    tal que 01 <= DD <= 31, 01 <= MM <= 12 e 00 <= AA <= 99, seguindo as
    devidas quantidades de dias no m&ecirc;s.\n

    232013031 - implementa&ccdeil;&atilde;o, construtores \n
    232002520 - documentação, exce��es
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
        
        //! bool Data::validar(int, int, int)
        /*!
            Recebe três valores inteiros, verifica se são valores válidos para
            dia (>0), mês (> 0 e <= 12) e ano (>=0 e >= 99), respectivamente, e
            retorna um bool indicando o resultado da operação.
            @param int dia
            @param int mes
            @param int ano
        */
        void validar(int, int, int);

        void validar(std::string);

    public:
        //! Construtor vazio
        /*! Cria um objeto Data vazio. */
        Data();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Data que recebe três ints com o dia, mês e ano, respectivamente.
            @param int dia
            @param int mes
            @param int ano
        */
        Data(int, int, int);

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

        void setValor(std::string);

        //! std::string Data::getValor() const
        /*! Retorna um std::string com a data formatada. */
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
