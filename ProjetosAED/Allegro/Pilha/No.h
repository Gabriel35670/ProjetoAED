#ifndef NOH_H
#define NOH_H


#include <iostream>
#include <cstdlib>
#include <allegro.h>
#include "Fruta.h"


using namespace std;


struct Noh
{
    fruta *f;
    struct Noh *proximo;
};

typedef Noh No;

No* criaNo(fruta *fruta);
No* LiberaNo(No *X);

#endif