#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

//! Entidade Conta
/*
    232002771 - implementação da entidade conta
*/

class Conta
{
    private:
        Codigo codigo;
        Senha senha;

    public:
        bool setCodigo(const Codigo&)
        Codigo getCodigo() const;
        bool setSenha(const Senha&);
        Senha getSenha() const;

};

inline int Conta::getValor() const
{
    return codigo;
}

inline int Senha::getValor() const
{
    return senha;
}

#endif // CONTA_HPP_INCLUDED
