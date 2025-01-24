#include "../../include/Controladores/CIFViagem.hpp"
#include "../../include/Dominios/Avaliacao.hpp"
#include "../../include/Dominios/Codigo.hpp"
#include "../../include/Dominios/Nome.hpp"
#include <iostream>

using namespace std;

bool CIFViagem::criar() {
    Codigo codigo;
    Avaliacao avaliacao;
    Nome nome;
    string aux0; int aux1;

    while (true) {
        cout << "Criação de Viagem" << endl << endl;

        try {
            cout << "Forneça o código: ";
            cin >> aux0;
            codigo.setValor(aux0);
            cout << "Forneça a avaliação: ";
            cin >> aux1;
            avaliacao.setValor(aux1);
            cout << "Forneça o nome: ";
            cin >> aux0;
            nome.setValor(aux0);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << "Formatação incorreta." << endl;
        }
        catch (const invalid_argument & exp) {
            cout << "Formatação incorreta." << endl;
        }
    }

    Viagem viagemRecebida;
    viagemRecebida.setValor(codigo);
    viagemRecebida.setValor(avaliacao);
    viagemRecebida.setValor(nome);

    bool resultado = cntrIBViagem->criar(viagemRecebida);

    if (resultado)
        return true;
    return false;
}
