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
#include <math.h>
#include <string.h>

//Implementação das funções de espalhamento

/*Objetivo: h deve ser:

-Deterministica
-Rápida de calcular
-Ocupa pouco espaço
-Espalha as chaves uniformemente pelo vetor*/

//SUponha-se que a chave é uma string, faz com que todo caractere tenha influencia no resultado
typedef char* Chave;

int hash(Chave chave,int M){

    int i, h=0;

    for(i = 0; chave[i] != '\0';i++){
        h += chave[i];
    }

    h = h % M;
    return h;
}

//Caracteres com valores múltiplos de M são irrelevantes, logo não contribui para o resultado

//Multipla cada caractere por um nuero primo, que so é divido por 1 e por ele mesmo, ou seja, caso M não for o numero primo em questão, o resto dará != 0

int hash2(Chave chave,int M){

    int i,h=0;
    int primo = 127;

    for(i = 0; chave[i] != '\0';i++)
        h += primo * chave[i];

    h = h % M;

    return h;
}

//A variavel primo deve ter um valor proximo e m, NÃO deve ser muito próximo
//Mas essa função tem problemas, chaves que são anagramas caem no mesmo lugar, e também quaiquer chaves cujos caracteres somam o mesmo valor, caem na mesma
//posição


//Notação posicional
long int hash3(Chave chave,int M){

    int i,h=0;
    int primo = 127;

    for(i = 0; chave[i] != '\0';i++)
        h += pow(primo,i) * chave[i];

    h = h % M;

    return h;
}

//Essa função pode resultar em problemas de eficiencia e corretude

/*Essa nova visão, pode ser implementada, sem a ultilização da operação de potencia, que muitas vezes pode gerar números grotescos, e possivelmente
estourar a quantidade maxima de memória

c1*p + c2*p²+c3*p³ == p(c1+p(c2+p(c3+...))))...)
*/

long int hash4(Chave chave,int M){

    int i,h=0;
    int primo = 127;

    for(i = 0; chave[i] != '\0';i++){
        h = (h*primo + chave[i]);
    }

    h = h % M;

    return h;
}

/*Ao ultilizar essa funções, o numero da variavel h, pode crescer tanto, que gere um estouro de variável, e ocorra um erro numérico

Para evitar esse erro podemos ultilizar a seguinte propriedade do resto:

(a+b)%M = (a%M + b%M)%M , assim chegamos a seguinte função de espalhamento

*/

int hash5(Chave chave,int M){

    int i,h=0;
    int primo = 127;

    for(i = 0; chave[i] != '\0';i++)
        h = (h*primo  + chave[i]) % M;
    return h;
}

/*Eficiencia de tempo:

Nossas funções tem eficiencia proporcional ao numero de digitos da chave, por isso podem nao ser eficientes com chaves muito grandes, mas com relação ao numero
de itens da tabrla, o tempo é constante, i.e O(1)

Funções de espalhamento de referencia: FarmHase,MurMurHase3,SpookyHash,MD5*/


int main(){

    Chave strings[10] = {"felipe","gabriel","ana","ricardo","claudia","roberta","eva","naomi","luna","dora"};

    //Hash 1
    printf("\n\nHash 1\n\n");

    for(int i=0;i<10;i++){

        int h = hash(strings[i],10);
        printf("A chave %s esta na posicao: {%d}\n",strings[i],h);
    }

    //Hash 2
    printf("\n\nHash 2\n\n");

    for(int i=0;i<10;i++){

        int h = hash2(strings[i],10);
        printf("A chave %s esta na posicao: {%d}\n",strings[i],h);
    }

    //Hash 3
    printf("\n\nHash 3\n\n");

    for(int i=0;i<10;i++){

        long int h = hash3(strings[i],10);
        if(h < 0 || h > 9)
            printf("Posicao invalida, devido a funcao de espalhamento\n");
        else
            printf("A chave %s esta na posicao: {%ld}\n",strings[i],h);
    }

    //Hash 4
    printf("\n\nHash 4\n\n");
    for(int i=0;i<10;i++){

       long int h = hash4(strings[i],10);
         if(h < 0 || h > 9)
            printf("Posicao invalida, devido a funcao de espalhamento\n");
        else
            printf("A chave %s esta na posicao: {%ld}\n",strings[i],h);
    }

    //Hash 5
    printf("\n\nHash 5\n\n");
    for(int i=0;i<10;i++){

        int h = hash5(strings[i],10);
        printf("A chave %s esta na posicao: {%d}\n",strings[i],h);
    }

    return 0;
}