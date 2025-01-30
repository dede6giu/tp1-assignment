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
        bool run(Conta* Conta) = 0;
        void setCntrIFConta(IFConta* cntrIFConta) = 0;
        void setCntrIFvIAGEM(IFViagem* cntrIFViagem) = 0;

};

#endif // MFDADOS_HPP_INCLUDED
