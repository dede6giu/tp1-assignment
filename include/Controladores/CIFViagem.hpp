#ifndef CIFVIAGEM_HPP_INCLUDED
#define CIFVIAGEM_HPP_INCLUDED

#include "../Interfaces/IFViagem.hpp"
#include "../Interfaces/IBViagem.hpp"

class CIFViagem : public IFViagem {
    private:

        IBViagem* cntrIBViagem;

    public:

        void run(Conta*);
        void setCntrIBViagem(IBViagem*);
};

inline void CIFViagem::setCntrIBViagem(IBViagem* novo) {
    this->cntrIBViagem = novo;
}

#endif // CIFVIAGEM_HPP_INCLUDED
