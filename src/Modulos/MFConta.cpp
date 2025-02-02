#include "../../include/Modulos/MFConta.hpp"
#include "../../include/Modulos/MBConta.hpp"
#include <iostream>

using namespace std;

MFConta::MFConta()
{
    cntrIBConta = new MBConta();
}

MFConta::~MFConta()
{
    delete cntrIBConta;
}

void MFConta::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

bool MFConta::criar()
{
    while (true)
    {
        system("cls");
        cout << endl << "=========================================";
        cout << endl << "               NOVA CONTA";
        cout << endl << "Uma Conta possui um codigo identificador";
        cout << endl << "e uma senha." << endl;
        cout << endl << "Codigos sao identificadores unicos de 6 caracteres.";
        cout << endl << "Podem ser letras min e maiusculas, ou numeros." << endl;
        cout << endl << "Senhas sao compostas de 5 numeros distintos";
        cout << endl << "que nao estao em ordem (de)crescente.";
        cout << endl << "=========================================";

        string codigo, senha;
        try
        {
            cout << endl <<  "Digite o codigo da conta: ";
            string resultado;
            getline(cin, resultado);
            Codigo aux1(resultado);
            codigo = resultado;
            cout << endl <<  "Digite a senha da conta: ";
            getline(cin, resultado);
            Senha aux2(resultado);
            senha = resultado;
        }
        catch (const invalid_argument &exp)
        {
            cout << endl << "Valor invalido.";
            esperarInput();
            continue;
        }
        catch (const length_error &exp)
        {
            cout << endl << "Valor invalido.";
            esperarInput();
            continue;
        }

        try
        {
            Conta aux(codigo, senha);
        }
        catch (const invalid_argument &exp)
        {
            cout << endl << "Valor invalido.";
            esperarInput();
            continue;
        }

        Conta conta(codigo, senha);
        if (cntrIBConta->criar(conta))
        {
            cout << endl << "Sua conta foi criada com sucesso.";
            esperarInput();
            return true;
        }
        else
        {
            cout << endl << "Houve um problema na criacao da conta.";
            esperarInput();
            return false;
        }
    }
}

bool MFConta::run(Conta contaAtual)
{
    while (true)
    {
        system("cls");
        cout << endl << "=========================================";
        cout << endl << "             PERFIL "; cout << contaAtual.getValorCodigo();
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Retornar";
        cout << endl << "    1. Alterar senha";
        cout << endl << "    2. Excluir conta";
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
                try
                {
                    cout << endl << "=========================================";
                    cout << endl << "Forneca a senha atual: ";
                    getline(cin, aux);
                    Senha senhaFornecida(aux);
                    cout << endl << "Forneca a nova senha: ";
                    getline(cin, aux);
                    Senha senhaNova(aux);
                    if (senhaFornecida.getValor() == contaAtual.getValorSenha())
                    {
                        if (cntrIBConta->atualizar(contaAtual, senhaNova))
                        {
                            cout << endl << "Sucesso na alteracao da senha.";
                            esperarInput();
                        }
                        else
                        {
                            cout << endl << "Erro na alteracao. Tente novamente.";
                            esperarInput();
                            continue;
                        }
                    }
                    else
                    {
                        cout << endl << "Senha atual incorreta.";
                        esperarInput();
                        continue;
                    }
                    return false;
                }
                catch (const invalid_argument &exp)
                {
                    cout << endl << "Valor invalido.";
                    esperarInput();
                    continue;
                }
                catch (const length_error &exp)
                {
                    cout << endl << "Valor invalido.";
                    esperarInput();
                    continue;
                }
            case 2:
                {
                    bool excluida = false;
                    cout << endl << "=========================================";
                    cout << endl << "Deseja excluir sua conta? Isso removera";
                    cout << endl << "todas as informacoes da sua conta, ";
                    cout << endl << "incluindo suas viagens, destinos, ";
                    cout << endl << "atividades e hospedagens.";
                    cout << endl << "Tem certeza disso? (S/n) ";
                    getline(cin, aux);
                    if (aux == "S" || aux == "s")
                    {
                        Codigo contaExc(contaAtual.getValorCodigo());
                        if (cntrIBConta->excluir(contaExc))
                        {
                            cout << endl << "Conta excluida com sucesso.";
                            excluida = true;
                        }
                        else
                        {
                            cout << endl << "Conta nao existe.";
                        }
                    }
                    else
                    {
                        cout << endl << "Operacao cancelada.";
                        esperarInput();
                        continue;
                    }
                    esperarInput();
                    return excluida;
                }
            case 0:
                cout << endl << "Operacao cancelada.";
                esperarInput();
                return false;
            case -1:
            default:
                cout << endl << "Valor invalido.";
                esperarInput();
                continue;
        }
    }
}
