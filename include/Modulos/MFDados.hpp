#ifndef MFDADOS_HPP_INCLUDED
#define MFDADOS_HPP_INCLUDED

#include "IFDados.hpp"
#include "Entidades/Conta.hpp"
#include "IFAtividade.hpp"
#include "IFConta.hpp"
#include "IFDestino.hpp"
#include "IFHospedagem.hpp"
#include "IFViagem.hpp"

//! Implementação da IFDados
/*!
    Esta classe implementa a interface IFDados, conectando e gerenciando
    as dependências das interfaces de Atividade, Conta, Destino, Hospedagem e Viagem.
*/
class Dados : public IFDados
{
private:
    IFAtividade* cntrIFAtividade;   // Referência para IFAtividade
    IFConta* cntrIFConta;           // Referência para IFConta
    IFDestino* cntrIFDestino;       // Referência para IFDestino
    IFHospedagem* cntrIFHospedagem; // Referência para IFHospedagem
    IFViagem* cntrIFViagem;         // Referência para IFViagem

public:
    //! Construtor
    Dados();

    //! Implementação do método run
    void run(Conta* conta) override;

    //! Implementação do método setCntrIFAtividade
    void setCntrIFAtividade(IFAtividade* cntrIFAtividade) override;

    //! Implementação do método setCntrIFConta
    void setCntrIFConta(IFConta* cntrIFConta) override;

    //! Implementação do método setCntrIFDestino
    void setCntrIFDestino(IFDestino* cntrIFDestino) override;

    //! Implementação do método setCntrIFHospedagem
    void setCntrIFHospedagem(IFHospedagem* cntrIFHospedagem) override;

    //! Implementação do método setCntrIFViagem
    void setCntrIFViagem(IFViagem* cntrIFViagem) override;

    //! Destrutor
    ~Dados() override;
};


#endif // MFDADOS_HPP_INCLUDED
