#ifndef JOGOs_H
#define JOGOs_H

#include "Jogador.h"
#include "Pilha.h"

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

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