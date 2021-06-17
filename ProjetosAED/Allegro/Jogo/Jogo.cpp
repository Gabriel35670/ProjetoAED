#include "Jogo.h"

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
        tempoSequencia = tempoSeq;
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
    return tempoSequencia;
}

void Jogo::embaralha(PILHA *P)
{
    vector<fruta *> frutas;

    frutas = vet_frutas(5);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gera uma "seed" aleatoria

    shuffle(frutas.begin(), frutas.end(), default_random_engine(seed));

    int tamanho = frutas.size();
    for (int i = 0; i < tamanho; i++)
    {
        No *N;
        N = new No;
        N->f = frutas[i];
        Empilhar(P, N);
    }
}