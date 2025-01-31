#include "MFAutenticacao.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

bool MFAutenticacao::run(Conta* contaAutenticar){
    IBConta* dep1 = new MBConta();

    cntrIBAutenticacao->setCntrIBConta(dep1);

    bool retorno = 0;
    while(true){
        system("cls");

        string codigo, senha;
        cout << "Forneca seu codigo e senha, se deseja retornar digite \"cancelar\"";
        cout << "Digite seu codigo: ";
        getline(cin, codigo);
        cout << endl << "Digite sua senha: ";
        getline(cin, senha)
        if(codigo == "cancelar" || senha == "cancelar"){
            break;
        }
        Conta contaFornecida(codigo, senha);
        if (cntrIBConta->criar(contaFornecida)){
            contaAutenticar->setValor(Codigo(contaAutenticar.getValorCodigo()));
            contaAutenticar->setValor(Senha(contaAutenticar.getValorSenha()));
            retorno = 1;
            break;
        }
        else{
            break;
        }
    }

    delete dep1;
    return retorno;
}
