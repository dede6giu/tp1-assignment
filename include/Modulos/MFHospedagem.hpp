#ifndef MFHOSPEDAGEM_HPP_INCLUDED
#define MFHOSPEDAGEM_HPP_INCLUDED

#include "../Interfaces/IFHospedagem.hpp"
#include <string>
#include <vector>

/*!
    232013031 - Implementação.
*/
class MFHospedagem : public IFHospedagem
{
    private:

        IBHospedagem* cntrIBHospedagem;

        std::vector<Hospedagem> hospedagemRegistradas;

    public:

        int lerInt(std::string);
        void esperarInput();
        void printHospedagem(Hospedagem);
        bool criarHospedagem(Codigo, Codigo);
        bool editarHospedagem(Hospedagem);
        bool processHospedagem();

        void run(Codigo, Codigo);
        void setCntrIBHospedagem(IBHospedagem*);
};

inline void MFHospedagem::setCntrIBHospedagem(IBHospedagem* novo)
{
    this->cntrIBHospedagem = novo;
}

#endif // MFHOSPEDAGEM_HPP_INCLUDED
