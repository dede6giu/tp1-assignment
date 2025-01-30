#ifndef MFCONTA_HPP_INCLUDED
#define MFCONTA_HPP_INCLUDED
#include "IFConta.hpp"
#include "IBConta.hpp"
#include "../Entidade/Conta.hpp"

class MIFConta : public IFConta {
private:

    IBConta* cntrIBConta;

public:
    //Construtora
    MIFConta() : ibConta(nullptr)

    // Implementação do método criar
    bool criar()

    // Implementação do método setCntrIBConta
    void setCntrIBConta(IBConta*)
    // Destrutor
    ~MIFConta()
};



#endif // MFCONTA_HPP_INCLUDED
