#ifndef MFVIAGEM_HPP_INCLUDED
#define MFVIAGEM_HPP_INCLUDED

#include "../Interfaces/IFViagem.hpp"
#include <string>
#include <vector>

/*!
    232013031 - Implementação.
*/
class MFViagem : public IFViagem
{
    private:

        IBViagem* cntrIBViagem;
        IFDestino* cntrIFDestino;

        std::vector<Viagem> viagemRegistradas;

    public:

        void esperarInput();

        int lerInt(std::string);
        bool processViagem();
        bool editarViagem(Viagem);
        void printViagem(Viagem);
        bool criarViagem(Codigo);

        void run(Codigo);
        void setCntrIBViagem(IBViagem*);
        void setCntrIFDestino(IFDestino*);
};

inline void MFViagem::setCntrIBViagem(IBViagem* novo)
{
    this->cntrIBViagem = novo;
}

inline void MFViagem::setCntrIFDestino(IFDestino* novo)
{
    this->cntrIFDestino = novo;
}

#endif // MFVIAGEM_HPP_INCLUDED
