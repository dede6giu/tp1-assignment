#ifndef IBVIAGEM_HPP_INCLUDED
#define IBVIAGEM_HPP_INCLUDED

#include "../Entidades/Viagem.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "../Dominios/Nome.hpp"
#include "../Interfaces/IBDestino.hpp"
#include <vector>

//! Interface Back Viagem
/*!
    232002520 - implementação \n

    A IBViagem é responsável pela comunicação entre o usuário e o
    banco de dados quanto ao controle das Viagens. Ela permite criar,
    excluir, ler e atualizar Viagem.
*/

class IBViagem {
    public:

        virtual bool criar(Viagem) = 0;
        virtual void criar(Codigo) = 0;
        virtual bool excluir(Viagem) = 0;

        //! Exclui uma Tabela
        /*!
            Recebe um Codigo e exclui a tabela associada ao Codigo. Método só deve
            ser usado durante a exclusão de Conta.
            @param Codigo da Conta excluída.
            @return Sucesso da operação.
        */
        virtual void excluir(Codigo) = 0;
        virtual bool ler(Viagem) = 0;
        virtual std::vector<Viagem> ler(Codigo) = 0;
        virtual bool atualizar(Viagem, Avaliacao) = 0;
        virtual bool atualizar(Viagem, Nome) = 0;

        //! Dependência da IBDestino
        /*!
            Estabelece uma referência para a IBDestino como uma variável, permitindo
            acesso ao banco de dados pelos métodos da IBDestino.
            @param Referência à IBDestino a ser salva.
        */
        virtual void setCntrIBDestino(IBDestino*) = 0;

        virtual ~IBViagem(){};
};

#endif // IBVIAGEM_HPP_INCLUDED
