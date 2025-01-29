#include <curses.h>
#include "MFAtividade.hpp"
#include <iostream>

MFAtividade::run(Conta* conta)override{
    std:cout<<"Qual operacao deseja realizar ?"<<endl;
    std:cout<<"1-criar"<<endl;
    std:cout<<"2-excluir"<<endl;
    std:cout<<"3-ler"<<endl;
    std:cout<<"4-atualizar"<<endl;
    int resposta;
    std:cin<< resposta<<endl;

    switch(resposta){
        case 1{
        //executar a funcao criar no back
        }
        case 2{
        //executar a funcao excluir no back
        }
        case 3{
        //executar a funcao ler no back
        }
        case 4{
        //executar a funcao atualizar no back
        }
        break;
        default:
        std:cout<< "Por favor indicar um valor valido"<<endl;
        std:cin<< resposta<<endl;
    }

}

MFAtividade::setCntrIBAtividade(IBAtividade* ibAtividade) override{
    this->ibAtividade=ibAtividade;
}
Dados::~Dados() {
    ibAtividade = nullptr;
}
