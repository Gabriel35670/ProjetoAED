//Includes
#include "buttons/button.h"

#include "timer/timer.h"


#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//Jogador.h
#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED


class Jogador
{

    private:
        string nome;
        int pontuacao;
        static int contador;

    public:
        Jogador(string nome);
        ~Jogador();

        void setNome(string);
        string getNome() const;

        void aumentaPontuacao();
        int getPontos() const;
        void controlaCont(int x);


};

#endif

//Fruta.h
#ifndef FRUTA_H
#define FRUTA_H


struct Fruta{

    string nome;
    BITMAP *img;

};

typedef Fruta fruta;


fruta* criaFruta(string n);

string getFileName(string n);

bool igual(fruta *f1,fruta *f2);

vector<fruta *> vet_frutas(int x); 

#endif

//No.h
#ifndef NOH_H
#define NOH_H



struct Noh
{
    fruta *f;
    struct Noh *proximo;
};

typedef Noh No;

No* criaNo(fruta *fruta);
No* LiberaNo(No *X);

#endif

//Pilha.h
#ifndef PILHAJOGO_H
#define PILHAJOGO_H


struct Pilha
{
    int tamanhoMAX;
    No *topo;
};

typedef Pilha PILHA;

PILHA* CriarPilha(int tamanhoMAX);
PILHA* LiberarPilha(PILHA *P);

bool Empilhar(PILHA *P,No *X);
bool Desempilhar(PILHA *P,No *X);

bool Vazia(PILHA *P);
bool Cheia(PILHA *P);

int ComparaPilhas(PILHA *P1, PILHA *P2);

void imprimePILHA(PILHA *P, BITMAP *buffer,int width,int height);

#endif


//Jogo.h
#ifndef JOGO_H
#define JOGO_H

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
    void embaralha(PILHA *P,int tamanho);
    void iniciarTempoGam();
    void iniciarTempoSeq();
};

#endif


//screen.h
#ifndef TELAS_H
#define TELAS_H



void menu(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void single_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,Jogador *j);
void multi_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void memory_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,PILHA *P);
void game_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void final_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void config_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);

#endif
