#ifndef SBCONTA_HPP_INCLUDED
#define SBCONTA_HPP_INCLUDED

#include "../Interfaces/IBConta.hpp"
#include <string>

class SBConta : public IBConta
{
    private:

        const static std::string TRIGGER_FALHA_CODIGO;
        const static std::string TRIGGER_FALHA_SENHA;

    public:

        bool criar(Conta);
        bool excluir(Conta);
        bool ler(Codigo);
        bool atualizar(Conta, Senha);
};

#endif // SBCONTA_HPP_INCLUDED
