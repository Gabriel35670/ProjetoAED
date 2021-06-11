#include "No.h"

No* criaNo(int valor){

    No *N = new No;

    N->proximo = NULL;
    N->valor = valor;

    //cout<<"No com valor {"<<N->valor<<"} criado.\n";
    
    return N;
}

No* LiberaNo(No *X){

    delete X;

    return X;
}
