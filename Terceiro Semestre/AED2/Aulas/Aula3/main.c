#include "avl.h"


int main(){

    int vetor[10];
    for(int i=0;i<10;i++)
        vetor[i] = i;

    Arvore raiz = NULL;
    raiz = inserir(raiz, vetor[0],vetor[0]);

    //int v2[6] = {4,3,7,6,10,5};
    for(int i=1;i <10;i++){

        printf("Insercao nro -> [%d]\n\n",i);
        raiz = inserir(raiz,vetor[i],vetor[i]);
        em_ordem(raiz);
        printf("\n\n");
        pre_ordem(raiz);
        printf("\n\n");
       /* pos_ordem(raiz);
        printf("\n\n");*/

       
    }

    int tamanho = alturaAR(raiz);
    printf("a altura eh: %d\n",tamanho);

    int verificar = verifica(raiz);
    if(verificar)
        printf("Arvore eh AVL\n");
    else
        printf("Arvore nao eh AVL\n");

    raiz = remover(raiz,0);

    em_ordem(raiz);



    return 0;

}