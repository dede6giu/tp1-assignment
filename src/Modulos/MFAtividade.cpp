#include "../../include/Modulos/MFAtividade.hpp"
#include "../../include/Modulos/MBAtividade.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

MFAtividade::MFAtividade()
{
    cntrIBAtividade = new MBAtividade();
}

MFAtividade::~MFAtividade()
{
    delete cntrIBAtividade;
}

int MFAtividade::lerInt(std::string entrada)
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

void MFAtividade::esperarInput()
{
    cout << endl << "Pressione Enter para continuar...";
    string aux;
    getline(cin, aux);
    return;
}

void MFAtividade::printAtividade(Atividade atividadeImprimir)
{
    cout << endl << "=========================================";
    cout << endl << "                ATIVIDADE";
    cout << endl << "       Tag: " << atividadeImprimir.getTag().getValor();
    cout << endl << "TagDestino: " << atividadeImprimir.getTagDestino().getValor();
    cout << endl << "      Nome: " << atividadeImprimir.getValorNome();
    cout << endl << "      Data: " << atividadeImprimir.getValorData();
    cout << endl << "   Horario: " << atividadeImprimir.getValorHorario();
    cout << endl << "   Duracao: " << atividadeImprimir.getValorDuracao() << " min";
    cout << endl << "     Preco: R$" << atividadeImprimir.getValorPrecoFormatado();
    cout << endl << " Avaliacao: ";
    for (int i = 0; i < atividadeImprimir.getValorAvaliacao(); i++)     cout << "*";
    for (int i = 0; i < 5 - atividadeImprimir.getValorAvaliacao(); i++) cout << "-";
    cout << endl << "=========================================";
}

bool MFAtividade::editarAtividade(Atividade atividadeAtual, Destino destinoAssociado)
{
    cout << endl << "=========================================";
    cout << endl << "                  EDITAR";
    cout << endl << "Operacoes disponiveis:";
    cout << endl << "    0. Retornar";
    cout << endl << "    1. Editar Nome";
    cout << endl << "    2. Editar Data";
    cout << endl << "    3. Editar Horario";
    cout << endl << "    4. Editar Duracao";
    cout << endl << "    5. Editar Preco";
    cout << endl << "    6. Editar Avaliacao";
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
                if (cntrIBAtividade->atualizar(atividadeAtual, nomeNovo))
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
            cout << endl << "Qual a nova data?";
            cout << endl << "DD/MM/AA" << endl;
            getline(cin, comando);
            try
            {
                Data dataNovo(comando);
                if (destinoAssociado.getValorInicio() > dataNovo
                    || destinoAssociado.getValorFim() < dataNovo)
                {
                    cout << endl << "Data da atividade deve ocorrer dentro do periodo do destino associado";
                    break;
                }
                if (cntrIBAtividade->atualizar(atividadeAtual, dataNovo))
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
            cout << endl << "Qual o novo horario?";
            cout << endl << "HH:mm" << endl;
            getline(cin, comando);
            try
            {
                Horario horarioNovo(comando);
                if (cntrIBAtividade->atualizar(atividadeAtual, horarioNovo))
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
            cout << endl << "Qual a nova duracao?";
            cout << endl << "De 0 a 360 minutos." << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Duracao duracaoNovo(resultado);
                if (cntrIBAtividade->atualizar(atividadeAtual, duracaoNovo))
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
        case 5:
            cout << endl << "Qual o novo preco em centavos?";
            cout << endl << "De 0 a 20000000." << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Dinheiro precoNovo(resultado);
                if (cntrIBAtividade->atualizar(atividadeAtual, precoNovo))
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
        case 6:
            cout << endl << "Qual a nova avaliacao?";
            cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
            getline(cin, comando);
            try
            {
                resultado = stoi(comando);
                Avaliacao nomeAvaliacao(resultado);
                if (cntrIBAtividade->atualizar(atividadeAtual, nomeAvaliacao))
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

bool MFAtividade::processAtividade(Destino destinoAssociado)
{
    bool atualizarAtividade = false;
    int posicaoAtual = 0;
    while (true)
    {
        int posicaoMaxima = atividadeRegistradas.size();
        posicaoAtual %= posicaoMaxima; // failsafe
        if (posicaoMaxima == 0)
        {
            // nenhuma viagem disponivel
            atualizarAtividade = true;
            return atualizarAtividade;
        }

        system("cls");

        printAtividade(atividadeRegistradas[posicaoAtual]);
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
                return atualizarAtividade;
            case 1:
                posicaoAtual += posicaoMaxima-1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 2:
                posicaoAtual += posicaoMaxima+1;
                posicaoAtual %= posicaoMaxima;
                break;
            case 3:
                cout << endl << "Informe a tag da Atividade desejada: ";
                getline(cin, comando);
                try
                {
                    Codigo tagFornecida(comando);
                    int posicaoInicial = posicaoAtual;
                    for (int i = 0; i < posicaoMaxima; i++)
                    {
                        if (atividadeRegistradas[i].getTag().getValor() == tagFornecida.getValor())
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
                atualizarAtividade = true;
                try
                {
                    bool sucesso = editarAtividade(atividadeRegistradas[posicaoAtual], destinoAssociado);
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
                return atualizarAtividade;
            case 5:
                cout << endl << "Deseja excluir essa Atividade?";
                cout << endl << "Tem certeza disso? (S/n) ";
                getline(cin, comando);
                if (comando == "S" || comando == "s")
                {
                    atualizarAtividade = true;
                    try
                    {
                        if (cntrIBAtividade->excluir(atividadeRegistradas[posicaoAtual]))
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
                    return atualizarAtividade;
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

bool MFAtividade::criarAtividade(Codigo contaAutenticada, Destino destinoAssociado)
{
    system("cls");
    cout << endl << "=========================================";
    cout << endl << "              NOVA ATIVIDADE";
    cout << endl << "Uma Atividade possui um tag, um nome, uma";
    cout << endl << "data, um horario, uma duracao, um preco,";
    cout << endl << "e uma avaliacao." << endl;
    cout << endl << "Tag sao identificadores unicos de 6 caracteres.";
    cout << endl << "Podem ser letras min e maiusculas, ou numeros." << endl;
    cout << endl << "Nomes sao compostos de, no maximo, 30 caracteres" << endl;
    cout << endl << "Datas sao do tipo 'DD/MM/AA'." << endl;
    cout << endl << "Horarios sao do tipo 'HH:mm'." << endl;
    cout << endl << "Duracoes sao dadas em minutos. Max 360." << endl;
    cout << endl << "Preco sao dados em centavos, e sao, no";
    cout << endl << "maximo, 20000000, ou seja, R$200.000,00." << endl;
    cout << endl << "Avaliacao vai de 1 a 5, inclusivo" << endl;
    cout << endl << "=========================================";
    cout << endl << "Forneca um tag para a Atividade:";
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
    cout << endl << "Forneca um nome para a Atividade:";
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
    cout << endl << "Forneca uma data para a Atividade:";
    cout << endl << "DD/MM/AA" << endl;
    string data;
    getline(cin, data);
    try
    {
        Data aux(data);
        if (destinoAssociado.getValorInicio() > aux
            || destinoAssociado.getValorFim() < aux)
        {
            cout << endl << "Data da atividade deve ocorrer dentro do periodo do destino associado";
            return false;
        }
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }
    cout << endl << "Forneca um horario para a Atividade:";
    cout << endl << "HH:mm" << endl;
    string horario;
    getline(cin, horario);
    try
    {
        Horario aux(horario);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }
    cout << endl << "Forneca uma duracao para a Atividade: ";
    string duracaoStr;
    getline(cin, duracaoStr);
    try
    {
        int duracao = stoi(duracaoStr);
        Dinheiro aux(duracao);
    }
    catch (const exception &exp)
    {
        cout << endl << "Valor invalido.";
        return false;
    }
    cout << endl << "Forneca um preco em centavos para a Atividade: ";
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
        return false;
    }
    cout << endl << "Forneca uma avaliacao para a Atividade: ";
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

    Atividade novoAtividade(contaAutenticada,
                            Nome(nome),
                            Data(data),
                            Horario(horario),
                            Duracao(stoi(duracaoStr)),
                            Dinheiro(stoi(precoStr)),
                            Avaliacao(stoi(avaliacaoStr)),
                            Codigo(tag),
                            destinoAssociado.getTag());
    if (cntrIBAtividade->criar(novoAtividade))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MFAtividade::run(Codigo contaAutenticada, Destino destinoAssociado)
{
    bool atualizarAtividade = true;
    bool operando = true;
    while (operando)
    {
        system("cls");
        if (atualizarAtividade)
        {
            atividadeRegistradas = cntrIBAtividade->ler(contaAutenticada, destinoAssociado.getTag());
            atualizarAtividade = false;
        }
        cout << endl << "=========================================";
        cout << endl << "               ATIVIDADES";
        cout << endl << "           DO DESTINO "; cout << destinoAssociado.getTag().getValor();
        cout << endl << "Operacoes disponiveis:";
        cout << endl << "    0. Retornar";
        cout << endl << "    1. Criar nova Atividade";
        cout << endl << "    2. Manejar Atividade registradas";
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
                    bool sucesso = criarAtividade(contaAutenticada, destinoAssociado);
                    if (sucesso)
                    {
                        cout << endl << "Atividade criada com sucesso.";
                        atualizarAtividade = true;
                    }
                    else
                    {
                        cout << endl << "Atividade nao foi criada. Tente novamente.";
                    }
                }
                catch (const runtime_error &exp)
                {
                    cout << endl << "Algum erro aconteceu.";
                }
                esperarInput();
                break;
            case 2:
                if ((int)atividadeRegistradas.size() == 0)
                {
                    cout << endl << "Nao ha atividades registradas";
                    esperarInput();
                    break;
                }
                atualizarAtividade = processAtividade(destinoAssociado);
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
