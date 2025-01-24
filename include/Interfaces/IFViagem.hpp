#ifndef IFVIAGEM_HPP_INCLUDED
#define IFVIAGEM_HPP_INCLUDED

#include "IBViagem.hpp"

//! Interface Front Viagem
/*!
    232002520 - implementação \n

    A IFViagem é responsável pela chamada do método que inicia a criação de Viagem.
*/

class IFViagem {
    public:

        virtual bool criar() = 0;
        virtual void setCntrIBViagem(IBViagem*) = 0;
        virtual ~IFViagem(){};
};

#endif // IFVIAGEM_HPP_INCLUDED
