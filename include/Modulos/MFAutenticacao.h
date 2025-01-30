#ifndef MFAUTENTICACAO_HPP_INCLUDED
#define MFAUTENTICACAO_HPP_INCLUDED

#include <curses.h>
#include "IBAutenticacao.hpp"
#include "Entidades/Conta.hpp"


class MFAutenticacao : IFAutenticacao{
private:
    IBAutenticacao* ibAutenticacao;
public:
    void run(Conta* Conta) = 0;
    void setCntrIBAutenticacao(IBAutenticacao* ibAutenticacao) = 0;
    ~IFAutenticacao(){};
}


#endif // MFAutenticacao_HPP_INCLUDED
