#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "Dominios/Codigo.hpp"
#include "Dominios/Nome.hpp"
#include "Dominios/Data.hpp"
#include "Dominios/Avaliacao.hpp"


//! Entidade Destino
/*!
    Entidade Destino \n
    232013031 - implementação
*/

class Destino
{
    private:
        Codigo codigo;
        Nome nome;
        Data inicio;
        Data Fim;
        Avaliacao avaliacao;
        bool validar();

    public:
        bool setValor(Codigo);
        bool setValor(Nome);
        bool setValor(Avaliacao);
        bool setValor(Data, bool);
};

#endif // DESTINO_HPP_INCLUDED
