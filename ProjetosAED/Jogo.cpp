#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Jogo.h"
#include "Fruta.h"

Jogo::Jogo(int tempoSeq, int tempoGam)
{

    setTempoSeq(tempoSeq);
    setTempoGam(tempoGam);
}

Jogo::~Jogo() {}

void Jogo::setTempoSeq(int tempoSeq)
{
    if (tempoSeq <= 0)
    {
        cout << "Tempo inválido" << endl;
    }
    else
    {
        tempoSequência = tempoSeq;
    }
}

void Jogo::setTempoGam(int tempoGam)
{
    if (tempoGam <= 0)
    {
        cout << "Tempo inválido" << endl;
    }
    else
    {
        tempoGameplay = tempoGam;
    }
}

int Jogo::getTempoGam() const
{
    return tempoGameplay;
}

int Jogo::getTempoSeq() const
{
    return tempoSequência;
}

void Jogo::embaralha(PILHA *P)
{
    vector<Fruta *> frutas;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gera uma "seed" aleatoria

    shuffle(frutas.begin(), frutas.end(), default_random_engine(seed));

    for (int i = 0; i < frutas.size(); i++)
    {
        No *N;
        N = new No;
        N->f = frutas[i];
        Empilhar(P, N);
    }
}