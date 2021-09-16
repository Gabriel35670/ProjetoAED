#include <stdio.h>
#include <stdlib.h>

/*
AULA 3 - ROTAÇÕES E ÁRVORES AVL - DEFINIÇÃO E INSERÇÃO
ROTAÇÃO - inverte a relação pai/filho e suas subàrvores, com corretude (respeitando a propriedade de busca);

Analisando o impacto de uma rotação na altura de uma subárvore:
-Operações de rotação façam alguma coisa em relação ao balanceamento da árvore;

H_antes = max{2+hA, 2+hB, 1+hC} -> O maior dos termos determina a altura da rotação (ver pdf)

Depois de uma rotação à direita:

H_depois = max{1+hA, 2+hB, 1+hC} -> Ver esquema do pdf

ROTAÇÃO DUPLA: ROTAÇÃO À DIREITA, SEGUIDA DE ROTAÇÃO À ESQUERDA



AVL: ADELSON-VELSKY AND LANDIS

DEFINIÇÕES:
*O FATOR DE BALANCEAMENTO DE UM NÓ É A DIFERENÇA ENTRE A ALTURA DE SUA SUBÁRVORE DIREITA E A ALTURA DE SUA SUBÁRVORE ESQUERDA;
*UMA ÁRVORE É DITA AVL SE TODOS OS SEUS NÓS TEM UM FATOR DE BALANCEAMENTO ENTRE -1 E +1;
*INTUITIVAMENTE, ESSA PROPRIEDADE GARANTE QUE UMA ÁRVORE AVL É POUCO DESBALANCEADA;

COMO CALCULAR BAL:
*CALCULAR DE BAIXO PRA CIMA;
SUBARVOREESQ-SUBARVOREDIR;
FATOR DE BALANCEAMENTO + 1: ALTURA DA SUBARVORE DIREITA É MAIOR QUE DA SUBARVORE ESQUERDA;
FATOR DE BALANCEAMENTO - 1: ALTURA DA SUBARVORE ESQUERDA É MENOR QUE DA SUBARVORE DIREITA;
FATOR DE BALANCEAMENTO 0  : ARVORE BALANCEADA (OS DOIS NÓS TEM A MESMA ALTURA);

BALANCEAMENTO PODE MUDAR QUANDO OCORRE INSERÇÃO OU REMOÇÃO;
*/

//LEMBRANDO QUE A ALTURA DE UMA SUBARVORE VAZIA É -1;


typedef int Cont;
typedef int Chave;

typedef struct noh{
    int bal;
    Chave chave;
    Cont conteudo;
    struct noh *pai;
    struct noh *esq;
    struct noh *dir;
} Noh;

typedef Noh *Arvore;



Noh *novoNoh(Chave chave, Cont conteudo);
Arvore rotacaoDir(Arvore r);
Arvore rotacaoEsq(Arvore r);
Arvore insereAVL(Noh *r, Noh *novo, int *aumentou_altura);
Arvore inserir(Arvore r, Chave chave, Cont conteudo);
Arvore AVLmax(Arvore r);
Arvore AVLmin(Arvore r);

Arvore balanceamento_esquerdo(Arvore r, int *diminuiu_altura);
Arvore balanceamento_direito(Arvore r, int *diminuiu_altura);
Arvore busca_remove(Arvore r, Arvore noh_chave, int *diminuiu_altura);
Arvore removeAVL(Arvore r, Chave chave, int *diminuiu_altura);
Arvore remover(Arvore r, Chave chave);

void exibeElementos(Arvore r);



Noh *novoNoh(Chave chave, Cont conteudo){
    Noh *novo;
    novo = (Noh *)malloc(sizeof(Noh));
    novo->bal = 0;
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

Arvore rotacaoDir(Arvore r){
    Noh *aux;
    aux = r->esq;
    r->esq = aux->dir;
    if (aux->dir != NULL) aux->dir->pai = r;
    aux->dir = r;
    r->pai = aux;
    return aux;
}

Arvore rotacaoEsq(Arvore r){
    Noh *aux;
    aux = r->dir;
    r->dir = aux->esq;
    if (aux->esq != NULL) aux->esq->pai = r;
    aux->esq = r;
    r->pai = aux;
    return aux;
}

//INSERINDO O NOVO NÓ COMO UMA FOLHA, COMO OCORRE NAS ÁRVORES DE BUSCA COMUNS;

Arvore insereAVL(Noh *r, Noh *novo, int *aumentou_altura){
    if (r == NULL){ //Caso 1: subárvore era vazia
        novo->pai = NULL; //Irrelevante (não precisava)
        *aumentou_altura = 1;
        return novo;
    }
    if (novo->chave <= r->chave){ //desce à esquerda
        r->esq = insereAVL(r->esq, novo, aumentou_altura);
        r->esq->pai = r;
        if (*aumentou_altura == 1){ //altura da subárvore esquerda aumentou após a inserção
            if (r->bal == +1){ //Caso 2: inseriu do lado mais baixo (ARVORE FICA BALANCEADA)
                r->bal = 0;
                *aumentou_altura = 0;
            }
            else if (r->bal == 0){ //Caso 3 dois lados tinham a mesma altura
                r->bal = -1;
                *aumentou_altura = 1;
            }
            else if (r->bal == -1){ // Caso 4: inseriu do lado mais alto
                if (r->esq->bal == -1){ //Caso 4.1: inseriu à esquerda do filho direito
                    r = rotacaoDir(r); //Rotacao a direita entre o x e o filho esquerdo, faz descer o C e subir o A;
                    r->dir->bal = 0;
                }
                else{ //Caso 4.2: inseriu à direita do filho esquerdo
                    r->esq = rotacaoEsq(r->esq);
                    r = rotacaoDir(r);
                    if (r->bal == 0){ // z foi o nó inserido
                        r->esq->bal = 0;
                        r->dir->bal = 0;
                    }
                    else if (r->bal == -1){ //inserção à esquerda de z
                        r->esq->bal = 0;
                        r->dir->bal = +1;
                    }
                    else{ //r->bal == +1 (inserção a direita de z)
                        r->esq->bal = -1;
                        r->dir->bal = 0;
                    }
                }
                r->bal = 0;
                *aumentou_altura = 0;
            }
        }
    }
    else{
        r->dir = insereAVL(r->dir, novo, aumentou_altura);
        r->dir->pai = r;
        if (*aumentou_altura == 1){ //altura da subárvore direita aumentou após a inserção
            if (r->bal == -1){ //Caso 2: inseriu do lado mais baixo (filho direito da subarvore direita)(ARVORE FICA BALANCEADA)  //OK
                r->bal = 0;
                *aumentou_altura = 0;
            }
            else if (r->bal == 0){ //Caso 3 dois lados tinham a mesma altura //Ok
                r->bal = 1; //inseri do lado direito, fat bal = 1;
                *aumentou_altura = 1;
            }
            //alterar daqui pra baixo
            else if (r->bal == 1){ // Caso 4: inseriu do lado mais alto
                if (r->dir->bal == 1){ //Caso 4.1: inseriu à direita do filho direito
                    r = rotacaoEsq(r);
                    r->esq->bal = 0;
                }
                else{ //Caso 4.2: inseriu à esquerda do filho direito
                    r->dir = rotacaoDir(r->dir);
                    r = rotacaoEsq(r);
                    if (r->bal == 0){
                        r->esq->bal = 0;
                        r->dir->bal = 0;
                    }
                    else if (r->bal == -1){
                        r->esq->bal = 0;
                        r->dir->bal = +1;
                    }
                    else{ //r->bal == 1;
                        r->esq->bal = -1;
                        r->dir->bal = 0;
                    }
                }
                r->bal = 0;
                *aumentou_altura = 0;
            }
        }
    }
    return r;
}

Arvore inserir(Arvore r, Chave chave, Cont conteudo){
    int aumentou_altura;
    Noh *novo = novoNoh(chave, conteudo);
    return insereAVL(r, novo, &aumentou_altura);
}

Arvore AVLmax(Arvore r){
    if(r->dir == NULL) return r;
    return AVLmax(r);
}

Arvore AVLmin(Arvore r){
    if (r == NULL) return r;
    return AVLmin(r->esq);
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

void exibeElementos(Arvore r){
    if (r != NULL){
        exibeElementos(r->dir);
        printf("%d ->", r->chave);
        exibeElementos(r->esq);
    }
}

int main(int argc, char const *argv[]){
    Arvore r = NULL;
    printf("Inserindo elementos:\n");
    for (int i = 0; i < 10; i++){
        r = inserir(r, i, i);
    }
    exibeElementos(r);
    printf("\n");
    printf("Removendo...\n");
    r = remover(r, 1);
    exibeElementos(r);
    return 0;
}

