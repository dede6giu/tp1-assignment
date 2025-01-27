#include "../../include/Controladores/CIFConta.hpp"
#include "../Entidades/Conta.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Codigo.hpp"
#include <string>
#include <iostream>

using namespace std;

bool CIFConta::criar()
{
    Codigo codigo;
    Senha senha;
    string aux;

    while (true)
    {
        cout << endl << "Criacao de conta" << endl << endl;
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

    bool resultado = cntrIBConta->criar(contaRecebida);

    if (resultado)
        return true;
    return false;
}

void CIFConta::run(Conta* contaAutenticada)
{

}
