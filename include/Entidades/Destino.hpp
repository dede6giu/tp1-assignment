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
        Data fim;
        Avaliacao avaliacao;
        bool validar(); //!< não ainda implementado

    public:
        Destino();
        Destino(const Codigo&, const Nome&, const Data&,const Avaliacao&);

        void setValor(const Codigo&);
        inline std::string getValorCodigo() const;

        void setValor(const Nome&);
        inline std::string getValorNome() const;

        void setValor(const Avaliacao&);
        inline int getValorAvaliacao() const;

        void setValor(const Data&, bool);
        inline std::string getValorInicio() const;
        inline std::string getValorFim() const;
};

inline std::string Destino::getValorCodigo() const {
    return this->codigo.getValor();
}

inline std::string Destino::getValorNome() const {
    return this->nome.getValor();
}

inline int Destino::getValorAvaliacao() const {
    return this->avaliacao.getValor();
}

inline std::string Destino::getValorInicio() const {
    return this->inicio.getValor();
}

inline std::string Destino::getValorFim() const {
    return this->fim.getValor();
}


#endif // DESTINO_HPP_INCLUDED
