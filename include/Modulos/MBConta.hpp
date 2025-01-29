#ifndef MBCONTA_HPP_INCLUDED
#define MBCONTA_HPP_INCLUDED

#include "Interfaces/IBConta.hpp"
#include <sqlite3.h>

class MBConta : public IBConta
{
    private:
        sqlite3* banco;

        IBViagem* cntrIBViagem;

    public:
        MBConta();
        ~MBConta();

        bool criar(Conta);
        bool excluir(Conta);
        bool ler(Codigo);
        bool atualizar(Conta, Senha);
        void setCntrIBViagem(IBViagem*);
};

inline void MBConta::setCntrIBViagem(IBViagem* novo)
{
    this->cntrIBViagem = novo;
}

#endif // MBCONTA_HPP_INCLUDED
