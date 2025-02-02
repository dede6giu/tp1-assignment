#ifndef MFATIVIDADE_HPP_INCLUDED
#define MFATIVIDADE_HPP_INCLUDED

#include "../Interfaces/IFAtividade.hpp"
#include <string>
#include <vector>

/*!
    232013031 - Implementação.
*/
class MFAtividade : public IFAtividade
{
    private:

        IBAtividade* cntrIBAtividade;

        std::vector<Atividade> atividadeRegistradas;

    public:

        MFAtividade();
        ~MFAtividade();

        int lerInt(std::string);
        void esperarInput();
        void printAtividade(Atividade);
        bool criarAtividade(Codigo, Destino);
        bool editarAtividade(Atividade, Destino);
        bool processAtividade(Destino);

        void run(Codigo, Destino);
        void setCntrIBAtividade(IBAtividade*);
};

inline void MFAtividade::setCntrIBAtividade(IBAtividade* novo)
{
    this->cntrIBAtividade = novo;
}

#endif // MFATIVIDADE_HPP_INCLUDED
