#include "../../include/Modulos/MFAutenticacao.hpp"
#include "../../include/Modulos/MBConta.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void MFAutenticacao::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

bool MFAutenticacao::run(Conta* contaAutenticar)
{
    IBConta* dep1 = new MBConta();

    cntrIBAutenticacao->setCntrIBConta(dep1);

    bool retorno = false;
    while(true)
    {
        system("cls");

        cout << endl << "=========================================";
        cout << endl << "              AUTENTICACAO";
        cout << endl << "Forneca um codigo e uma senha.";
        cout << endl << "Se deseja retornar, digite 'cancelar'.";
        cout << endl << "=========================================";

        string codigoStr, senhaStr;
        try
        {
            cout << endl <<  "Digite o codigo da conta: ";
            string resultado;
            getline(cin, resultado);
            if (resultado == "cancelar")
            {
                cout << endl << "Operacao cancelada.";
                esperarInput();
                break;
            }
            Codigo aux1(resultado);
            codigoStr = resultado;
            cout << endl <<  "Digite a senha da conta: ";
            getline(cin, resultado);
            if (resultado == "cancelar")
            {
                cout << endl << "Operacao cancelada.";
                esperarInput();
                break;
            }
            Senha aux2(resultado);
            senhaStr = resultado;
        }
        catch (const invalid_argument &exp)
        {
            cout << endl << "Valor invalido.";
            continue;
        }
        catch (const length_error &exp)
        {
            cout << endl << "Valor invalido.";
            continue;
        }

        Codigo codigo(codigoStr);
        Senha senha(senhaStr);
        try
        {
            Conta aux(codigo, senha);
        }
        catch (const invalid_argument &exp)
        {
            cout << endl << "Valor invalido.";
            continue;
        }

        Conta contaFornecida(codigo, senha);
        if (cntrIBAutenticacao->autenticar(contaFornecida))
        {
            contaAutenticar->setValor(Codigo(contaFornecida.getValorCodigo()));
            contaAutenticar->setValor(Senha(contaFornecida.getValorSenha()));
            retorno = true;
            break;
        }
        else
        {
            cout << endl << "Credenciais invalidas.";
            esperarInput();
            continue;
        }
    }

    delete dep1;
    return retorno;
}
