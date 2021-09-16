/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: XX/XX/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Cont;
typedef int Chave;

typedef struct noh{

    int bal;
    Chave chave;
    Cont conteudo;
    struct noh *pai;
    struct noh *esq;
    struct noh *dir;

}Noh;

typedef Noh *Arvore;

Arvore rotacaoDir(Arvore r);
Arvore rotacaoEsq(Arvore r);

Noh *novoNOH(Chave chave,Cont conteudo);
Arvore insereAVL(Noh *r,Noh *novo,int *aumentou_altura);
Arvore inserir(Arvore r,Chave chave,Cont conteudo);

void em_ordem(Arvore r);
void pre_ordem(Arvore r);
void pos_ordem(Arvore r);

int alturaAR(Arvore r);//

int verifica(Arvore r);

Arvore balanceamento_esquerdo(Arvore r, int *diminuiu_altura);
Arvore balanceamento_direito(Arvore r, int *diminuiu_altura);
Arvore busca_remove(Arvore r, Arvore noh_chave, int *diminuiu_altura);
Arvore removeAVL(Arvore r, Chave chave, int *diminuiu_altura);
Arvore remover(Arvore r, Chave chave);