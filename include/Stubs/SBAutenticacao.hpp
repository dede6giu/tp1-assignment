#ifndef SBAUTENTICACAO_HPP_INCLUDED
#define SBAUTENTICACAO_HPP_INCLUDED

#include "../Interfaces/IBAutenticacao.hpp"
#include "../Entidades/Conta.hpp"
#include <string>

class SBAutenticacao : public IBAutenticacao
{
    private:

        const static std::string TRIGGER_FALHA;

    public:

        bool autenticar(Conta);
};

#endif // SBAUTENTICACAO_HPP_INCLUDED
