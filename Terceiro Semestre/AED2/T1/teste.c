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


int main(){

    char opcao;
    char nome[10];
    long int nro;

    scanf("%c",&opcao);
    scanf("%s",nome);
    scanf("%ld",&nro);

    printf("%c\n",opcao);
    printf("%s\n",nome);
    printf("%ld\n",nro);

    return 0;
}