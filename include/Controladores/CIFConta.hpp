#ifndef CIFCONTA_HPP_INCLUDED
#define CIFCONTA_HPP_INCLUDED

#include "../Interfaces/IFConta.hpp"
#include "../Interfaces/IBConta.hpp"

class CIFConta : public IFConta
{
    private:

        IBConta* cntrIBConta;

    public:

        bool criar();
        void run(Codigo);
        void setCntrIBConta(IBConta*);
};

inline void CIFConta::setCntrIBConta(IBConta* novo)
{
    this->cntrIBConta = novo;
}

#endif // CIFCONTA_HPP_INCLUDED
