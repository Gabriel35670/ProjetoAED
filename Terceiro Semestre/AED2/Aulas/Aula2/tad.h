/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: 19/08/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Chave;
typedef int Cont;

typedef struct noh{

    Chave chave;
    Cont conteudo;
    int tam;

    struct noh* pai;
    struct noh* esq;
    struct noh* dir;

}Noh;

typedef Noh* Arvore;
typedef Noh TS;

Arvore TSbusca(Arvore r,Chave chave);//

Noh* novoNoh(Chave chave,Cont conteudo);//

Arvore insereR(Arvore r,Noh *novo);//
TS* TSinserir(TS *tab, Chave chave,Cont conteudo);//

Noh* TSmax(Arvore r);//
Noh* TSmin(Arvore r);//

Arvore removeNOH(Arvore alvo);//
Arvore removeraiz(Arvore alvo);
TS* TSremove(TS *tab,Chave chave);//

void em_ordem(Arvore r);//

int tamanhoArvore(Arvore r);//

int alturaAR(Arvore r);//

void preenchePAI(Arvore r);//

void verifica(Arvore r,bool *eh);//

int* vetorMax(Arvore r);//

void imprimeVETOR(int v[],int n);