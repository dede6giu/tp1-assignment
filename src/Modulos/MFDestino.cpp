#include "../../include/Modulos/MFDestino.hpp"
#include "../../include/Modulos/MBAtividade.hpp"
#include "../../include/Modulos/MBHospedagem.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

int MFDestino::lerInt(std::string entrada)
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

void MFDestino::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

void MFDestino::printDestino(Destino destinoImprimir)
{
    cout << endl << "=========================================";
    cout << endl << "                 DESTINO";
    cout << endl << "      Tag: " << destinoImprimir.getTag().getValor();
    cout << endl << "TagViagem: " << destinoImprimir.getTagViagem().getValor();
    cout << endl << "     Nome: " << destinoImprimir.getValorNome();
    cout << endl << "   Inicio: " << destinoImprimir.getValorInicio();
    cout << endl << "      Fim: " << destinoImprimir.getValorFim();
    cout << endl << "Avaliacao: ";
    for (int i = 0; i < destinoImprimir.getValorAvaliacao(); i++)     cout << "*";
    for (int i = 0; i < 5 - destinoImprimir.getValorAvaliacao(); i++) cout << "-";
    cout << endl << "=========================================";
}

bool MFDestino::editarDestino(Destino destinoAtual)
{
    cout << endl << "=========================================";
    cout << endl << "                  EDITAR";
    cout << endl << "0. Retornar";
    cout << endl << "1. Nome";
    cout << endl << "2. Data de inicio";
    cout << endl << "3. Data de fim";
    cout << endl << "4. Avaliacao";
    cout << endl << "=========================================";
    cout << endl << "Qual valor deseja editar? ";
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
                if (cntrIBDestino->atualizar(destinoAtual, nomeNovo))
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
            cout << endl << "Qual a nova data de inicio?";
            cout << endl << "DD/MM/AA" << endl;
            getline(cin, comando);
            try
            {
                Data inicioNovo(comando);
                if (inicioNovo > Data(destinoAtual.getValorFim()))
                {
                    cout << endl << "Data de inicio deve ser antes da data de fim";
                    esperarInput();
                    return false;
                }
                if (cntrIBDestino->atualizar(destinoAtual, inicioNovo, 0))
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
            cout << endl << "Qual a nova data de fim?";
            cout << endl << "DD/MM/AA" << endl;
            getline(cin, comando);
            try
            {
                Data fimNovo(comando);
                if (fimNovo < Data(destinoAtual.getValorInicio()))
                {
                    cout << endl << "Data de fim deve ser depois da data de inicio";
                    esperarInput();
                    return false;
                }
                if (cntrIBDestino->atualizar(destinoAtual, fimNovo, 1))
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
        case 4:
            cout << endl << "Qual a nova avaliacao?";
            cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Avaliacao nomeAvaliacao(resultado);
                if (cntrIBDestino->atualizar(destinoAtual, nomeAvaliacao))
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

bool MFDestino::processDestino()
{
    bool atualizarDestino = false;
    int posicaoAtual = 0;
    while (true)
    {
        int posicaoMaxima = destinoRegistrados.size();
        posicaoAtual %= posicaoMaxima; // failsafe
        if (posicaoMaxima == 0)
        {
            // nenhuma viagem disponivel
            atualizarDestino = true;
            return atualizarDestino;
        }

        system("cls");

        printDestino(destinoRegistrados[posicaoAtual]);
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Navegacao: Retornar";
        cout << endl << "    1. Navegacao: Anterior";
        cout << endl << "    2. Navegacao: Proxima";
        cout << endl << "    3. Navegacao: Pesquisar Tag";
        cout << endl << "    4. Atual: Editar";
        cout << endl << "    5. Atual: Excluir";
        cout << endl << "    6. Atual: Atividades Associadas";
        cout << endl << "    7. Atual: Hospedagens Associadas";
        cout << endl << "=========================================";
        cout << endl << "Por favor, escolha uma operacao: ";
        string comando;
        getline(cin, comando);
        int resultado = lerInt(comando);
        switch (resultado)
        {
            case 0:
                return atualizarDestino;
            case 1:
                posicaoAtual += posicaoMaxima-1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 2:
                posicaoAtual += posicaoMaxima+1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 3:
                cout << endl << "Informe a tag do Destino desejado: ";
                getline(cin, comando);
                try
                {
                    Codigo tagFornecida(comando);
                    int posicaoInicial = posicaoAtual;
                    for (int i = 0; i < posicaoMaxima; i++)
                    {
                        if (destinoRegistrados[i].getTag().getValor() == tagFornecida.getValor())
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
                atualizarDestino = true;
                try
                {
                    bool sucesso = editarDestino(destinoRegistrados[posicaoAtual]);
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
                return atualizarDestino;
            case 5:
                cout << endl << "Deseja excluir esse Destino?";
                cout << endl << "Isso excluira todas as Atividades e as Hospedagens";
                cout << endl << "associados a esse Destino. Tem certeza disso? (S/n) ";
                getline(cin, comando);
                if (comando == "S" || comando == "s")
                {
                    atualizarDestino = true;
                    try
                    {
                        if (cntrIBDestino->excluir(destinoRegistrados[posicaoAtual]))
                        {
                            cout << endl << "Sucesso na operacao.";
                            destinoRegistrados.erase(destinoRegistrados.begin() + posicaoAtual);
                            posicaoMaxima--;
                            posicaoAtual %= posicaoMaxima;
                        }
                        else
                        {
                            cout << endl << "Falha na operacao.";
                            esperarInput();
                            return atualizarDestino;
                        }
                    }
                    catch (const exception &exp)
                    {
                        cout << endl << "Erro no sistema." << endl;
                        esperarInput();
                        return atualizarDestino;
                    }
                }
                else
                {
                    cout << endl << "Operacao cancelada.";
                }
                esperarInput();
                break;
            case 6:
                cntrIFAtividade->run(Codigo(destinoRegistrados[posicaoAtual].getValorCodigo()),
                                   destinoRegistrados[posicaoAtual].getTag());
                break;
            case 7:
                cntrIFHospedagem->run(Codigo(destinoRegistrados[posicaoAtual].getValorCodigo()),
                                   destinoRegistrados[posicaoAtual].getTag());
                break;
            case -1:
            default:
                cout << endl << "Operacao Invalida.";
                break;
        }
    }
}

bool MFDestino::criarDestino(Codigo contaAutenticada, Codigo viagemAssociada)
{
    system("cls");
    cout << endl << "=========================================";
    cout << endl << "               NOVO DESTINO";
    cout << endl << "Um Destino possui um tag, um nome, um inicio";
    cout << endl << "um fim e uma avaliacao" << endl;
    cout << endl << "Tag sao identificadores unicos de 6 caracteres.";
    cout << endl << "Podem ser letras min e maiusculas, ou numeros." << endl;
    cout << endl << "Nomes sao compostos de, no maximo, 30 caracteres" << endl;
    cout << endl << "Inicio e fim sao ambos datas 'DD/MM/AA'." << endl;
    cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
    cout << endl << "=========================================";
    cout << endl << "Forneca um tag para o Destino:";
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
    cout << endl << "Forneca um nome para o Destino:";
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
    cout << endl << "Forneca uma data de inicio para o Destino:";
    cout << endl << "DD/MM/AA" << endl;
    string inicio;
    getline(cin, inicio);
    try
    {
        Data aux(inicio);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        esperarInput();
        return false;
    }
    cout << endl << "Forneca uma data de fim para o Destino:";
    cout << endl << "DD/MM/AA" << endl;
    string fim;
    getline(cin, fim);
    try
    {
        Data aux(fim);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        esperarInput();
        return false;
    }
    {
        Data aux1(inicio);
        Data aux2(fim);
        if (aux2 > aux1)
        {
            cout << endl << "Data de fim deve ser depois do inicio.";
            esperarInput();
            return false;
        }
    }
    cout << endl << "Forneca uma avaliacao para o Destino: ";
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

    Destino novoDestino(contaAutenticada,
                        Nome(nome),
                        Data(inicio),
                        Data(fim),
                        Avaliacao(stoi(avaliacaoStr)),
                        Codigo(tag),
                        viagemAssociada);
    if (cntrIBDestino->criar(novoDestino))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MFDestino::run(Codigo contaAutenticada, Codigo viagemAssociada)
{
    IBAtividade* dep1 = new MBAtividade();
    IBHospedagem* dep2 = new MBHospedagem();

    cntrIBDestino->setCntrIBAtividade(dep1);
    cntrIBDestino->setCntrIBHospedagem(dep2);
    cntrIFAtividade->setCntrIBAtividade(dep1);
    cntrIFHospedagem->setCntrIBHospedagem(dep2);

    bool atualizarDestino = true;
    bool operando = true;
    while (operando)
    {
        system("cls");
        if (atualizarDestino)
        {
            destinoRegistrados = cntrIBDestino->ler(contaAutenticada, viagemAssociada);
            atualizarDestino = false;
        }
        cout << endl << "=========================================";
        cout << endl << "                 DESTINOS";
        cout << endl << "             DA VIAGEM "; cout << viagemAssociada.getValor();
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Retornar";
        cout << endl << "    1. Criar novo Destino";
        cout << endl << "    2. Manejar Destinos registrados";
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
                    bool sucesso = criarDestino(contaAutenticada, viagemAssociada);
                    if (sucesso)
                    {
                        cout << endl << "Destino criado com sucesso.";
                    }
                    else
                    {
                        cout << endl << "Destino nao foi criado. Tente novamente.";
                    }
                }
                catch (const runtime_error &exp)
                {
                    cout << endl << "Algum erro aconteceu.";
                }
                esperarInput();
                break;
            case 2:
                if ((int)destinoRegistrados.size() == 0)
                {
                    cout << endl << "Nao ha destinos registrados";
                    esperarInput();
                    break;
                }
                atualizarDestino = processDestino();
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
    return;
}
