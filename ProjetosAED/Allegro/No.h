//No.h
#ifndef NOH_H
#define NOH_H

#include "Fruta.h"

struct Noh
{
    fruta *f;
    struct Noh *proximo;
};

typedef Noh No;

No *criaNo(fruta *fruta);
No *LiberaNo(No *X);

#endif
