#include <iostream>
#include <cstdlib>
#include "Objeto.h"


using namespace std;


struct Noh
{
    Objeto obj;
    Noh *proximo;
};

typedef Noh No;

No* criaNo(Objeto o);
No* LiberaNo(No *X);