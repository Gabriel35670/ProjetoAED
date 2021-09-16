/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: XX/XX/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/

#include "fCompl.h"

#include <time.h>
#include <math.h>

//Variaveis globais

clock_t stime,etime;
double cpu_time_used;



void imprime(int v[],int n){

    for(int i=0;i<n;i++){
        if(i != n-1)
            printf("[%d] ",v[i]);
        else
            printf("[%d]\n",v[i]);
    }
}

bool buscaExaustiva1(int v[],int n,int alvo){

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){
            if(v[i]+v[j] == alvo)
                return true;
        }
    }

    return false;
}

bool buscaExaustiva2(int v[],int n,int alvo){
   
    int i,j;

    for(i=0;i<n-1;i++){

        int complemento = alvo - v[i];

        for(j=i+1;j<n;j++)
            if(v[j] == complemento)
                return true;
    }

    return false;
}

bool BuscaBinaria(int v[],int n,int alvo){

    sort(v,n);

    for(int i=0;i<n-1;i++){

        int complemento = alvo - v[i];

        if(bBinaria(v,n,complemento,i))
            return true;
    }

    return false;
}

bool buscaInteligente(int v[],int n,int alvo){

    int j = n-1;
    sort(v,n);

    for(int i=0;i<j;i++){
        int complemento = alvo - v[i];

        for(;j>i && v[j] >= complemento;j--)
            if(v[j] == complemento)
                return true;
    }

    return false;
}

int main(){

    int tamanho;

    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tamanho);

    //int *vetor = (int*)malloc(sizeof(int)*tamanho);
    int vetor[10] = {4,5,6,7,8,9,10,11,12,13};

    /*for(int i=0;i<tamanho;i++){

        vetor[i] = 2*(tamanho-i-1);
    }*/

    //imprime(vetor,tamanho);

    int alvo = 10;
    bool achou = false;

    stime = clock();
    achou = buscaExaustiva1(vetor,tamanho,alvo);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;

    if(achou)
        printf("A soma %d foi achada pela BE1, e demorou %lf\n",alvo,cpu_time_used);
    else
        printf("A soma %d nao foi achada pela BE1, e demorou %lf\n",alvo,cpu_time_used);

    stime = clock();
    achou = buscaExaustiva2(vetor,tamanho,alvo);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;

    if(achou)
        printf("A soma %d foi achada pela BE2, e demorou %lf\n",alvo,cpu_time_used);
    else
        printf("A soma %d nao foi achada pela BE2, e demorou %lf\n",alvo,cpu_time_used);

    stime = clock();
    achou = BuscaBinaria(vetor,tamanho,alvo);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;

    if(achou)
        printf("A soma %d foi achada pela BB2, e demorou %lf\n",alvo,cpu_time_used);
    else
        printf("A soma %d nao foi achada pela BB2, e demorou %lf\n",alvo,cpu_time_used);

    //Reefazendo a aleatoriedade
   /* for(int i=0;i<tamanho;i++){

        vetor[i] = 2*(tamanho-i-1);
    }*/

    stime = clock();
    achou = buscaExaustiva1(vetor,tamanho,alvo);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;

    if(achou)
        printf("A soma %d foi achada pela BI2, e demorou %lf\n",alvo,cpu_time_used);
    else
        printf("A soma %d nao foi achada pela BI2, e demorou %lf\n",alvo,cpu_time_used);

    
    

    return 0;
}
