//Pilha.cpp
#include "Pilha.h"

PILHA *CriarPilha(int tamanhoMAX)
{

	PILHA *P = new PILHA;
	P->tamanhoMAX = tamanhoMAX;
	P->topo = NULL;

	return P;
}
bool Cheia(PILHA *P)
{

	int contador = 0;
	No *aux = P->topo;
	while (aux != NULL)
	{
		aux = aux->proximo;
		contador++;
	}

	return contador == P->tamanhoMAX;
}

bool Vazia(PILHA *P)
{

	return P->topo == NULL;
}

bool Empilhar(PILHA *P, No *novo)
{

	if (Cheia(P) || novo == NULL)
	{
		return false;
	}
	else
	{
		if (Vazia(P))
		{
			novo->proximo = NULL;
			P->topo = novo;
		}
		else
		{
			No *aux;
			aux = P->topo;
			P->topo = novo;
			P->topo->proximo = aux;
		}
	}
	return true;
}

bool Desempilhar(PILHA *P, No *X, bool acabou)
{

	if (Vazia(P))
	{
		return false;
	}
	if (acabou && P->topo == X)
	{
		No *lixo;

		X->f = P->topo->f;
		lixo = P->topo;
		P->topo = P->topo->proximo;
		lixo = LiberaNo(lixo);

		return true;
	}
	else
	{
		if (P->topo == X)
		{
			X->f = P->topo->f;
			P->topo = P->topo->proximo;
			return true;
		}
	}

	return false;
}

int ComparaPilhas(PILHA *P1, PILHA *P2)
{

	int igualdades = 0;

	No *N1 = P1->topo;
	No *N2 = P2->topo;

	while (N1 != NULL && N2 != NULL)
	{

		if (igual(N1->f, N2->f))
		{

			igualdades++;
		}
		N1 = N1->proximo;
		N2 = N2->proximo;
	}

	return igualdades;
}
void imprimePILHA(PILHA *P, BITMAP *buffer, int width, int height, int tamanhoP, FONT *verdana)
{

	No *aux;
	int tamanhoOcup = tamanhoP * 80;
	double contador = 0;

	aux = P->topo;
	while (aux != NULL)
	{
		draw_sprite(buffer, aux->f->img, (799 - tamanhoOcup) + ((contador) * (80)), height);
		contador += 1;
		aux = aux->proximo;
	}
}
PILHA *LiberarPilha(PILHA *P)
{

	if (!Vazia(P))
	{
		No *proxNode,
			*atual;

		atual = P->topo;
		while (atual != NULL)
		{
			proxNode = atual->proximo;
			delete atual;
			atual = proxNode;
		}
		P->topo = NULL;
	}

	return P;
}
