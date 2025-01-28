#include <iostream>
#include <string>
#include <exception>
#include "include/Controladores.hpp"
#include "include/Stubs.hpp"
#include "include/Interfaces.hpp"
#include "include/Modulos/MBConta.hpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    IFConta* cntrIFConta = new CIFConta();
    IBConta* mdlConta = new MBConta();

    cntrIFConta->setCntrIBConta(mdlConta);

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
    delete mdlConta;

    return 0;
}
