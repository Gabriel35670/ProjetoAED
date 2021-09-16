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


//Registro de tamanho variavel
typedef struct Registro
{
    char *nome;
    char *cpf;
    char *idade;
}Reg;


int criaArquivo(char *n_arq);
FILE* abre_arquivo(int m,char *n_arq);
FILE* fecha_arquivo(FILE *arquivo);
void escreve_arquivo(FILE *arquivo,Reg registro,int *posicao_final);
void le_arquivo(FILE *arquivo);
