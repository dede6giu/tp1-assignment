#include <iostream>
#include "TU/TUDuracao.hpp"

using namespace std;

int main()
{
    TUDuracao testes;

    switch (testes.run())
    {
        case TUDuracao::SUCESSO:
            cout << "SUCESSO" << endl;
            break;
        case TUDuracao::FALHA:
            cout << "FALHA" << endl;
            break;
    }

    return 0;
}
