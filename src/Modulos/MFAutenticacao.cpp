#include "MFAutenticacao.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

// system"cls";

MFAutenticacao::run(Conta* contaAutenticar){
    system("cls");
    string codigo, senha;
    cout << "Digite seu código: ";
    cin >> codigo
    cout << endl << "Digite sua senha: "
    cin >> senha;
    Conta contaFornecida(codigo, senha);
    if (cntrIBConta->criar(contaFornecida)){
        contaAutenticar->setValor(Codigo(contaAutenticar.getValorCodigo()));
        contaAutenticar->setValor(Senha(contaAutenticar.getValorSenha()));
        return 1;
    }
    else
        return 0;

MFAutenticacao::setCntrIBAutenticacao(IBAutenticacao* ibAutenticacao) {
    this->cntrIBAutenticacao = cntrIBAutenticacao;
}
