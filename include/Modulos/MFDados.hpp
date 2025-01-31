#ifndef MFDADOS_HPP_INCLUDED
#define MFDADOS_HPP_INCLUDED

#include "../Interfaces/IFDados.hpp"

/*!
    232002771 - implementação. \n
*/
class MFDados : public IFDados
{
    private:

        IFConta* cntrIFConta;
        IFViagem* cntrIFViagem;

    public:

        MFDados();
        ~MFDados();

        void run(Conta);
        void setCntrIFConta(IFConta* cntrIFConta);
        void setCntrIFViagem(IFViagem* cntrIFViagem);

};

inline void MFDados::setCntrIFConta(IFConta* cntrIFConta) {
    this->cntrIFConta = cntrIFConta;
}

inline void MFDados::setCntrIFViagem(IFViagem* cntrIFViagem) {
    this->cntrIFViagem = cntrIFViagem;
}

#endif // MFDADOS_HPP_INCLUDED
