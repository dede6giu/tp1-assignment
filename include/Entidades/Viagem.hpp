#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

using namespace std;

class Viagem {
    private:
        Avaliacao avaliacao;
        Codigo codigo;
        Nome nome;
    public:
        void setAvaliaca(const Avaliacao&);
        Codigo getAvaliacao() const;
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Codigo getNome() const;
};

#endif // VIAGEM_HPP_INCLUDED
