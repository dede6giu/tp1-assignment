#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

#include <string>

//! Dominio Horario
/*!
    Dominio Horario, string de 5 caracteres composta por "HH:mm", impressa em formato de 24h. Internamente salva como dois inteiros, um para horas e outro para minutos.\n
    232013031 - implementação, construtores \n
    232002520 - documentação, exceções, implementação \n
    232002771 - documentação \n
    232006028 - documentação
*/

class Horario
{
    private:
        //! Um int
        /*! Armazena o valor das horas */
        int horas;

        //! Um int
        /*! Armazena o valor dos minutos */
        int minutos;

        //! bool Horario::validar(std::string)
        /*!
            Recebe uma string e verifica se ela é válida (tamanho exatamente igual 5 e se o terceiro caractere é ":").
            @param string é ser analisada.
        */
        void validar(std::string);

        //! Horario::validarHoras()
        /*!
            Verifica se o valor de um int está no intervalo 0 e 24 (24 não incluso).
            @param int a ser verificado.
        */
        void validarHoras(int);

        //! Horario::validarHoras()
        /*!
            Verifica se o valor de um int está entre 0 e 60 (60 não incluso).
            @param int a ser verificado.
        */
        void validarMinutos(int);

    public:

        //! Construtor vazio
        /*!
            Constrói um objeto Horario vazio.
            @sa Horario(int, int)
        */
        Horario();

        //! Construtor paramétrico
        /*!
            Constrói um objeto Horario, verifica os parâmetros passados e
            salva os valores dentro do objeto.
            @param int com as horas.
            @param int com os minutos.
            @sa Nome(), Horario::setValor().
        */
        Horario(int, int);

        Horario(std::string);

        void setValor(std::string);

        //! Horario::setValor()
        /*!
            Armazena 2 novos valores na classe: horas e minutos, respectivamente.
            @param int com o novo valor das horas.
            @param int com o novo valor dos minutos.
        */
        void setValor(int, int);

        //! Horario::setValorHoras()
        /*!
            Recebe um int, o verifica e salva no atributo horas da classe.
            @param int com o novo valor das horas.
        */
        void setValorHoras(int);

        //! Horario::setValorMinutos()
        /*!
            Recebe um int, o verifica e salva no atributo minutos da classe.
            @param int com o novo valor dos minutos.
        */
        void setValorMinutos(int);

        //! Horario::getValor()
        /*!
            Retorna std::string com o horário, no formato "HH:mm".
            @return std::string com o horário.
        */
        std::string getValor() const;

        //! Horario::getValorHoras()
        /*!
            Retorna um int com o valor das horas.
            @return int com o valor das horas.
        */
        int getValorHoras() const;

        //! Horario::getValorMinutos()
        /*!
            Retorna um int com o valor dos minutos.
            @return int com o valor dos minutos.
        */
        int getValorMinutos() const;
};

inline int Horario::getValorHoras() const
{
    return this->horas;
}

inline int Horario::getValorMinutos() const
{
    return this->minutos;
}

#endif // HORARIO_HPP_INCLUDED
