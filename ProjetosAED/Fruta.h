#include <iostream>
#include <string>

using namespace std;

struct Fruta{

    string nome;
};

typedef Fruta fruta;


fruta* criaFruta(string n);

bool igual(fruta *f1,fruta *f2);