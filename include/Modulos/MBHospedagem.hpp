#ifndef MBHOSPEDAGEM_HPP_INCLUDED
#define MBHOSPEDAGEM_HPP_INCLUDED

#include "../Interfaces/IBHospedagem.hpp"
#include "../../libraries/sqlite3.h"

/*!
    232013031 - Implementação.
*/
class MBHospedagem : public IBHospedagem
{
    private:

        sqlite3* banco;

    public:

        MBHospedagem();
        ~MBHospedagem();

        bool criar(Hospedagem);
        void criar(Codigo);
        bool excluir(Hospedagem);
        void excluir(Codigo);
        void excluir(Codigo, Codigo);
        bool ler(Hospedagem);
        std::vector<Hospedagem> ler(Codigo, Codigo);
        bool atualizar(Hospedagem, Nome);
        bool atualizar(Hospedagem, Dinheiro);
        bool atualizar(Hospedagem, Avaliacao);
};

#endif // MBHOSPEDAGEM_HPP_INCLUDED
