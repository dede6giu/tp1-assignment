#ifndef IBVIAGEM_HPP_INCLUDED
#define IBVIAGEM_HPP_INCLUDED

#include "../Entidades/Viagem.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "../Dominios/Nome.hpp"

//! Interface Back Viagem
/*!
    232002520 - implementação \n

    A IBViagem é responsável pela comunicação entre o usuário e o banco de dados quanto ao controle das Viagens. Ela permite criar, excluir, ler e atualizar Viagem.
*/

class IBViagem {
    public:

        virtual bool criar(Viagem) = 0;
        virtual bool excluir(Viagem) = 0;
        virtual bool ler(Viagem) = 0;
        virtual bool atualizar(Viagem, Avaliacao) = 0;
        virtual bool atualizar(Viagem, Nome) = 0;
        virtual ~IBViagem() = 0;
};

#endif // IBVIAGEM_HPP_INCLUDED
