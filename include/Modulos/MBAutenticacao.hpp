#ifndef MBAUTENTICACAO_HPP_INCLUDED
#define MBAUTENTICACAO_HPP_INCLUDED

#include "../Interfaces/IBAutenticacao.hpp"
#include <sqlite3.h>

class MBAutenticacao : public IBAutenticacao
{
    private:
        sqlite3* banco;

        IBConta* cntrIBConta;

    public:
        MBAutenticacao();
        ~MBAutenticacao();

        bool autenticar(Conta);
        void setCntrIBConta(IBConta*);
};

inline void MBAutenticacao::setCntrIBConta(IBConta* novo)
{
    this->cntrIBConta = novo;
}

#endif // MBAUTENTICACAO_HPP_INCLUDED
