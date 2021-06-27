#include "Fruta.h"

string getFileName(string n)
{

	//File names
	string v[10] = {"Pilha/F/abacaxi.bmp", "Pilha/F/banana.bmp", "Pilha/F/maca.bmp", "Pilha/F/laranja.bmp", "Pilha/F/caju.bmp",
					"Pilha/F/framboesa.bmp", "Pilha/F/abacate.bmp", "Pilha/F/morango.bmp", "Pilha/F/uva.bmp", "Pilha/F/melancia.bmp"};

	string v2[10] = {"abacaxi", "banana", "maca", "laranja", "caju", "framboesa", "abacate", "morango", "uva", "melancia"};

	int pos = 0;
	bool achou = false;

	while (pos < 10 && !achou)
	{
		if (n == v2[pos])
			achou = true;
		pos++;
	}
	pos -= 1;
	return v[pos];
}

fruta *criaFruta(string n)
{

	fruta *novaFruta = new fruta;

	novaFruta->nome = n;
	string file_name = getFileName(n);
	novaFruta->img = load_bitmap(file_name.c_str(), NULL);

	return novaFruta;
}

bool igual(fruta *f1, fruta *f2)
{

	if (f1->nome == f2->nome)
		return true;
	return false;
}

vector<fruta *> vet_frutas(int x)
{

	string v[10] = {"abacaxi", "banana", "maca", "laranja", "caju", "framboesa", "abacate", "morango", "uva", "melancia"};
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gera uma "seed" aleatoria

	vector<string>sorteio;
	for(int j=0;j<10;j++)
		sorteio.push_back(v[j]);

	shuffle(sorteio.begin(),sorteio.end(),default_random_engine(seed));

	vector<fruta *> frutas;

	fruta *aux;

	for (int i = 0; i < x; i++)
	{

		aux = criaFruta(sorteio[i]);

		frutas.push_back(aux);
	}

	return frutas;
}
