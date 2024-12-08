#include <iostream>
#include <string>
#include "TU.hpp"

using namespace std;

int main()
{
    cout << "Iniciando Testes de Unidade..." << endl;

    string suc = "SUCESSO";
    string fal = "FALHA";


    cout << "\n" << "===== Dominios =====" << endl;
    {
        TUAvaliacao* holder = new TUAvaliacao();
        cout << "Avaliacao : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUCodigo* holder = new TUCodigo();
        cout << "Codigo    : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUData* holder = new TUData();
        cout << "Data      : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUDinheiro* holder = new TUDinheiro();
        cout << "Dinheiro  : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUDuracao* holder = new TUDuracao();
        cout << "Duracao   : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUHorario* holder = new TUHorario();
        cout << "Horario   : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUNome* holder = new TUNome();
        cout << "Nome      : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUSenha* holder = new TUSenha();
        cout << "Senha     : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    cout << "\n" << "===== Entidades =====" << endl;

    {
        TUConta* holder = new TUConta();
        cout << "Conta     : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUDestino* holder = new TUDestino();
        cout << "Destino   : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUHospedagem* holder = new TUHospedagem();
        cout << "Hospedagem: ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    {
        TUViagem* holder = new TUViagem();
        cout << "Viagem    : ";
        switch (holder->run())
        {
            case holder->SUCESSO:
                cout << suc << endl;
                break;
            case holder->FALHA:
                cout << fal << endl;
                break;
        }
        delete holder;
    }

    return 0;
}
