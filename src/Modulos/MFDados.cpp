#include "../../include/Modulos/MFDados.hpp"
#include "../../include/Modulos/MFDestino.hpp"
#include "../../include/Modulos/MBConta.hpp"
#include "../../include/Modulos/MBViagem.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

void MFDados::run(Conta contaAutenticada)
{
    IFDestino* dep1 = new MFDestino();
    IBConta* dep2 = new MBConta();
    IBViagem* dep3 = new MBViagem();

    cntrIFConta->setCntrIBConta(dep2);
    cntrIFViagem->setCntrIBViagem(dep3);
    cntrIFViagem->setCntrIFDestino(dep1);

    bool operando = 1;
    while(operando)
    {
        system("cls");
        string aux;
        cout << endl << "Selecione uma das opcoes a seguir: ";
        cout << endl << "0 - Sair da conta";
        cout << endl << "1 - Gerenciar conta";
        cout << endl << "2 - Gerenciar viagens";

        // string para int
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
    delete dep1;
    delete dep2;
    delete dep3;
}
