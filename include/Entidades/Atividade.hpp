#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

//! entidade Atividade
//! 232029274 - entidade Atividade
using namespace std;

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

    void setCodigo(const Codigo &novoCodigo);
    void setNome(const Nome &novoNome);
    void setData(const Data &novaData);
    void setHorario(const Horario &novoHorario);
    void setDuracao(const Duracao &novaDuracao);
    void setPreco(const Dinheiro &novoPreco);
    void setAvaliacao(const Avaliacao &novaAvaliacao);

    inline Codigo getCodigo() const { return codigo; }
    inline Nome getNome() const { return nome; }
    inline Data getData() const { return data; }
    inline Horario getHorario() const { return horario; }
    inline Duracao getDuracao() const { return duracao; }
    inline Dinheiro getPreco() const { return preco; }
    inline Avaliacao getAvaliacao() const { return avaliacao; }
};

#endif // ATIVIDADE_HPP


