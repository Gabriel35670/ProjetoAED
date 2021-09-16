#include "rubro_negras.h"


//Novo noh

Noh *novoNoh(Chave chave,Item conteudo){

    Noh *novo;

    novo = (Noh*)malloc(sizeof(Noh));
    novo->vermelho = TRUE;
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Arvore rotacaoDir(Arvore r){

    Noh *aux;

    aux = r->esq;
    r->esq = aux->dir;

    if(aux->dir != NULL)
        aux->dir->pai = r;

    aux->dir = r;
    r->pai = aux;

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

    return aux;
}

//Insere na arvore binaria de fato
Arvore insereRN(Noh *r,Noh *novo){

    if(r == NULL){//subarvore era vazia
    
        novo->pai = NULL;

        return novo;
    }

    if(novo->chave <= r->chave){//desce a esquerda
    
        r->esq = insereRN(r->esq,novo);
        r->esq->pai = r;
    }

    else{//desce a direita
    
        r->dir = insereRN(r->dir,novo);
        r->dir->pai = r;
    }


    //Tratamento de casos

    //Se filho direito é vermelho e filho esquerdo não é vermelho, quebra a propriedade das ARB esquerdistas, em que os filhos vermelhos sao esquerdos
    if(r->dir != NULL && r->dir->vermelho == TRUE && (r->esq == NULL || r->esq->vermelho == FALSE)){

        r = rotacaoEsq(r);

        //Recoloração
        r->vermelho = r->esq->vermelho; //recebe a cor do A, que teoricamente já estava correto
        r->esq->vermelho = TRUE;
    }

    //Se filho esquerdo é vermelho e filho esquerdo do filho esquerdo é vermelho
    if(r->esq != NULL && r->esq->vermelho == TRUE && r->esq->esq != NULL && r->esq->esq->vermelho == TRUE){

        //Para corrigir isso, deve-se fazer uma rotação a direita entre B e A e recoloria B e A
        r = rotacaoDir(r);
        r->vermelho = FALSE;
        r->dir->vermelho = TRUE;
    }

    //Se filho esquerdo é vermelho e filho direito é vermelho
    if(r->esq != NULL && r->esq->vermelho == TRUE && r->dir != NULL && r->dir->vermelho == TRUE){
        
        //Para isso, troque a cor do pai desse filhos com a cor dos filhos
        r->vermelho = TRUE;

        r->esq->vermelho = FALSE;
        r->dir->vermelho = FALSE;
    }

    return r;

}

//Cria o novo no, e chama a insereRN
Arvore inserir(Arvore r,Chave chave,Item conteudo){

    Noh *novo = novoNoh(chave,conteudo);

    return insereRN(r,novo);
}