#ifndef MBATIVIDADE_HPP_INCLUDED
#define MBATIVIDADE_HPP_INCLUDED

#include "../Interfaces/IBAtividade.hpp"
#include <sqlite3.h>

/*!
    232013031 - Implementação.
*/
class MBAtividade : public IBAtividade
{
    private:

    sqlite3* banco;

    public:

        MBAtividade();
        ~MBAtividade();

        bool criar(Atividade);
        void criar(Codigo);
        bool excluir(Atividade);
        void excluir(Codigo);
        void excluir(Codigo, Codigo);
        bool ler(Atividade);
        std::vector<Atividade> ler(Codigo, Codigo);
        bool atualizar(Atividade, Nome);
        bool atualizar(Atividade, Data);
        bool atualizar(Atividade, Horario);
        bool atualizar(Atividade, Duracao);
        bool atualizar(Atividade, Dinheiro);
        bool atualizar(Atividade, Avaliacao);
};

#endif // MBATIVIDADE_HPP_INCLUDED
