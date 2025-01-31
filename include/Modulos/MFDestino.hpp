#ifndef MFDESTINO_HPP_INCLUDED
#define MFDESTINO_HPP_INCLUDED

#include "../Interfaces/IFDestino.hpp"
#include <string>
#include <vector>

/*!
    232013031 - Implementação.
*/
class MFDestino : public IFDestino
{
    private:

        IFHospedagem* cntrIFHospedagem;
        IFAtividade* cntrIFAtividade;
        IBDestino* cntrIBDestino;

        std::vector<Destino> destinoRegistrados;

    public:

        int lerInt(std::string);
        void esperarInput();
        void printDestino(Destino);
        bool criarDestino(Codigo, Codigo);
        bool editarDestino(Destino);
        bool processDestino();

        void run(Codigo, Codigo);

        void setCntrIBDestino(IBDestino*);
        void setCntrIFHospedagem(IFHospedagem*);
        void setCntrIFAtividade(IFAtividade*);
};

inline void MFDestino::setCntrIBDestino(IBDestino* novo)
{
    this->cntrIBDestino = novo;
}

inline void MFDestino::setCntrIFHospedagem(IFHospedagem* novo)
{
    this->cntrIFHospedagem = novo;
}

inline void MFDestino::setCntrIFAtividade(IFAtividade* novo)
{
    this->cntrIFAtividade = novo;
}

#endif // MFDESTINO_HPP_INCLUDED
