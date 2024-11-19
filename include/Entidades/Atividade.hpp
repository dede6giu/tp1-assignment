#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Horario.hpp"
#include "Dominios/Duracao.hpp"
#include "Dominios/Dinheiro.hpp"
#include "Dominios/Avaliacao.hpp"

//! entidade Atividade
/*!
    232029274 - implementação \n
    232002520 - documentação
*/

class Atividade {
private:
    //! Objeto Codigo
    /*! Atributo do tipo Codigo do objeto Atividade. */
    Codigo codigo;
    //! Objeto Nome
    /*! Atributo do tipo Nome do objeto Atividade. */
    Nome nome;
    //! Objeto Data
    /*! Atributo do tipo Data do objeto Atividade. */
    Data data;
    //! Objeto Horario
    /*! Atributo do tipo horario do objeto Atividade. */
    Horario horario;
    //! Objeto Codigo
    /*! Atributo do tipo Codigo do objeto Atividade. */
    Duracao duracao;
    //! Objeto Codigo
    /*! Atributo do tipo Codigo do objeto Atividade. */
    Dinheiro preco;
    //! Objeto Codigo
    /*! Atributo do tipo Codigo do objeto Atividade. */
    Avaliacao avaliacao;

public:
    //! Construtor vazio
    /*! Constrói um objeto Atividade vazio. */
    Atividade();

    //! Atividade::setValor(const Codigo&)
    /*! Recebe um objeto Codigo e armazena no objeto. */
    void setValor(const Codigo &);
    //! Atividade::setValor(const Nome&)
    /*! Recebe um objeto Nome e armazena no objeto. */
    void setValor(const Nome &);
    //! Atividade::setValor(const Data&)
    /*! Recebe um objeto Data e armazena no objeto. */
    void setValor(const Data &);
    //! Atividade::setValor(const Horario&)
    /*! Recebe um objeto Horario e armazena no objeto. */
    void setValor(const Horario &);
    //! Atividade::setValor(const Duracao&)
    /*! Recebe um objeto Duracao e armazena no objeto. */
    void setValor(const Duracao &);
    //! Atividade::setValor(const Dinheiro&)
    /*! Recebe um objeto Dinheiro e armazena no objeto. */
    void setValor(const Dinheiro &);
    //! Atividade::setValor(const Avaliacao&)
    /*! Recebe um objeto Avaliacao e armazena no objeto. */
    void setValor(const Avaliacao &);

    //! inline Codigo Atividade::getCodigo() const
    /*! Retorna o objeto Codigo da atividade. */
    inline Codigo       getCodigo() const { return this->codigo; }
    //! inline Nome Avaliacao::getNome() const
    /*! Retorna o objeto Nome da atividade. */
    inline Nome           getNome() const { return this->nome; }
    //! inline Data Avaliacao::getData() const
    /*! Retorna o objeto Data da atividade. */
    inline Data           getData() const { return this->data; }
    //! inline Horario Avaliacao::getHorario() const
    /*! Retorna o objeto Horario da atividade. */
    inline Horario     getHorario() const { return this->horario; }
    //! inline Duracao Avaliacao::getDuracao() const
    /*! Retorna o objeto Duracao da atividade. */
    inline Duracao     getDuracao() const { return this->duracao; }
    //! inline Dinheiro Avaliacao::getPreco() const
    /*! Retorna o objeto Dinheiro com o preço da atividade. */
    inline Dinheiro      getPreco() const { return this->preco; }
    //! inline Avaliacao Avaliacao::getAvaliacao() const
    /*! Retorna o objeto Avaliacao da atividade. */
    inline Avaliacao getAvaliacao() const { return this->avaliacao; }
};

#endif // ATIVIDADE_HPP
