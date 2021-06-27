//Jogador.h
#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#include "Pilha.h"


class Jogador
{

private:
    string nome;
    int pontuacao;
    PILHA *P;
    static int contador;

public:
    Jogador(string nome, int t);
    ~Jogador();

    void setNome(string);
    string getNome() const;
    bool JogadorEmpilha(No *n);
    PILHA *getPilha();
    void LPilha();

    void aumentaPontuacao();
    int getPontos() const;
    void controlaCont(int x);
};

#endif