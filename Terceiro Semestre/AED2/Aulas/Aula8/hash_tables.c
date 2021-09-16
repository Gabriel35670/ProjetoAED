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

typedef char* Chave;
typedef long int Valor;


int hash(Chave chave,int M){

    int i,h=0;
    int primo = 127;

    for(i = 0; chave[i] != '\0';i++)
        h = (h*primo  + chave[i]) % M;
    return h;
}

typedef struct celTS{

    Chave chave;
    Valor valor;
    struct celTS *prox;

}CelTS;


typedef struct table{
    
    CelTS **tab;
    int nChaves;
    int M; //tamanho da hashtable

}HashTable;

//INicializar a hashtable
HashTable *stInit(int max){

    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    int h;

    ht->M = max;
    ht->nChaves = 0;
    ht->tab = NULL;

    ht->tab = malloc(max*sizeof(CelTS*));
    
    for(h =0;h<max;h++)
        ht->tab[h] = NULL;

    return ht;
}

bool stSearch(Chave chave,HashTable *ht,Valor *v){

    CelTS *p;
    int h = hash(chave,ht->M);
    p = ht->tab[h];

    //Procurar na lista ligada
    while(p != NULL && strcmp(p->chave,chave) != 0)
        p = p->prox;

    if(p != NULL){


        *v = p->valor;
        return true;
    }

    return false;
} //Uma solução aqui é passar uma variavel por referencia, e ultilizar uma função do tipo booleano,


void stInsert(Chave chave,Valor valor,HashTable *ht){
    //inserção ou edição

    CelTS *p;

    int h = hash(chave,ht->M);
    p = ht->tab[h];

    //Verifica se há algum valor na posição h
    while(p != NULL && strcmp(p->chave,chave))
        p = p->prox;

    if(p != NULL){

        printf("Contatinho ja inserido\n");
        return;

    }
    else{
       
        p = (CelTS*)malloc(sizeof(CelTS));
        p->chave = malloc(10);
        strcpy(p->chave,chave);
       
        ht->nChaves += 1;
        p->prox = ht->tab[h];
        ht->tab[h] = p;
    }

    p->valor = valor; //atualiza o valor do item. uma edição
    return;

}

void stEdit(Chave chave,Valor valor,HashTable *ht){
    
    CelTS *p;

    int h = hash(chave,ht->M);

    p = ht->tab[h];

    //Verifica se há algum valor na posição h
   while(p != NULL && (strcmp(p->chave,chave) != 0))
        p = p->prox;

    if(p != NULL){
        p->valor = valor;
        return;
    }

    printf("Operacao invalida: contatinho nao encontrado\n");
    return;
}

void stDelete(Chave chave,HashTable *ht){
    
    CelTS *p, *aux;

    int h = hash(chave,ht->M);
    p = ht->tab[h];

    if(p == NULL){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return ;
    }

    //Dois casos, remoção na cabeça da lista, e remoção no corpo da lista
    if(strcmp(p->chave,chave) == 0){

        ht->tab[h] = p->prox;
        free(p->chave);
        free(p);
        ht->nChaves--;
        return;
    }

    //Remoção no restante da lista, bem mais simples
    while(p->prox != NULL && strcmp((p->prox)->chave,chave) != 0)
        p = p->prox;

    //Se o proximo é o valor
    if(p->prox != NULL){
        aux = p->prox;
        p->prox = aux->prox;
        free(aux->chave);
        free(aux);
        ht->nChaves--;

        return;
    }

    printf("Operacao invalida: contatinho nao encontrado\n");
    return ;

}

void stFree(HashTable *ht){

    CelTS *p = NULL, *q = NULL;
    int i;
    for(i =0;i<ht->M;i++){//libera cada lista antes de liberar o tab 
        p = ht->tab[i];
        while(p != NULL){
            q = p;
            p = p->prox;
            free(q->chave);
            free(q);
        }
    }

    //Liberou todas as listas apontadas por tab
    free(ht->tab);
    ht->tab = NULL;
    ht->nChaves = 0;

    return;
}


int main(){

    HashTable *ht = stInit(100);

    char opcao;
    char *nome = malloc(10);
    long int nro;

    char str[30];

    scanf(" %[^\r]", str);
    
    sscanf(str,"%c %s %ld",&opcao,nome,&nro);
    while(opcao != '0'){

    if(opcao == 'I')
        stInsert(nome,nro,ht);
    else if(opcao == 'R')
        stDelete(nome,ht);

    else if(opcao == 'P'){
        Valor v;
        
        if(stSearch(nome,ht,&v))
            printf("Contatinho encontrado: telefone %ld\n",v);
        
        else
            printf("Contatinho nao encontrado\n");
    }
    else if(opcao == 'A'){
        stEdit(nome,nro,ht);
    }

    else ;

    
    scanf(" %[^\r]", str);
    sscanf(str,"%c %s %ld",&opcao,nome,&nro);

    
    }


    return 0;
}