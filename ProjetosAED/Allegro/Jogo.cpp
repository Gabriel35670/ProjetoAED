#include "Jogo.h"

//Jogo.cpp

Jogo::Jogo(int tempoSeq, int tempoGam, int qtdFrutas, string difi)
{
	setQtdFrutas(qtdFrutas);
	setTempoSeq(tempoSeq);
	setTempoGam(tempoGam);
	setDificuldade(difi);
}

Jogo::~Jogo() {}

void Jogo::setTempoSeq(int tempoSeq)
{
	if (tempoSeq <= 0)
	{
		cout << "Tempo inválido" << endl;
	}
	else
	{
		tempoSequencia = tempoSeq;
	}
}

void Jogo::setTempoGam(int tempoGam)
{
	if (tempoGam <= 0)
	{
		cout << "Tempo inválido" << endl;
	}
	else
	{
		tempoGameplay = tempoGam;
	}
}

void Jogo::setQtdFrutas(int frutas)
{
	if (frutas <= 0)
	{
		cout << "Quantidade de frutas inválida" << endl;
	}
	else if (frutas > 10)
	{
		cout << "Quantidade máxima de frutas atingida" << endl;
	}
	else
	{
		qtdFrutas = frutas;
	}
}

void Jogo::setDificuldade(string difi)
{
	if (difi == "Facil" || difi == "Medio" || difi == "Dificil")
	{
		dificuldade = difi;
	}
	else
	{
		cout << "Dificuldade inválida";
	}
}

int Jogo::getTempoGam() const
{
	return tempoGameplay;
}

int Jogo::getTempoSeq() const
{
	return tempoSequencia;
}

int Jogo::getQtdFrutas() const
{
	return qtdFrutas;
}

string Jogo::getDificuldade() const
{
	return dificuldade;
}

void Jogo::embaralha(PILHA *P)
{
	vector<fruta *> frutas;

	frutas = vet_frutas(qtdFrutas);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gera uma "seed" aleatoria

	shuffle(frutas.begin(), frutas.end(), default_random_engine(seed));

	int tam = frutas.size();
	for (int i = 0; i < tam; i++)
	{
		No *N;
		N = new No;
		N->f = frutas[i];
		Empilhar(P, N);
	}
}
