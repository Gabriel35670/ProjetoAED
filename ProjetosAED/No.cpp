#include "No.h"

No* criaNo(Fruta *fruta){

    No *N;
    N = new No;

    N->proximo = NULL;
    N->f = fruta;
    
    return N;
}

No* LiberaNo(No *X){

    delete X;

    return X;
}
