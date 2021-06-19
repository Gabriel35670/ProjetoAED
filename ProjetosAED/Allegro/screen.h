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
bool Desempilhar(PILHA *P,No *X,bool acabou);

bool Vazia(PILHA *P);
bool Cheia(PILHA *P);

int ComparaPilhas(PILHA *P1, PILHA *P2);

void imprimePILHA(PILHA *P, BITMAP *buffer,int width,int height,int jeito=0);

#endif

//Jogador.h
#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED


class Jogador
{

    private:
        string nome;
        int pontuacao;
        PILHA *P;
        static int contador;

    public:
        Jogador(string nome);
        ~Jogador();

        void setNome(string);
        string getNome() const;

        void aumentaPontuacao();
        int getPontos() const;
        void controlaCont(int x);

        bool JogadorEmpilha(No *n);
        PILHA* getPilha();
        void LPilha();


};

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
void game_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,Jogador *j1);
void final_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,PILHA *P, Jogador *j1);
void config_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void verifica_botao(Button *b1,BITMAP *iFruta,BITMAP *highlight,SAMPLE *click,Jogador *j1,No *noh,int *cont,int height,int dF);

#endif

/*
if(b_maca->ativado){
			bool entrou = false;
			b_maca->ativado = false;
			if(b_maca->pos_y == height/1.2 && Empilhar(j1->getPilha(),noh[2])){
				destroy_button(b_maca);
				b_maca = create_button(maca,voltar_highlight,click,1+(80*contadorPilha),height/2);
				contadorPilha++;
				entrou = true;
			}
			else{
				if(Desempilhar(j1->getPilha(),noh[2],false)){
				destroy_button(b_maca);
				b_maca = create_button(maca,voltar_highlight,click,160,height/1.2);
				contadorPilha--;
				entrou = true;	
				}
			}
			if(entrou){
				button_input(b_maca);
			}

		}
*/