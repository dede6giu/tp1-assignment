#include "../../include/Modulos/MFViagem.hpp"
#include "../../include/Modulos/MBDestino.hpp"
#include "../../include/Modulos/MFAtividade.hpp"
#include "../../include/Modulos/MFHospedagem.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using namespace std;

int MFViagem::lerInt(std::string entrada)
{
    try
    {
        int resultado = stoi(entrada);
        return resultado;
    }
    catch (...)
    {
        return -1;
    }
}

void MFViagem::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

void MFViagem::printViagem(Viagem viagemImprimir)
{
    cout << endl << "=========================================";
    cout << endl << "                  VIAGEM";
    cout << endl << "      Tag: " << viagemImprimir.getTag().getValor();
    cout << endl << "     Nome: " << viagemImprimir.getValorNome();
    cout << endl << "Avaliacao: ";
    for (int i = 0; i < viagemImprimir.getValorAvaliacao(); i++)     cout << "*";
    for (int i = 0; i < 5 - viagemImprimir.getValorAvaliacao(); i++) cout << "-";
    cout << endl << "=========================================";
}

bool MFViagem::editarViagem(Viagem viagemAtual)
{
    cout << endl << "=========================================";
    cout << endl << "                  EDITAR";
    cout << endl << "Operacoes disponiveis:";
    cout << endl << "    0. Retornar";
    cout << endl << "    1. Editar Nome";
    cout << endl << "    2. Editar Avaliacao";
    cout << endl << "=========================================";
    cout << endl << "Por favor, escolha uma operacao: ";
    string comando;
    getline(cin, comando);
    int resultado = lerInt(comando);
    switch (resultado)
    {
        case 1:
            cout << endl << "Qual o novo nome?";
            cout << endl << "Nomes sao compostos de, no maximo, 30 caracteres";
            cout << endl << "                           30v" << endl;
            getline(cin, comando);
            try
            {
                Nome nomeNovo(comando);
                if (cntrIBViagem->atualizar(viagemAtual, nomeNovo))
                {
                    return true;
                }
                else
                {
                    throw runtime_error("Falha na operacao");
                }
            }
            catch (const length_error &exp)
            {
                cout << endl << "Valor invalido.";
            }
            break;
        case 2:
            cout << endl << "Qual a nova avaliacao?";
            cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Avaliacao nomeAvaliacao(resultado);
                if (cntrIBViagem->atualizar(viagemAtual, nomeAvaliacao))
                {
                    return true;
                }
                else
                {
                    throw runtime_error("Falha na operacao");
                }
            }
            catch (const length_error &exp)
            {
                cout << endl << "Valor invalido.";
            }
            break;
        case 0:
            cout << endl << "Operacao cancelada.";
            esperarInput();
            return false;
        case -1:
        default:
            cout << endl << "Valor invalido.";
            esperarInput();
            return false;
    }
    return false;
}

bool MFViagem::processViagem()
{
    bool atualizarViagem = false;
    int posicaoAtual = 0;
    while (true)
    {
        int posicaoMaxima = viagemRegistradas.size();
        posicaoAtual %= posicaoMaxima; // failsafe
        if (posicaoMaxima == 0)
        {
            // nenhuma viagem disponivel
            atualizarViagem = true;
            return atualizarViagem;
        }

        system("cls");

        printViagem(viagemRegistradas[posicaoAtual]);
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Navegacao: Retornar";
        cout << endl << "    1. Navegacao: Anterior";
        cout << endl << "    2. Navegacao: Proxima";
        cout << endl << "    3. Navegacao: Pesquisar Tag";
        cout << endl << "    4. Atual: Editar";
        cout << endl << "    5. Atual: Excluir";
        cout << endl << "    6. Atual: Destinos Associados";
        cout << endl << "=========================================";
        cout << endl << "Por favor, escolha uma operacao: ";
        string comando;
        getline(cin, comando);
        int resultado = lerInt(comando);
        switch (resultado)
        {
            case 0:
                return atualizarViagem;
            case 1:
                posicaoAtual += posicaoMaxima-1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 2:
                posicaoAtual += posicaoMaxima+1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 3:
                cout << endl << "Informe a tag da Viagem desejada: ";
                getline(cin, comando);
                try
                {
                    Codigo tagFornecida(comando);
                    int posicaoInicial = posicaoAtual;
                    for (int i = 0; i < posicaoMaxima; i++)
                    {
                        if (viagemRegistradas[i].getTag().getValor() == tagFornecida.getValor())
                        {
                            posicaoAtual = i;
                            break;
                        }
                    }
                    if (posicaoAtual == posicaoInicial)
                    {
                        cout << endl << "Tag nao foi encontrada.";
                        esperarInput();
                    }
                }
                catch (invalid_argument &exc)
                {
                    cout << endl << "Tag invalida.";
                    esperarInput();
                }
                catch (length_error &exc)
                {
                    cout << endl << "Tag invalida.";
                    esperarInput();
                }
                break;
            case 4:
                atualizarViagem = true;
                try
                {
                    bool sucesso = editarViagem(viagemRegistradas[posicaoAtual]);
                    if (sucesso)
                    {
                        cout << endl << "Alteracao realizada com sucesso.";
                    }
                    else
                    {
                        cout << endl << "Alteracao nao foi realizada. Tente novamente.";
                        esperarInput();
                        break;
                    }
                }
                catch (const runtime_error &exp)
                {
                    cout << endl << "Falha desconhecida durante a operacao. Tente novamente.";
                }
                esperarInput();
                return atualizarViagem;
            case 5:
                cout << endl << "Deseja excluir essa Viagem?";
                cout << endl << "Isso excluira todos os Destinos, as Atividades e as Hospedagens";
                cout << endl << "associados a essa Viagem. Tem certeza disso? (S/n) ";
                getline(cin, comando);
                if (comando == "S" || comando == "s")
                {
                    atualizarViagem = true;
                    try
                    {
                        if (cntrIBViagem->excluir(viagemRegistradas[posicaoAtual]))
                        {
                            cout << endl << "Sucesso na operacao.";
                            viagemRegistradas.erase(viagemRegistradas.begin() + posicaoAtual);
                            posicaoMaxima--;
                            posicaoAtual %= posicaoMaxima;
                        }
                        else
                        {
                            cout << endl << "Falha na operacao.";
                            esperarInput();
                            return atualizarViagem;
                        }
                    }
                    catch (const exception &exp)
                    {
                        cout << endl << "Erro no sistema." << endl;
                        esperarInput();
                        return atualizarViagem;
                    }
                }
                else
                {
                    cout << endl << "Operacao cancelada.";
                }
                esperarInput();
                break;
            case 6:
                cntrIFDestino->run(Codigo(viagemRegistradas[posicaoAtual].getValorCodigo()),
                                   viagemRegistradas[posicaoAtual].getTag());
                break;
            case -1:
            default:
                cout << endl << "Operacao Invalida.";
                break;
        }
    }
}

bool MFViagem::criarViagem(Codigo contaAutenticada)
{
    system("cls");
    cout << endl << "=========================================";
    cout << endl << "               NOVA VIAGEM";
    cout << endl << "Uma Viagem possui um tag, um nome e uma avaliacao" << endl;
    cout << endl << "Tag sao identificadores unicos de 6 caracteres.";
    cout << endl << "Podem ser letras min e maiusculas, ou numeros." << endl;
    cout << endl << "Nomes sao compostos de, no maximo, 30 caracteres" << endl;
    cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
    cout << endl << "=========================================";
    cout << endl << "Forneca um tag para a Viagem:";
    cout << endl << "    6v" << endl;
    string tag;
    getline(cin, tag);
    try
    {
        Codigo aux(tag);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }
    cout << endl << "Forneca um nome para a Viagem:";
    cout << endl << "                           30v" << endl;
    string nome;
    getline(cin, nome);
    try
    {
        Nome aux(nome);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }
    cout << endl << "Forneca uma avaliacao para a Viagem: ";
    string avaliacaoStr;
    getline(cin, avaliacaoStr);
    try
    {
        int avaliacao = stoi(avaliacaoStr);
        Avaliacao aux(avaliacao);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }

    Viagem novaViagem(Avaliacao(stoi(avaliacaoStr)),
                      contaAutenticada,
                      Nome(nome),
                      Codigo(tag));
    if (cntrIBViagem->criar(novaViagem))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MFViagem::run(Codigo contaAutenticada)
{
    IBDestino* dep1 = new MBDestino();
    IFAtividade* dep2 = new MFAtividade();
    IFHospedagem* dep3 = new MFHospedagem();

    cntrIFDestino->setCntrIBDestino(dep1);
    cntrIFDestino->setCntrIFAtividade(dep2);
    cntrIFDestino->setCntrIFHospedagem(dep3);
    cntrIBViagem->setCntrIBDestino(dep1);

    bool atualizarViagem = true;
    bool operando = true;
    while (operando)
    {
        system("cls");
        if (atualizarViagem)
        {
            viagemRegistradas = cntrIBViagem->ler(contaAutenticada);
            atualizarViagem = false;
        }
        cout << endl << "=========================================";
        cout << endl << "                 VIAGENS";
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Retornar";
        cout << endl << "    1. Criar nova Viagem";
        cout << endl << "    2. Manejar Viagens registradas";
        cout << endl << "=========================================";
        cout << endl << "Por favor, escolha uma operacao: ";
        string comando;
        getline(cin, comando);
        int resultado = lerInt(comando);
        switch (resultado)
        {
            case 1:
                try
                {
                    bool sucesso = criarViagem(contaAutenticada);
                    if (sucesso)
                    {
                        cout << endl << "Viagem criada com sucesso.";
                    }
                    else
                    {
                        cout << endl << "Viagem nao foi criada. Tente novamente.";
                    }
                }
                catch (const runtime_error &exp)
                {
                    cout << endl << "Algum erro aconteceu.";
                }
                esperarInput();
                break;
            case 2:
                if ((int)viagemRegistradas.size() == 0)
                {
                    cout << endl << "Nao ha viagens registradas";
                    esperarInput();
                    break;
                }
                atualizarViagem = processViagem();
                break;

            case 0:
                operando = false;
                break;
            case -1:
            default:
                cout << endl << "Operacao Invalida.";
                esperarInput();
                break;
        }
    }

    delete dep1;
    delete dep2;
    delete dep3;
    return;
}
