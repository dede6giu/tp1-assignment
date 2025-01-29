#include <curses.h>
#include "MFAtividade.hpp"
#include <iostream>

MFAtividade::run(conta* Conta)override{
    //A se implementar ainda.
}

MFAtividade::setCntrIBAtividade(IBAtividade* ibAtividade) override{
    this->ibAtividade=ibAtividade;
}
Dados::~Dados() {
    ibAtividade = nullptr;
}
