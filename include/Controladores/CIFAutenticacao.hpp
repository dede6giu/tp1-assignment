#ifndef CIFAUTENTICACAO_HPP_INCLUDED
#define CIFAUTENTICACAO_HPP_INCLUDED

#include "../Interfaces/IFAutenticacao.hpp"
#include "../Interfaces/IBAutenticacao.hpp"
#include "../Entidades/Conta.hpp"

class CIFAutenticacao : public IFAutenticacao
{
    private:

        IBAutenticacao* cntrIBAutenticacao;

    public:

        bool run(Conta*);
        void setCntrIBAutenticacao(IBAutenticacao*);
};

void inline CIFAutenticacao::setCntrIBAutenticacao(IBAutenticacao* novo)
{
    this->cntrIBAutenticacao = novo;
}

#endif // CIFAUTENTICACAO_HPP_INCLUDED
