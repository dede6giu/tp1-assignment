#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Horario.hpp"
#include "../Dominios/Duracao.hpp"
#include "../Dominios/Dinheiro.hpp"
#include "../Dominios/Avaliacao.hpp"

//! entidade Atividade
/*!
    232029274 - implementação
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

    void setValor(const Codigo &);
    void setValor(const Nome &);
    void setValor(const Data &);
    void setValor(const Horario &);
    void setValor(const Duracao &);
    void setValor(const Dinheiro &);
    void setValor(const Avaliacao &);

    inline Codigo       getCodigo() const { return codigo; }
    inline Nome           getNome() const { return nome; }
    inline Data           getData() const { return data; }
    inline Horario     getHorario() const { return horario; }
    inline Duracao     getDuracao() const { return duracao; }
    inline Dinheiro      getPreco() const { return preco; }
    inline Avaliacao getAvaliacao() const { return avaliacao; }
};

#endif // ATIVIDADE_HPP


