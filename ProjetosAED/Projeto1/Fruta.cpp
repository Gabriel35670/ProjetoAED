#include "Fruta.h"


fruta* criaFruta(string n){

    fruta *novaFruta = new fruta;

    novaFruta->nome = n;

    return novaFruta;
}


bool igual(fruta *f1,fruta *f2){

    if(f1->nome == f2->nome)
        return true;
    return false;
}

