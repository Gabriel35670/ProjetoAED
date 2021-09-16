#include "skip_list.h"


int main(){

    srand(time(NULL));
    
    int i;

    for(i =0;i<100;i++){

        TSinsere(i,i);
    }

    Noh *alvo = TSbusca(99);

    if(alvo == NULL){
        printf("O alvo nao foi encontrado\n");
    }

    else printf("Alvo encontrado\n");

    TSimprime();

    return 0;
}