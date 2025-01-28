#ifndef IFDADOS_HPP_INCLUDED
#define IFDADOS_HPP_INCLUDED

#include "Entidades/Conta.hpp"
#include "IFAtividade.hpp"
#include "IFConta.hpp"
#include "IFDestino.hpp"
#include "IFHospedagem.hpp"
#include "IFViagem.hpp"

//! Interface Front Dados
/*!
    232013031 - implementação \n

    A IFDados atua como conectora de todos os serviços relacionados ao
    armazenamento de dados do programa. No caso, ela realiza uma conexão
    com IFAtividade, IFDestino, IFHospedagem e IFViagem.
*/

class IFDados
{
    public:

        //! Inicia a IFDados
        /*!
            Inicia a Interface Front Dados, requisitando do usuário qual
            tipo de informação deseja trabalhar com. As opções são: Atividade,
            Conta, Destino, Hospedagem, Viagem. \n
            @param Ponteiro da Conta atualmente autenticada.
        */
        virtual void run(Conta*) = 0;

        //! Dependência da IFAtividade
        /*!
            Estabelece uma referência para a IFAtividade como uma variável,
            permitindo uma conexão com os métodos relacionados ao manejamento
            de Atividade associadas à conta.
            @param Referência à IFAtividade a ser salva.
        */
        virtual void setCntrIFAtividade(IFAtividade*) = 0;

        //! Dependência da IFConta
        /*!
            Estabelece uma referência para a IFConta como uma variável,
            permitindo uma conexão com os métodos relacionados ao manejamento
            da Conta do usuário.
            @param Referência à IFConta a ser salva.
        */
        virtual void setCntrIFConta(IFConta*) = 0;

        //! Dependência da IFDestino
        /*!
            Estabelece uma referência para a IFDestino como uma variável,
            permitindo uma conexão com os métodos relacionados ao manejamento
            de Destino associadas à conta.
            @param Referência à IFDestino a ser salva.
        */
        virtual void setCntrIFDestino(IFDestino*) = 0;

        //! Dependência da IFHospedagem
        /*!
            Estabelece uma referência para a IFHospedagem como uma variável,
            permitindo uma conexão com os métodos relacionados ao manejamento
            de Hospedagem associadas à conta.
            @param Referência à IFHospedagem a ser salva.
        */
        virtual void setCntrIFHospedagem(IFHospedagem*) = 0;

        //! Dependência da IFViagem
        /*!
            Estabelece uma referência para a IFViagem como uma variável,
            permitindo uma conexão com os métodos relacionados ao manejamento
            de Viagem associadas à conta.
            @param Referência à IFViagem a ser salva.
        */
        virtual void setCntrIFViagem(IFViagem*) = 0;

        //! Destrutor Virtual
        virtual ~IFDados(){};
};

#endif // IFDADOS_HPP_INCLUDED
