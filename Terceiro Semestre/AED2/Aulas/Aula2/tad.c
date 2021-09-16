#include "tad.h"

Arvore TSbusca(Arvore r,Chave chave){

    if(r == NULL)
        return r;
    
    if(r->chave == chave)
        return r;
    if(r->chave < chave)
        return TSbusca(r->dir,chave);
    return TSbusca(r->esq,chave);
}

Noh* novoNoh(Chave chave,Cont conteudo){

    Noh *novoNo = (Noh*)malloc(sizeof(Noh));
    novoNo->chave = chave;
    novoNo->conteudo = conteudo;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->pai = NULL;

    return novoNo;
}

TS* TSmax(Arvore r){

    if(r->dir == NULL)
        return r;
    else
        return TSmax(r->dir);
}

Arvore insereR(Arvore r,Noh* novo){

    if(r == NULL)
        return novo;
    if(novo->chave > r->chave){
        r->dir = insereR(r->dir, novo);
    }
    else{
        r->esq = insereR(r->esq,novo);
    }

    return r;
}

TS* TSinserir(TS *tab,Chave chave,Cont conteudo){

    Noh *novo = novoNoh(chave,conteudo);
    return insereR(tab,novo);
}

Arvore removeNOH(Arvore alvo){

    Arvore aux,p;

    //Caso 1
    if(alvo->esq == NULL && alvo->dir == NULL){
        free(alvo);
        return NULL;
    }

    //Caso 2
    if(alvo->esq == NULL || alvo->dir == NULL){

        if(alvo->esq == NULL)
            aux = alvo->dir;
        
        else
            aux = alvo->esq;
        
        aux->pai = alvo->pai;
        free(alvo);
        return aux;
    }

    //Caso 3
    aux = TSmax(alvo->esq);
    alvo->chave = aux->chave;
    alvo->conteudo = aux->conteudo;
    p = aux->pai;

    if(p == alvo){
        p->esq = removeNOH(aux);
    }
    else
        p->dir = removeNOH(aux);

    return alvo;
}


TS* TSremove(TS* tab, Chave chave){

    Arvore aux,p,alvo;
    alvo = TSbusca(tab,chave); 

    if(alvo == NULL) return tab;    

    p = alvo->pai;
    aux = removeNOH(alvo); 

    if(p == NULL){
        tab = aux;
        return tab;
    }   
  
    if(p->esq == alvo)
        p->esq = aux;

    if(p->dir == alvo)
        p->dir = aux;

    return tab;
}

void em_ordem(Arvore r){

    if(r != NULL){

        em_ordem(r->esq);
        printf("[%d,%d]\n",r->chave,r->conteudo);
        em_ordem(r->dir);

    }
}

int tamanhoArvore(Arvore r){

   if(r == NULL) return 0;

   return tamanhoArvore(r->esq) + tamanhoArvore(r->dir)+1; 
}

int alturaAR(Arvore r){

    if(r== NULL) return -1;

    int hesq,hdir;

    hesq = alturaAR(r->esq);
    hdir = alturaAR(r->dir);

    if(hesq > hdir)
        return hesq+1;
    return hdir +1;
}

void preenchePAI(Arvore r){

    if(r==NULL)
        return;
    if(r->esq != NULL){
        preenchePAI(r->esq);
        r->esq->pai = r;
    }
    if(r->dir != NULL){
        preenchePAI(r->dir);
        r->dir->pai = r;
    }

    return;

}

void verifica(Arvore r,bool *eh){


    if(r == NULL) return;

    if(r->esq->chave <= r->chave && r->dir->chave > r->chave){
        verifica(r->esq,eh);
        verifica(r->dir,eh);
    }
    else
        eh = false;

    return;
}

Noh* TSmin(Arvore r){

    if(r->esq == NULL) return r;

    return TSmin(r->esq);
}

int* vetorMax(Arvore r){

    int tamanho = tamanhoArvore(r);
    int *v = (int*)malloc(sizeof(int)*tamanho);

    int i=0;
    while(r != NULL){
        v[i] = TSmin(r)->chave;
        i++;    
        r = TSremove(r,TSmin(r)->chave);
    }

    //free(r);
    return v;
}

void imprimeVETOR(int v[],int n){

    for(int i=0;i<n;i++){

        if(i != n-1)
            printf("[%d] ",v[i]);
        else
            printf("[%d]\n",v[i]);

    }
}
