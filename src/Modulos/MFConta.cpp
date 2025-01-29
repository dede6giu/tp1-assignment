#include "../../include/Modulos/MFConta.hpp"
#include <iostream>

using namespace std;

MIFConta ::criar(){
    while (true){
        cout << "Iniciando o processo de criação de conta...\n";
        string nome, senha;
        cout << "Digite o nome da conta: ";
        cin >> nome;
        cout << "Digite a senha: ";
        cin >> senha;
        Conta conta(nome, senha);
        if (cntrIBConta->criar(conta)){
            cout<<"Sua conta foi criada com sucesso"<<endl;
            cout<<"Tente novamente"<<endl;
            break
        }
        else{
            cout<<"Houve um problema na criacao da conta"<<endl;
        }
}
    }
MIFConta::setCntrIBConta(IBConta* cntrIBConta){
    this->cntrIBConta = cntrIBConta;
}

MIFConta :: ~MIFConta() {
}

