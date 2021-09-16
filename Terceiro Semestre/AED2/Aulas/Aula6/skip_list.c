#include "skip_list.h"

//Variaveis globais, para simplificar
static Noh *lista;
static int num_itens=0,nivel_max;


Noh *buscaR(Noh *t,Chave chave,int nivel){

    if(t != lista && chave == t->chave) return t; //achou o no com a chave desejada

    if(t->prox[nivel] == NULL || chave < t->prox[nivel]->chave){
        /*Caso o no proximo ao no corrente no nivel for nulo, ou a chave dele for maior do que
        a chave que se busca, a função deve descer um nivel */
        if(nivel == 0) return NULL;

        return buscaR(t,chave,nivel-1);
    }

    //So vai aqui, caso a chave do proximo no ao corrente, for menor que a chave desejada, e o proximo no nao for NULL
    return buscaR(t->prox[nivel],chave,nivel);
}

Noh *TSbusca(Chave chave){

    return buscaR(lista,chave,nivel_max);
}

int nivelAleatorio(){

    int nivel,disp_acum, d = 2, v = rand();
    disp_acum = d;
    for(nivel = 0;nivel < NMAX_NIVEIS;nivel++){

        if(v > RAND_MAX / disp_acum) break;

        disp_acum *= d;
    }
    if(nivel > nivel_max) nivel_max = nivel;

    return nivel;
}

/*Inserção em skip lists, para isso, um novo nó deve ser criado e então percorrer um caminho
semelhante ao da busca, até chegar na posição que o nó deveria ocupar no nível sorteado, e então
inseri o nó em todas as listas com nível menor ou igual ao dele*/

Noh *novo(Chave chave,Item conteudo,int num_niveis){

    int i;
    Noh *p = (Noh*)malloc(sizeof *p);
    p->chave = chave;
    p->conteudo = conteudo;

    p->prox = malloc(num_niveis*sizeof(Noh*));
    p->num_niveis = num_niveis;

    for(i = 0;i<num_niveis;i++)
        p->prox[i] = NULL;

    return p;
}

void insereR(Noh *t,Noh *novoNoh,int nivel){

    Chave chave = novoNoh->chave;

    if(t->prox[nivel] == NULL || chave < t->prox[nivel]->chave){ //nao continua no mesmo nivel

        if(nivel < novoNoh->num_niveis){ //ta inserindo
            novoNoh->prox[nivel] = t->prox[nivel];
            t->prox[nivel] = novoNoh;
        }

        if(nivel > 0) insereR(t,novoNoh,nivel - 1);

        return;
    }

    insereR(t->prox[nivel],novoNoh,nivel);//continua no mesmo nivel

}

void TSinsere(Chave chave,Item conteudo){

    int nivelAleat = nivelAleatorio();
    Noh *novoNoh = novo(chave,conteudo,nivelAleat+1);

    if(num_itens == 0) inicia(novoNoh);

    insereR(lista,novoNoh,nivel_max);
    num_itens++;
}

/*Remoção, buscar o nó normalmente, e removê-lo de todas as listas com nivel menor ou igual ao dele,
e então liberar p nó em si */

int removeR(Noh *t,Chave chave,int nivel){

    Noh *p = t->prox[nivel];
    if(p == NULL || chave <= p->chave){

        if(p != NULL && chave == p->chave){

            t->prox[nivel] = p->prox[nivel];

            if(nivel == 0){
                free(p->prox);
                free(p);

                return 1;
            }
        }
    
        if(nivel == 0) return 0;

        return removeR(t,chave,nivel-1);
    
    }

    return removeR(t->prox[nivel],chave,nivel);
}

void TSremove(Chave chave){

    removeR(lista,chave,nivel_max);
    num_itens--;
}

void inicia(){


    lista = novo(-1234567,-1234567,10);
    num_itens = 0;
    nivel_max = 10;

}



void chama_papai(){

    printf("%d\n",num_itens);
    printf("%d\n",nivel_max);
    if(lista->prox[9] == NULL)
        printf("oi\n");
    printf("%d\n",lista->prox[5]->conteudo);
}

void imprime(Noh *t,int indice){

    if(t->prox[indice] != NULL){
        printf("%d ",t->prox[indice]->chave);
        imprime(t->prox[indice],indice);
    }

    else if(indice > 0){
        printf("\n%d -> ",indice-1);
        imprime(lista,indice-1);
    }
    return ;


}
void TSimprime(){

    printf("%d -> ",nivel_max);
    imprime(lista,nivel_max);
    printf("\n");


}