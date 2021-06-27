//Fruta.h
#ifndef FRUTA_H
#define FRUTA_H

#include <iostream>
#include <string>
#include <cstdlib>

#include <allegro.h>

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

struct Fruta
{

    string nome;
    BITMAP *img;
};

typedef Fruta fruta;

fruta *criaFruta(string n);

string getFileName(string n);

bool igual(fruta *f1, fruta *f2);

vector<fruta *> vet_frutas(int x);

#endif