#include "../../include/Modulos/MFHospedagem.hpp"
#include "../../include/Modulos/MBHospedagem.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

MFHospedagem::MFHospedagem()
{
    cntrIBHospedagem = new MBHospedagem();
}

MFHospedagem::~MFHospedagem()
{
    delete cntrIBHospedagem;
}

int MFHospedagem::lerInt(std::string entrada)
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

void MFHospedagem::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

void MFHospedagem::printHospedagem(Hospedagem hospedagemImprimir)
{
    cout << endl << "=========================================";
    cout << endl << "               HOSPEDAGEM";
    cout << endl << "       Tag: " << hospedagemImprimir.getTag().getValor();
    cout << endl << "TagDestino: " << hospedagemImprimir.getTagDestino().getValor();
    cout << endl << "      Nome: " << hospedagemImprimir.getValorNome();
    cout << endl << "     Preco: R$" << hospedagemImprimir.getValorDiariaFormatado();
    cout << endl << " Avaliacao: ";
    for (int i = 0; i < hospedagemImprimir.getValorAvaliacao(); i++)     cout << "*";
    for (int i = 0; i < 5 - hospedagemImprimir.getValorAvaliacao(); i++) cout << "-";
    cout << endl << "=========================================";
}

bool MFHospedagem::editarHospedagem(Hospedagem hospedagemAtual)
{
    cout << endl << "=========================================";
    cout << endl << "                  EDITAR";
    cout << endl << "Operacoes disponiveis:";
    cout << endl << "    0. Retornar";
    cout << endl << "    1. Editar Nome";
    cout << endl << "    2. Editar Preco da diaria";
    cout << endl << "    3. Editar Avaliacao";
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
                if (cntrIBHospedagem->atualizar(hospedagemAtual, nomeNovo))
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
            catch (const invalid_argument &exp)
            {
                cout << endl << "Valor invalido.";
            }
            break;
        case 2:
            cout << endl << "Qual o novo preco em centavos?";
            cout << endl << "De 0 a 20000000." << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Dinheiro precoNovo(resultado);
                if (cntrIBHospedagem->atualizar(hospedagemAtual, precoNovo))
                {
                    return true;
                }
                else
                {
                    throw runtime_error("Falha na operacao");
                }
            }
            catch (const invalid_argument &exp)
            {
                cout << endl << "Valor invalido.";
            }
            catch (const length_error &exp)
            {
                cout << endl << "Valor invalido.";
            }
            break;
        case 3:
            cout << endl << "Qual a nova avaliacao?";
            cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Avaliacao nomeAvaliacao(resultado);
                if (cntrIBHospedagem->atualizar(hospedagemAtual, nomeAvaliacao))
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
            catch (const invalid_argument &exp)
            {
                cout << endl << "Valor invalido.";
            }
            break;

        case 0:
            cout << endl << "Operacao cancelada.";
            return false;
        case -1:
        default:
            cout << endl << "Valor invalido.";
            return false;
    }
    return false;
}

bool MFHospedagem::processHospedagem()
{
    bool atualizarHospedagem = false;
    int posicaoAtual = 0;
    while (true)
    {
        int posicaoMaxima = hospedagemRegistradas.size();
        posicaoAtual %= posicaoMaxima; // failsafe
        if (posicaoMaxima == 0)
        {
            // nenhuma viagem disponivel
            atualizarHospedagem = true;
            return atualizarHospedagem;
        }

        system("cls");

        printHospedagem(hospedagemRegistradas[posicaoAtual]);
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Navegacao: Retornar";
        cout << endl << "    1. Navegacao: Anterior";
        cout << endl << "    2. Navegacao: Proxima";
        cout << endl << "    3. Navegacao: Pesquisar Tag";
        cout << endl << "    4. Atual: Editar";
        cout << endl << "    5. Atual: Excluir";
        cout << endl << "=========================================";
        cout << endl << "Por favor, escolha uma operacao: ";
        string comando;
        getline(cin, comando);
        int resultado = lerInt(comando);
        switch (resultado)
        {
            case 0:
                return atualizarHospedagem;
            case 1:
                posicaoAtual += posicaoMaxima-1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 2:
                posicaoAtual += posicaoMaxima+1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 3:
                cout << endl << "Informe a tag da Hospedagem desejada: ";
                getline(cin, comando);
                try
                {
                    Codigo tagFornecida(comando);
                    int posicaoInicial = posicaoAtual;
                    for (int i = 0; i < posicaoMaxima; i++)
                    {
                        if (hospedagemRegistradas[i].getTag().getValor() == tagFornecida.getValor())
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
                atualizarHospedagem = true;
                try
                {
                    bool sucesso = editarHospedagem(hospedagemRegistradas[posicaoAtual]);
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
                return atualizarHospedagem;
            case 5:
                cout << endl << "Deseja excluir essa Hospedagem?";
                cout << endl << "Tem certeza disso? (S/n) ";
                getline(cin, comando);
                if (comando == "S" || comando == "s")
                {
                    atualizarHospedagem = true;
                    try
                    {
                        if (cntrIBHospedagem->excluir(hospedagemRegistradas[posicaoAtual]))
                        {
                            cout << endl << "Sucesso na operacao.";
                        }
                        else
                        {
                            cout << endl << "Falha na operacao.";
                        }
                    }
                    catch (const exception &exp)
                    {
                        cout << endl << "Erro no sistema." << endl;
                    }
                    esperarInput();
                    return atualizarHospedagem;
                }
                else
                {
                    cout << endl << "Operacao cancelada.";
                }
                esperarInput();
                break;
            case -1:
            default:
                cout << endl << "Operacao Invalida.";
                break;
        }
    }
}

bool MFHospedagem::criarHospedagem(Codigo contaAutenticada, Codigo destinoAssociado)
{
    system("cls");
    cout << endl << "=========================================";
    cout << endl << "             NOVA HOSPEDAGEM";
    cout << endl << "Uma Hospedagem possui um tag, um nome, um";
    cout << endl << "preco da diaria e uma avaliacao" << endl;
    cout << endl << "Tag sao identificadores unicos de 6 caracteres.";
    cout << endl << "Podem ser letras min e maiusculas, ou numeros." << endl;
    cout << endl << "Nomes sao compostos de, no maximo, 30 caracteres" << endl;
    cout << endl << "Preco sao dados em centavos, e sao, no";
    cout << endl << "maximo, 20000000, ou seja, R$200.000,00." << endl;
    cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
    cout << endl << "=========================================";
    cout << endl << "Forneca um tag para a Hospedagem:";
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
        esperarInput();
        return false;
    }
    cout << endl << "Forneca um nome para a Hospedagem:";
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
        esperarInput();
        return false;
    }
    cout << endl << "Forneca um preco em centavos para a diaria da Hospedagem: ";
    string precoStr;
    getline(cin, precoStr);
    try
    {
        int preco = stoi(precoStr);
        Dinheiro aux(preco);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        esperarInput();
        return false;
    }
    cout << endl << "Forneca uma avaliacao para a Hospedagem: ";
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
        esperarInput();
        return false;
    }

    Hospedagem novoHospedagem(contaAutenticada,
                              Nome(nome),
                              Avaliacao(stoi(avaliacaoStr)),
                              Dinheiro(stoi(precoStr)),
                              Codigo(tag),
                              destinoAssociado);
    if (cntrIBHospedagem->criar(novoHospedagem))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MFHospedagem::run(Codigo contaAutenticada, Codigo destinoAssociado)
{
    bool atualizarHospedagem = true;
    bool operando = true;
    while (operando)
    {
        system("cls");
        if (atualizarHospedagem)
        {
            hospedagemRegistradas = cntrIBHospedagem->ler(contaAutenticada, destinoAssociado);
            atualizarHospedagem = false;
        }
        cout << endl << "=========================================";
        cout << endl << "               HOSPEDAGENS";
        cout << endl << "           DO DESTINO "; cout << destinoAssociado.getValor();
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Retornar";
        cout << endl << "    1. Criar nova Hospedagem";
        cout << endl << "    2. Manejar Hospedagem registradas";
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
                    bool sucesso = criarHospedagem(contaAutenticada, destinoAssociado);
                    if (sucesso)
                    {
                        cout << endl << "Hospedagem criada com sucesso.";
                        atualizarHospedagem = true;
                    }
                    else
                    {
                        cout << endl << "Hospedagem nao foi criada. Tente novamente.";
                    }
                }
                catch (const runtime_error &exp)
                {
                    cout << endl << "Algum erro aconteceu.";
                }
                esperarInput();
                break;
            case 2:
                if ((int)hospedagemRegistradas.size() == 0)
                {
                    cout << endl << "Nao ha hospedagens registradas";
                    esperarInput();
                    break;
                }
                atualizarHospedagem = processHospedagem();
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
    return;
}
