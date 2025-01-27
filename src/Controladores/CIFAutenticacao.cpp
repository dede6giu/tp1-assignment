#include "../../include/Controladores/CIFAutenticacao.hpp"
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Senha.hpp"
#include <string>
#include <exception>
#include <iostream>

using namespace std;

bool CIFAutenticacao::run(Conta* contaAutenticada)
{
    Codigo codigo;
    Senha senha;
    string aux;

    while (true)
    {
        cout << endl << "Autenticacao do usuario" << endl << endl;
        try
        {
            cout << "Forneca o codigo: ";
            cin >> aux;
            codigo.setValor(aux);
            cout << "Forneca a senha: ";
            cin >> aux;
            senha.setValor(aux);
            break;
        }
        catch (const invalid_argument &exp)
        {
            cout << "Formatacao incorreta" << endl;
        }
        catch (const length_error &exp)
        {
            cout << "Formatacao incorreta" << endl;
        }
    }

    Conta contaRecebida;
    contaRecebida.setValor(codigo);
    contaRecebida.setValor(senha);

    bool resultado = cntrIBAutenticacao->autenticar(contaRecebida);

    if (resultado)
    {
        contaAutenticada->setValor(codigo);
        contaAutenticada->setValor(senha);
        return true;
    }
    else
    {
        return false;
    }
}
