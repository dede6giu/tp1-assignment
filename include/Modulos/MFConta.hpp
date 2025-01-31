#ifndef MFCONTA_HPP_INCLUDED
#define MFCONTA_HPP_INCLUDED

#include "../Interfaces/IFConta.hpp"
#include "../Interfaces/IBConta.hpp"

class MFConta : public IFConta
{
    private:

        IBConta* cntrIBConta;

    public:

        MFConta();
        ~MFConta();

        void esperarInput();

        bool criar();
        bool run(Conta);
        void setCntrIBConta(IBConta*);
};

inline void MFConta::setCntrIBConta(IBConta* novo)
{
    this->cntrIBConta = novo;
}

#endif // MFCONTA_HPP_INCLUDED
