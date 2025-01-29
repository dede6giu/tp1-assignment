#ifndef MFHOSPEDAGEM_HPP_INCLUDED
#define MFHOSPEDAGEM_HPP_INCLUDED

#include "../Entidades/Conta.hpp"
#include "IBAutenticacao.hpp"

class MFHospedagem : IFHospedagem{
private:
        IBHospedagem* iBHospedagem;
public:
    virtual void run(Conta*) = 0;

    //! Dependência da IBHospedagem
    virtual void setCntrIBHospedagem(IBHospedagem*) = 0;

    //! Destrutor Virtual
    virtual ~IFHospedagem();
}/*!
            Estabelece uma referência para a IBHospedagem como uma variável,
            permitindo uma conexão com os métodos atuantes no banco de dados.
            @param Referência à IBHospedagem a ser salva.
        */


#endif // MFHOSPEDAGEM_HPP_INCLUDED
