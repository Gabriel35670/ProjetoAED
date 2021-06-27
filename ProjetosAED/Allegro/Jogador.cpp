#include "Jogador.h"

//Jogador.cpp

int Jogador::contador = 0;

Jogador::Jogador(string nome, int t)
{

	setNome(nome);
	this->P = CriarPilha(t);
	pontuacao = 0;
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

string Jogador::getNome() const
{
	return nome;
}

void Jogador::controlaCont(int x)
{
	this->contador -= x;
}

bool Jogador::JogadorEmpilha(No *n)
{

	if (Empilhar(this->P, n))
		return true;
	return false;
}

PILHA *Jogador::getPilha()
{
	return this->P;
}

void Jogador::LPilha()
{

	this->P = LiberarPilha(this->P);
}