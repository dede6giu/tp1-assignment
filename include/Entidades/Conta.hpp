#ifndef CONTA_H
#define CONTA_H
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
        Conta(Codigo codigo, Senha senha)
        bool setCodigo(const Codigo&)
        Codigo getCodigo() const;
        bool setSenha(const Senha&);
        Senha getSenha() const;

};

#endif // CONTA_H
