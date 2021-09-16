#include "avl.h"

/*

gcc -g ....
gdb ...
layout next
b main
start
...

s pra entrar facil


*/

Arvore rotacaoDir(Arvore r){

    Noh *aux;

    aux = r->esq;
    r->esq = aux->dir;

    if(aux->dir != NULL)
        aux->dir->pai = r;

    aux->dir = r;
    r->pai = aux;
 //   aux->pai = NULL;

    return aux;
}

Arvore rotacaoEsq(Arvore r){

    Noh *aux;

    aux = r->dir;
    r->dir = aux->esq;

    if(aux->esq != NULL)
        aux->esq->pai = r;

    aux->esq = r;
    r->pai = aux;

   // aux->pai = NULL;

    return aux;
}

Noh *novoNOH(Chave chave,Cont conteudo){

    Noh *novo;
    novo = (Noh*)malloc(sizeof(Noh));

    novo->bal = 0;
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;

}

Arvore insereAVL(Noh *r,Noh *novo,int *aumentou_altura){

    if(r == NULL){ //Caso 1: Subarvore está vazia, novo equivale a nova raiz

        *aumentou_altura = 1;
        return novo;
    }

    //Desce a esquerda
    if(novo->chave <= r->chave){

        r->esq = insereAVL(r->esq,novo,aumentou_altura);
        r->esq->pai = r;

        if(*aumentou_altura == 1){
            //Altura da subarvore esquerda aumentou apos a inserção

            if(r->bal == 1){//Caso 2: inseriu do lado mais baixo

                r->bal = 0;
                *aumentou_altura = 0;
            }

            else if(r->bal == 0){//Caso 3: Os dois lados tinha a mesma altura

                r->bal = -1;
                *aumentou_altura = 1;
            }

            else if(r->bal == -1){//Inseriu do lado mais alto da subarvore
            
                if(r->esq->bal == -1){ //Inseriu a esquerda do filho esquerdo

                    printf("opa");
                    r = rotacaoDir(r);
                    r->dir->bal = 0;
                }
                else{//r->esq->bal == 1, inseriu a direita do filho esquerdo

                    r->esq = rotacaoEsq(r->esq);
                    r = rotacaoDir(r);

                    if(r->bal == 0){
                        r->esq->bal = 0;
                        r->dir->bal = 0;
                    }

                    else if(r->bal == -1){
                        r->esq->bal = 0;
                        r->dir->bal = 1;
                    }

                    else{//r->bal == 1
                    
                        r->esq->bal = -1;
                        r->dir->bal = 0;
                    }
                
                }

                r->bal = 0;
                *aumentou_altura = 0;
            }
        }
    }
    //Desce a direita
    else{
        r->dir = insereAVL(r->dir,novo,aumentou_altura);
        r->dir->pai = r;

        if(*aumentou_altura == 1){//altura da subarvore direita, aumentou apos inserção

            if(r->bal == -1){//Caso 2: inseriu no lado mais baixo
                r->bal = 0;
                *aumentou_altura = 0;
            }

            else if(r->bal == 0){//Caso 3: dois lados tinham a mesma altura
            
                r->bal = 1;
                *aumentou_altura = 1;
            }

            else if(r->bal == 1){//Caso 4:inseriu no lado mais alto
            
                if(r->dir->bal == -1){//inseriu a esquerda do filho direito

                    //Rotação direita esquerda
                    r->dir = rotacaoDir(r->dir);
                    r = rotacaoEsq(r);


                    if(r->bal == 0){
                        r->esq->bal = 0;
                        r->dir->bal = 0;
                    }

                    else if(r->bal == -1){

                        r->esq->bal = 1;
                        r->dir->bal = 0;
                    }

                    else{//r->bal == 1
                    
                    
                        r->esq->bal = 0;
                        r->dir->bal = -1;
                    }

                }

                else{//r->dir->bal == 1, inseriu a direita do filho direito
                
                     //Rotação a esquerda
                    r = rotacaoEsq(r);
                   
                   r->esq->bal = 0;

                }

                r->bal = 0;
                *aumentou_altura = 0;
            }
        }
    }

    return r;
//FIM DA FUNÇÃO    
}

Arvore inserir(Arvore r,Chave chave,Cont conteudo){

    int aumentou_altura;
    Noh *novo = novoNOH(chave,conteudo);
    return insereAVL(r,novo,&aumentou_altura);

}

void em_ordem(Arvore r){

    if(r != NULL){

        em_ordem(r->esq);
        printf("{%d,%d}\n",r->chave,r->conteudo);
        em_ordem(r->dir);
    }

    return;
}

void pre_ordem(Arvore r){

    if(r != NULL){

        printf("{%d,%d}\n",r->chave,r->conteudo);
        pre_ordem(r->esq);
        pre_ordem(r->dir);
    }

    return;
}


void pos_ordem(Arvore r){

    if(r != NULL){

        pos_ordem(r->esq);
        pos_ordem(r->dir);
        printf("{%d,%d}\n",r->chave,r->conteudo);

    }

    return;
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

int verifica(Arvore r){

    int hesq = alturaAR(r->esq);
    int hdir = alturaAR(r->dir);

    if(abs(hesq-hdir) <= 1)
        return TRUE;
    return FALSE;
}



Arvore balanceamento_esquerdo(Arvore r, int *diminuiu_altura){
    if (r->bal == -1){ //estou removendo do lado esquerdo, isso implica  que o meu fator de balanceamento fica 0
        r->bal = 0;
        r->esq->bal = 0;
    }
    else if (r->bal == 0){
        r->bal = 1;
        *diminuiu_altura = 0;
    }
    else{ //altura foi altera e desbalanceou
    //em qual caso estou? (vou fazer rotação simples ou dupla?)
        if (r->dir->bal >= 0){
            r = rotacaoEsq(r);
            if (r->bal == 0){
                r->esq->bal = 1;
                r->bal = -1;
                *diminuiu_altura = 0;
            }
            else{ //r->bal == 1;
                r->esq->bal = 0;
                r->bal = 0;
            }
        }
        else{
            r->dir = rotacaoDir(r);
            r = rotacaoEsq(r);
            if (r->bal == -1){
                r->esq->bal = 0;
                r->dir->bal = 1; 
            }
            else if (r->bal == 1){
                r->esq->bal = -1;
                r->dir->bal = 0;
            }
            else{
                r->esq->bal = 0;
                r->dir->bal = 0;
            }
            r->bal = 0;
        }
    }
    return r;
}


Arvore balanceamento_direito(Arvore r, int *diminuiu_altura){
    if (r->bal == 1){ //estou removendo do lado direito, isso implica  que o meu fator de balanceamento fica 0
        r->bal = 0;
        r->esq->bal = 0;
    }
    else if (r->bal == 0){
        r->bal = -1;
        *diminuiu_altura = 0;
    }
    else{ //altura foi altera e desbalanceou
    //em qual caso estou? (vou fazer rotação simples ou dupla?)
        if (r->esq->bal <= 0){
            r = rotacaoDir(r);
            if (r->bal == 0){
                r->dir->bal = -1;
                r->bal = 1;
                *diminuiu_altura = 0;
            }
            else{ //r->bal == -1;
                r->dir->bal = 0;
                r->bal = 0;
            }
        }
        //CASOS ROTAÇÃO DUPLA
        else{
            r->esq = rotacaoEsq(r);
            r = rotacaoDir(r);
            if (r->bal == -1){
                r->esq->bal = 0;
                r->dir->bal = 1; 
            }
            else if (r->bal == 1){
                r->esq->bal = 0;
                r->dir->bal = 1;;
            }
            else{
                r->esq->bal = 0;
                r->dir->bal = 0;
            }
            r->bal = 0;
        }
    }
    return r;
}

Arvore busca_remove(Arvore r, Arvore noh_chave, int *diminuiu_altura){
    Noh *aux;
    if (r->dir != NULL){
        r->dir = busca_remove(r, noh_chave, diminuiu_altura);
        if (*diminuiu_altura == 1){
            r = balanceamento_direito(r, diminuiu_altura);
        }
    }
    else{
        noh_chave->chave = r->chave;
        aux = r;
        r = r->esq;
        free(aux);
        *diminuiu_altura = 1;
    }
    return r;
}

Arvore removeAVL(Arvore r, Chave chave, int *diminuiu_altura){
    Noh *aux = NULL;
    if (r == NULL){ //Ou a arvore ta vazia, ou em uma das recursões a gente chega em um ponteiro nulo->chave não encontrada;
        *diminuiu_altura = 0;
    }
    else if(chave < r->chave){ //se a raiz for diferente de nulo e a chave que eu to buscando eh menor do que a chave do nó corrente, olhamos para a esquerda
        r->esq = removeAVL(r->esq, chave, diminuiu_altura);
        if (*diminuiu_altura == 1){
            r = balanceamento_esquerdo(r, diminuiu_altura);
        }
    }
    else if(chave > r->chave){
        r->dir = removeAVL(r->dir, chave, diminuiu_altura);
        if (*diminuiu_altura == 1){
            r = balanceamento_direito(r, diminuiu_altura);
        }
    }
    else{ //encontrei a chave que to procurando
        if (r->dir == NULL){ //ou eh uma folha, ou eh um nóh que tem apenas um filho(filho esquerdo)
            aux = r;
            r = r->esq;
            free(aux);
            *diminuiu_altura = 1;
        }
        else if (r->esq == NULL){ //ou eh uma folha, ou eh um nóh que tem apenas um filho (filho direito)
            aux = r;
            r = r->dir;
            free(aux);
            *diminuiu_altura = 1;
        }
        //tem dois filhos
        else{
            r->esq = busca_remove(r->esq, r, diminuiu_altura);
            if (*diminuiu_altura == 1){
                r = balanceamento_esquerdo(r, diminuiu_altura);
            }
        }
    }
    return r;
}

Arvore remover(Arvore r, Chave chave){
    int dimininui_altura = 0;
    Noh *removido = removeAVL(r, chave, &dimininui_altura);
    return removido;
}

