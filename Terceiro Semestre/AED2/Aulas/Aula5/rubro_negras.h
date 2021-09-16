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
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0


/* Estrutura de um nó de arvore rubro negra, mas esse código trata sobre arvores rubro negras esquerdistas, pois os nós vermelhos sempre são filhos esquerdos*/


typedef int Item;
typedef int Chave;

typedef struct noh{

    int vermelho;
    Chave chave;
    Item conteudo;
    struct noh *pai;
    struct noh *esq;
    struct noh *dir;

}Noh;

typedef Noh *Arvore;


//Funções

Noh *novoNoh(Chave chave,Item conteudo);

Arvore insereRN(Noh *r,Noh *novo);
Arvore inserir(Arvore r,Chave chave,Item conteudo);

Arvore rotacaoDir(Arvore r);
Arvore rotacaoEsq(Arvore r);