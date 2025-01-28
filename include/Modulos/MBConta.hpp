#ifndef MBCONTA_HPP_INCLUDED
#define MBCONTA_HPP_INCLUDED

#include "Interfaces/IBConta.hpp"
#include <sqlite3.h>

class MBConta : public IBConta
{
    private:
        sqlite3* banco;

    public:
        MBConta();
        ~MBConta();

        bool criar(Conta);
        bool excluir(Conta);
        bool ler(Codigo);
        bool atualizar(Conta, Senha);
};

#endif // MBCONTA_HPP_INCLUDED
