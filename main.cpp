#include <iostream>
#include <string>
#include <exception>
#include "include/Interfaces.hpp"
#include "include/Modulos.hpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    IFControle* cntrIFControle = new MFControle();
    IFConta* dep1 = new MFConta();
    IFDados* dep2 = new MFDados();
    IFAutenticacao* dep3 = new MFAutenticacao();

    cntrIFControle->setCntrIFConta(dep1);
    cntrIFControle->setCntrIFDados(dep2);
    cntrIFControle->setCntrIFAutenticacao(dep3);

    try
    {
        cntrIFControle->run();
    }
    catch (const runtime_error &exp)
    {
        cout << &exp;
    }


    delete dep1;
    delete dep2;
    delete dep3;

    return 0;
}
