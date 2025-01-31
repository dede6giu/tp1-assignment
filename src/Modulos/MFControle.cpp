#include "../../include/Modulos/MFControle.hpp"
#include "../../include/Modulos/MFAutenticacao.hpp"
#include "../../include/Modulos/MFConta.hpp"
#include "../../include/Modulos/MFDados.hpp"
#include <iostream>

using namespace std;

MFControle::MFControle()
{
    contaAutenticada = new Conta();
    cntrIFAutenticacao = new MFAutenticacao();
    cntrIFConta = new MFConta();
    cntrIFDados = new MFDados();
}

MFControle::~MFControle()
{
    delete contaAutenticada;
    delete cntrIFAutenticacao;
    delete cntrIFConta;
    delete cntrIFDados;
}

void MFControle::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

void MFControle::run()
{
    bool operando = true;
    while (operando)
    {
        system("cls");
        cout << endl << "=========================================";
        cout << endl << "               BEM VINDO!";
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Terminar o programa";
        cout << endl << "    1. Criar uma conta";
        cout << endl << "    2. Autenticar em uma conta";
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
            case 1:
                cntrIFConta->criar();
                break;

            case 2:
                if(cntrIFAutenticacao->run(contaAutenticada))
                {
                    cntrIFDados->run(*contaAutenticada);
                    delete contaAutenticada;
                    contaAutenticada = new Conta();
                }
                else
                {
                    delete contaAutenticada;
                    contaAutenticada = new Conta();
                }
                break;

            case 0:
                cout << endl << "Programa terminado.";
                esperarInput();
                operando = false;
                break;
            case -1:
            default:
                cout << endl << "Valor invalido.";
                esperarInput();
                break;
        }
    }
}
