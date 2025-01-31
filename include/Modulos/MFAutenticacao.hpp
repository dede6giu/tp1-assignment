#ifndef MFAUTENTICACAO_HPP_INCLUDEDE
#define MFAUTENTICACAO_HPP_INCLUDEDE

#include "../Interfaces/IFAutenticacao.hpp"

/*!
    232002771 - implementação. \n
*/
class MFAutenticacao : public IFAutenticacao
{
    private:
        IBAutenticacao* cntrIBAutenticacao;

    public:
        bool run(Conta* Conta) = 0;
        void setCntrIBAutenticacao(IBAutenticacao* cntrIBAutenticacao) = 0;


};

inline void MFAutenticacao::setCntrIBAutenticacao(IBAutenticacao* cntrIBAutenticacao) {
    this->cntrIBAutenticacao = cntrIBAutenticacao;
}

#endif // MFAUTENTICACAO_HPP_INCLUDEDE
