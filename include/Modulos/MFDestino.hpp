#ifndef MFDESTINO_HPP_INCLUDED
#define MFDESTINO_HPP_INCLUDED

#include <curse.h>
#include "IBDestino.hpp"
#include "Entidades/Conta.hpp"

class MFDestino: IFDestino{
private:
    IBDestino* ibDestino;
public:
    void run(Conta*) = 0;
    void setCntrIBDestino(IBDestino*) = 0;
    ~IFDestino() {};
}

#endif // MFDESTINO_HPP_INCLUDED
