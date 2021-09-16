/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: 19/08/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/

#include "tad.h"


int main(){


    int vetor[11] = {5,4,6,2,8,3,7,1,9,0,10};

    Arvore raiz = novoNoh(vetor[0],vetor[0]);

    for(int i=1;i<11;i++){

        TSinserir(raiz,vetor[i],vetor[i]);
    }

    preenchePAI(raiz);
    em_ordem(raiz);

    bool eh=true;

    if(eh)
        printf("A arvore eh binaria de busca\n");
    else
        printf("A arvore nao eh binaria de busca\n");


    int n = tamanhoArvore(raiz);
    printf("Qntd de nos: %d\n",n);
    printf("Altura recursiva da arvore: %d\n",alturaAR(raiz));

   int *v = vetorMax(raiz);
    imprimeVETOR(v,n);



    


    return 0;
}

