#ifndef MBVIAGEM_HPP_INCLUDED
#define MBVIAGEM_HPP_INCLUDED

#include "../Interfaces/IBViagem.hpp"
#include <sqlite3.h>

/*!
    232013031 - Implementação.
*/
class MBViagem : public IBViagem
{
    private:

        sqlite3* banco;

        IBDestino* cntrIBDestino;

    public:
        MBViagem();
        ~MBViagem();

        bool criar(Viagem);
        void criar(Codigo);
        bool excluir(Viagem);
        void excluir(Codigo);
        bool ler(Viagem);
        std::vector<Viagem> ler(Codigo);
        bool atualizar(Viagem, Avaliacao);
        bool atualizar(Viagem, Nome);

        void setCntrIBDestino(IBDestino*);
};

inline void MBViagem::setCntrIBDestino(IBDestino* novo)
{
    this->cntrIBDestino = novo;
}

#endif // MBVIAGEM_HPP_INCLUDED
