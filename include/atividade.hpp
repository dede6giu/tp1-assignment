#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

//! Entidade Atividade
/* 
    232029274 - implementação entidade Atividade
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
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
    
        void setNome(const Nome&);
        Nome getNome() const;
    
        void setData(const Data&);
        Data getData() const;
    
        void setHorario(const Horario&);
        Horario getHorario() const;
    
        void setDuracao(const Duracao&);
        Duracao getDuracao() const;
    
        void setPreco(const Dinheiro&);
        Dinheiro getPreco() const;
    
        void setAvaliacao(const Avaliacao&);
        Avaliacao getAvaliacao() const;
};

#endif // ATIVIDADE_HPP_INCLUDED
