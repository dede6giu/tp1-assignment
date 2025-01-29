#include <curse.h>
#include "IBDestino.hpp"

MFDestino::run(Conta* conta) override{
    //Implementacao
}

MFDestino::setCntrIBDestino(IBDestino* ibDestino) override{
    this->ibDestino=ibDestino;
}
MFDestino::~IFDestino() override{
    ibDestino = nullptr;
}
