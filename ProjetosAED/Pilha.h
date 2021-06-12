#include "No.h"

struct Pilha
{
    int tamanhoMAX;
    No *topo;
};

typedef Pilha PILHA;

PILHA* CriarPilha(int tamanhoMAX);
PILHA* LiberarPilha(PILHA *P);

bool Empilhar(PILHA *P,No *X);
bool Desempilhar(PILHA *P,No *X);

bool Vazia(PILHA *P);
bool Cheia(PILHA *P);

int ComparaPilhas(PILHA *P1, PILHA *P2);
void imprimePILHA(PILHA *P);

