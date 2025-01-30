#ifndef MFAUTENTICACAO_HPP_INCLUDEDE
#define MFAUTENTICACAO_HPP_INCLUDEDE

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

#endif // MFAUTENTICACAO_HPP_INCLUDEDE
