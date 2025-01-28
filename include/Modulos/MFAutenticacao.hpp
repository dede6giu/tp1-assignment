#ifndef AUTENTICACAO_HPP_INCLUDED
#define AUTENTICACAO_HPP_INCLUDED

#include <string>
#include <iostream>
#include "../Entidades/Conta.hpp"
#include "IAutenticacao.hpp"

// Classe responsável pela autenticação do usuário
class Autenticacao : public IAutenticacao {
private:
    IAutenticacao* referenciaIAutenticacao;

public:
    bool autenticar(Conta* conta) override;

    void setCntrIAutenticacao(IAutenticacao* referencia) override;

    ~Autenticacao() override;
};

#endif

