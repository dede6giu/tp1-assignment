#include "../../include/Modulos/MFDados.hpp"
#include "../../include/Modulos/MFConta.hpp"
#include "../../include/Modulos/MFViagem.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

MFDados::MFDados()
{
    cntrIFConta = new MFConta();
    cntrIFViagem = new MFViagem();
}

MFDados::~MFDados()
{
    delete cntrIFConta;
    delete cntrIFViagem;
}

void MFDados::run(Conta contaAutenticada)
{
    bool operando = 1;
    while(operando)
    {
        system("cls");
        cout << endl << "=========================================";
        cout << endl << "            BEM VINDO, "; cout << contaAutenticada.getValorCodigo();
        cout << endl << "Operacoes disponiveis: ";
        cout << endl << "    0. Sair da conta";
        cout << endl << "    1. Gerenciar conta";
        cout << endl << "    2. Gerenciar viagens";
        cout << endl << "=========================================";
        cout << endl << "Por favor, escolha uma operacao: ";

        // string para int
        string aux;
        getline(cin, aux);
        int entrada;
        try
        {
            entrada = stoi(aux);
        }
        catch (const exception &exp)
        {
            entrada = -1;
        }

        switch (entrada)
        {
            case 0:
                operando = 0;
                break;
            case 1:
                {
                    bool exclusao = cntrIFConta->run(contaAutenticada);
                    operando = !exclusao;
                    break;
                }
            case 2:
                cntrIFViagem->run(Codigo(contaAutenticada.getValorCodigo()));
                break;
            default:
                cout << endl << "Operacao invalida. Selecione uma opcao valida.";
                break;
        }
    }
}
