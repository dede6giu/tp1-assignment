#ifndef MFCONTA_HPP_INCLUDED
#define MFCONTA_HPP_INCLUDED
#include "IFConta.hpp"
#include "../Entidade/Conta.hpp"
#include <iostream>

class MIFConta : public IFConta {
private:
    IBConta* ibConta; // Referência para a interface de banco de dados

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
