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
#include <time.h>

//Estrutura de um nó de uma skip list

#define NMAX_NIVEIS 100

typedef int Chave;
typedef int Item;

typedef struct noh{

    Chave chave;
    Item conteudo;
    struct noh **prox;
    /*
    vetor de apontadores para noh, ou seja, uma lista de apontadores
    */
    int num_niveis;
}Noh;

Noh *buscaR(Noh *t,Chave chave,int nivel);
Noh *TSbusca(Chave chave);

int nivelAleatorio();
Noh *novo(Chave chave,Item conteudo,int num_niveis);

void insereR(Noh *t,Noh *novoNoh,int nivel);
void TSinsere(Chave chave,Item conteudo);
int removeR(Noh *t,Chave chave,int nivel);
void TSremove(Chave chave);

void inicia();
void chama_papai();

void TSimprime();
void imprime(Noh *t, int indice);