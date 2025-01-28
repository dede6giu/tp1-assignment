#ifndef SBVIAGEM_HPP_INCLUDED
#define SBVIAGEM_HPP_INCLUDED

#include "../Interfaces/IBViagem.hpp"
#include <string>

class SBViagem : public IBViagem {
    private:

        const static int TRIGGER_FALHA_AVALIACAO;
        const static std::string TRIGGER_FALHA_CODIGO;
        const static std::string TRIGGER_FALHA_NOME;

    public:

        bool criar(Viagem);
        bool excluir(Viagem);
        bool ler(Codigo);
        bool atualizar(Viagem, Avaliacao);
        bool atualizar(Viagem, Codigo);
        bool atualizar(Viagem, Nome);
};

#endif // SBVIAGEM_HPP_INCLUDED
