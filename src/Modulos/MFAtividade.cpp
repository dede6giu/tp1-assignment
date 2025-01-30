#include <curses.h>
#include "MFAtividade.hpp"
#include <iostream>

MFAtividade::run(Conta* conta)override{
    initscr();
    noecho();
    cbreak();
    int resposta = 0;
    while(true){
        clear();
        mvprintw(2, 2, "Qual operacao deseja realizar?");
        mvprintw(4, 2, "1 - Criar");
        mvprintw(5, 2, "2 - Excluir");
        mvprintw(6, 2, "3 - Ler");
        mvprintw(7, 2, "4 - Atualizar");
        mvprintw(8, 2, "0 - Sair");
        mvprintw(10, 2, "Escolha: ");
        refresh();

        scanw("%d", &resposta);
        switch (resposta) {
            case 1:
                // Chamar função de criar
                mvprintw(12, 2, "Executando criacao...");
                break;
            case 2:
                // Chamar função de excluir
                mvprintw(12, 2, "Executando exclusao...");
                break;
            case 3:
                // Chamar função de leitura
                mvprintw(12, 2, "Executando leitura...");
                break;
            case 4:
                // Chamar função de atualização
                mvprintw(12, 2, "Executando atualizacao...");
                break;
            case 0:
                endwin(); // Finaliza a interface PDCurses
                return;
            default:
                mvprintw(12, 2, "Por favor, indique um valor valido.");
        }
        refresh();
        getch(); // Aguarda entrada do usuário para continuar
    }
    }
    /*std:cout<<"Qual operacao deseja realizar ?"<<endl;
    std:cout<<"1-criar"<<endl;
    std:cout<<"2-excluir"<<endl;
    std:cout<<"3-ler"<<endl;
    std:cout<<"4-atualizar"<<endl;
    int resposta;break;
        default:
        std:cout<< "Por favor indicar um valor valido"<<endl;
        std:cin<< resposta<<endl;
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
    */
}

MFAtividade::setCntrIBAtividade(IBAtividade* ibAtividade) override{
    this->ibAtividade=ibAtividade;
}
Dados::~Dados() {
    ibAtividade = nullptr;
}
