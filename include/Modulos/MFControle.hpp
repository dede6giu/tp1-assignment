#ifndef MFCONTROLE_HPP_INCLUDED
#define MFCONTROLE_HPP_INCLUDED

#include "../Interfaces/IFControle.hpp"


class MFControle : public IFControle
{
    private:

        Conta* contaAutenticada;

        IFAutenticacao* cntrIFAutenticacao;
        IFConta* cntrIFConta;
        IFDados* cntrIFDados;

    public:

        MFControle();
        ~MFControle();
        void esperarInput();

        void run();

        void setCntrIFAutenticacao(IFAutenticacao*);
        void setCntrIFConta(IFConta*);
        void setCntrIFDados(IFDados*);
};

inline void MFControle::setCntrIFAutenticacao(IFAutenticacao* novo)
{
    this->cntrIFAutenticacao = novo;
}

inline void MFControle::setCntrIFConta(IFConta* novo)
{
    this->cntrIFConta = novo;
}

inline void MFControle::setCntrIFDados(IFDados* novo)
{
    this->cntrIFDados = novo;
}

#endif // MFCONTROLE_HPP_INCLUDED
