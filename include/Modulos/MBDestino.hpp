#ifndef MBDESTINO_HPP_INCLUDED
#define MBDESTINO_HPP_INCLUDED

#include "../Interfaces/IBDestino.hpp"
#include <sqlite3.h>

/*!
    232013031 - Implementação.
*/
class MBDestino : public IBDestino
{
    private:

        sqlite3* banco;

        IBAtividade* cntrIBAtividade;
        IBHospedagem* cntrIBHospedagem;

    public:

        MBDestino();
        ~MBDestino();

        bool criar(Destino);
        void criar(Codigo);
        bool excluir(Destino);
        void excluir(Codigo);
        void excluir(Codigo, Codigo);
        bool ler(Destino);
        std::vector<Destino> ler(Codigo, Codigo);
        bool atualizar(Destino, Nome);
        bool atualizar(Destino, Data, bool);
        bool atualizar(Destino, Avaliacao);

        void setCntrIBAtividade(IBAtividade*);
        void setCntrIBHospedagem(IBHospedagem*);
};

inline void MBDestino::setCntrIBAtividade(IBAtividade* novo)
{
    this->cntrIBAtividade = novo;
}

inline void MBDestino::setCntrIBHospedagem(IBHospedagem* novo)
{
    this->cntrIBHospedagem = novo;
}

#endif // MBDESTINO_HPP_INCLUDED
