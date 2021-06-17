#include "Jogador.h"

int Jogador::contador = 0;

Jogador::Jogador(string nome)
{

    setNome(nome);
    pontuacao =0;
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

string Jogador::getNome() const{
    return nome;
}

void Jogador::controlaCont(int x){
    this->contador -= x;
}

