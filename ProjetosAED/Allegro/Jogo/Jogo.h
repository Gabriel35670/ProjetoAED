#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Pilha.h"

class Jogo
{

private:
    vector<Jogador *> lista_jogadores;
    int tempoSequencia;
    int tempoGameplay;

public:
    Jogo(int tempoSeq, int tempoGam);
    ~Jogo();

    void setTempoSeq(int);
    int getTempoSeq() const;
    void setTempoGam(int);
    int getTempoGam() const;
    void embaralha(PILHA *P);
    void iniciarTempoGam();
    void iniciarTempoSeq();
};

#endif