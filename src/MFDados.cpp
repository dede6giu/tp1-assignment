#include "MFDados.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool MFDados::run(Conta* contaAutenticar){
    while(true){
        system("cls");
        string aux;
        cout << "Selecione uma das opcoes a seguir: " << endl;
        cout << "0 - Gerenciar conta" << endl;
        cout << "1 - Gerenciar viagens" << endl;
        getline(cin, aux);

        if(aux == "cancelar"){
            return;
        }else{
            int entrada = int(aux);
            switch(entrada){
                case 0:
                    cntrIFConta->run(Conta contaAutenticada);
                    break;
                case 1:
                    cntrIFViagem->run(Conta contaAutenticada);
                    break;
            }
        }
    }

MFDados::setCntrIFConta(IFConta* cntrIFConta) {
    this->cntrIFConta = cntrIFConta;
}

MFDados::setCntrIFViagem(IFViagem* cntrIFViagem) {
    this->cntrIFViagem = cntrIFViagem;
}
