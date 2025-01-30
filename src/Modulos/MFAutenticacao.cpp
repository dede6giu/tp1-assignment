#include "MFAutenticacao.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool MFAutenticacao::run(Conta* contaAutenticar){
    while(true){
        system("cls");
        string codigo, senha;
        cout << "Forneca seu codigo e senha, se deseja retornar digite \"cancelar\"";
        cout << "Digite seu codigo: ";
        getline(cin, codigo);
        cout << endl << "Digite sua senha: ";
        getline(cin, senha)
        if(codigo == "cancelar" || senha == "cancelar"){
            return;
        }
        Conta contaFornecida(codigo, senha);
        if (cntrIBConta->criar(contaFornecida)){
            contaAutenticar->setValor(Codigo(contaAutenticar.getValorCodigo()));
            contaAutenticar->setValor(Senha(contaAutenticar.getValorSenha()));
            return 1;
        }
        else{
            return 0;
        }
    }
}

void MFAutenticacao::setCntrIBAutenticacao(IBAutenticacao* cntrIBAutenticacao) {
    this->cntrIBAutenticacao = cntrIBAutenticacao;
}
