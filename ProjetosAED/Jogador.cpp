#include "Jogador.h"

int Jogador::contador = 0;

Jogador::Jogador(string nome)
{

    setNome(nome);
}

Jogador::~Jogador() {}

void Jogador::setNome(string n)
{

    if (n != "\0")
        nome = n;
    else
    {
        string v[4] = {"Jogador1", "Jogador2", "Jogador3", "Jogador4"};

        nome = v[contador];
    }

    contador++;
}

void Jogador::aumentaPontuacao()
{
    pontuacao++;
}

int Jogador::getPontos() const
{
    return pontuacao;
}