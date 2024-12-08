#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include <string>
#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Horario.hpp"
#include "Dominios/Duracao.hpp"
#include "Dominios/Dinheiro.hpp"
#include "Dominios/Avaliacao.hpp"

//! Entidade Atividade
/*!
    232029274 - implementação \n
    232002520 - implementação
*/

class Atividade {
private:
    Codigo codigo;
    Nome nome;
    Data data;
    Horario horario;
    Duracao duracao;
    Dinheiro preco;
    Avaliacao avaliacao;

public:
    Atividade();

    void setValor(const Codigo &codigo);
    void setValor(const Nome &nome);
    void setValor(const Data &data);
    void setValor(const Horario &horario);
    void setValor(const Duracao &duracao);
    void setValor(const Dinheiro &preco);
    void setValor(const Avaliacao &avaliacao);

    inline Codigo       getCodigo()     const { return this->codigo; }
    inline Nome         getNome()       const { return this->nome; }
    inline Data         getData()       const { return this->data; }
    inline Horario      getHorario()    const { return this->horario; }
    inline Duracao      getDuracao()    const { return this->duracao; }
    inline Dinheiro     getPreco()      const { return this->preco; }
    inline Avaliacao    getAvaliacao()  const { return this->avaliacao; }

    std::string getAtividade() const;
};
#endif // ATIVIDADE_HPP


