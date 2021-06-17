#ifndef NO_H
#define NO_H


#include <iostream>
#include <cstdlib>
#include "Fruta.h"


using namespace std;


struct Noh
{
    Fruta *f;
    struct Noh *proximo;
};

typedef Noh No;

No* criaNo(Fruta *fruta);
No* LiberaNo(No *X);

#endif