//Jogo.h
#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"

class Jogo
{

private:
    vector<Jogador *> lista_jogadores;
    int tempoSequencia;
    int tempoGameplay;
    int qtdFrutas;
    string dificuldade;

public:
    Jogo(int tempoSeq, int tempoGam, int qtdFrutas, string dif);
    ~Jogo();

    void setTempoSeq(int);
    int getTempoSeq() const;
    void setTempoGam(int);
    int getTempoGam() const;
    void setQtdFrutas(int);
    int getQtdFrutas() const;
    void setDificuldade(string);
    string getDificuldade() const;
    void embaralha(PILHA *P);
    void iniciarTempoGam();
    void iniciarTempoSeq();
};

#endif