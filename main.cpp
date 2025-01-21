#include <iostream>
#include <string>
#include <exception>
#include "include/Interfaces/IFAutenticacao.hpp"
#include "include/Interfaces/IBAutenticacao.hpp"
#include "include/Controladores/CIFAutenticacao.hpp"
#include "include/Stubs/SBAutenticacao.hpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    IFAutenticacao* cntrIFAutenticacao = new CIFAutenticacao();
    IBAutenticacao* stubBAutenticacao = new SBAutenticacao();

    cntrIFAutenticacao->setCntrIBAutenticacao(stubBAutenticacao);

    bool resultado = false;
    Conta contaAutenticada;

    while (true)
    {
        cout << endl << "Tela inicial do sistema." << endl;

        try
        {
            resultado = cntrIFAutenticacao->autenticar(&contaAutenticada);
        }
        catch (const runtime_error &exc)
        {
            cout << "Erro de sistema" << endl;
            break;
        }

        if (resultado)
        {
            cout << endl << "Sucesso." << endl;
            cout << "Codigo = " << contaAutenticada.getValorCodigo() << endl;
            break;
        }
        else
        {
            cout << "Falha de autenticacao" << endl;
            break;
        }
    }

    delete cntrIFAutenticacao;
    delete stubBAutenticacao;

    return 0;
}
