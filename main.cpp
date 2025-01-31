#include <iostream>
#include <string>
#include <exception>
#include "include/Controladores.hpp"
#include "include/Stubs.hpp"
#include "include/Interfaces.hpp"
#include "include/Modulos.hpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    IFConta* cntrIFConta = new MFConta();
    IBConta* cntrIBConta = new MBConta();

    cntrIFConta->setCntrIBConta(cntrIBConta);

    bool resultado = false;

    while (true)
    {
        cout << endl << "Tela inicial do sistema." << endl;

        try
        {
            resultado = cntrIFConta->criar();
        }
        catch (const runtime_error &exc)
        {
            cout << &exc << endl;
            break;
        }

        if (resultado)
        {
            cout << endl << "Sucesso." << endl;
            break;
        }
        else
        {
            cout << "Falha na criacao." << endl;
            break;
        }
    }

    delete cntrIFConta;
    delete cntrIBConta;

    return 0;
}
