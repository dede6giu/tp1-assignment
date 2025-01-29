#ifndef MFATIVIDADE_HPP_INCLUDED
#define MFATIVIDADE_HPP_INCLUDED

#include <curses.h>
#include "IBAtividade.hpp"
#include "Entidades/Conta.hpp"


class MFAtividade : IFAtividade{
private:
    IBAtividade* ibAtividade;
public:
    void run(Conta* Conta) = 0;
    void setCntrIBAtividade(IBAtividade* ibAtividade) = 0;
    ~IFAtividade(){};
}


#endif // MFATIVIDADE_HPP_INCLUDED
