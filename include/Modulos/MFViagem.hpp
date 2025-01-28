#ifndef VIAGEM_HPP_INCLUDED
#define VIAGEM_HPP_INCLUDED

#include <string>
#include <iostream>
#include "../Entidades/Conta.hpp"
#include "IFViagem.hpp"

// Classe responsável pelo gerenciamento de viagens
class Viagem : public IFViagem {
private:
    IFViagem* referenciaIFViagem; // Dependência da interface de viagens

public:
    void run(Conta* conta) override;

    void setCntrIBViagem(IBViagem* referencia) override;

    ~Viagem() override;
};

#endif // VIAGEM_HPP_INCLUDED

