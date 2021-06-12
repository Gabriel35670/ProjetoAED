#include "Pilha.h"


PILHA* CriarPilha(int tamanhoMAX){

    PILHA *P = new PILHA;
    P->tamanhoMAX = tamanhoMAX;
    P->topo = NULL;
    
    //cout<<"Pilha de tamanho {"<<P->tamanhoMAX<<"} criado.\n";

    return P;
}
bool Cheia(PILHA *P){

    int contador=0;
    No *aux = P->topo;
    while(aux != NULL){
        aux = aux->proximo;
        contador++;
    }
    
    //cout<<"Atualmente a fila tem: "<<contador<<" valore(s).\n";
    return contador == P->tamanhoMAX;
}

bool Vazia(PILHA *P){

    return P->topo == NULL;
}

bool Empilhar(PILHA *P,No *novo){

    if(Cheia(P) || novo == NULL){
        //cout<<"Pilha cheia/No invalido.\n";
        return false;
    }
    else{
        //cout<<"Pilha nao cheia.\n";

        if(Vazia(P)){
            novo->proximo = NULL;
            P->topo = novo;
        }
        else{
            No *aux;
            aux = P->topo;
            P->topo = novo;
            P->topo->proximo = aux;
        }
    }
    return true;
}

bool Desempilhar(PILHA *P,No *X){

    if(Vazia(P)){
        //cout<<"Fila vazia, impossível retirar.\n";
        return false;
    }
    No *lixo;
    
    lixo = P->topo;
    X->f = P->topo->f;
    P->topo = P->topo->proximo;
    
    /*if(P->topo != NULL)
        cout<<"Valor do novo topo eh: {"<<P->topo->valor<<"}.\n";
    */
    lixo = LiberaNo(lixo);

    return true;
}

int ComparaPilhas(PILHA *P1, PILHA *P2){

    int igualdades=0;

    No *N1 = P1->topo;
    No *N2 = P2->topo;

    while(N1 != NULL && N2 != NULL){

        if(igual(N1->f,N2->f)){
            
            //cout<<"O valor de N1= "<<N1->valor<<" eh igual ao valor de N2= "<<N2->valor<<".\n";
            igualdades++;
        }
        N1 = N1->proximo;
        N2 = N2->proximo;
    }

    return igualdades;
}

void imprimePILHA(PILHA *P){

    No *aux;
    aux = P->topo;

    int contador=0;

    while(aux != NULL){
        cout<<"P["<<contador<<"] = "<<aux->f->nome<<"\n";
        contador ++;
        aux = aux->proximo;
    }

}

PILHA* LiberarPilha(PILHA *P){

    No *aux;
    fruta *f;
    f = criaFruta("MELAO");
    aux = criaNo(f);
    while(!Vazia(P)){
        Desempilhar(P,aux);
    }

    return P;
}
