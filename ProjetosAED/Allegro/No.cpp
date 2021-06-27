#include "No.h"


//No.cpp
No *criaNo(fruta *fruta)
{

	No *N;
	N = new No;

	N->proximo = NULL;
	N->f = fruta;

	return N;
}

No *LiberaNo(No *X)
{

	delete X;

	return X;
}
