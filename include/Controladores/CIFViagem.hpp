#ifndef CIFVIAGEM_HPP_INCLUDED
#define CIFVIAGEM_HPP_INCLUDED

#include "../Interfaces/IFViagem.hpp"
#include "../Interfaces/IBViagem.hpp"

class CIFViagem : public IFViagem {
    private:

        IBViagem* cntrIBViagem;

    public:

        bool criar();
        inline void setCntrIBConta(IBConta* novo) {
            this->cntrIBConta = novo;
        }
};

#endif // CIFVIAGEM_HPP_INCLUDED
