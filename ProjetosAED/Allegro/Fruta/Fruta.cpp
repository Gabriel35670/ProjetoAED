#include "Fruta.h"

string getFileName(string n){

    //File names
    string v[10] = {"BITMAPS/F/abacaxi.bmp","BITMAPS/F/banana.bmp","BITMAPS/F/maca.bmp","BITMAPS/F/laranja.bmp","BITMAPS/F/caju.bmp",
    "BITMAPS/F/framboesa.bmp","BITMAPS/F/abacate.bmp","BITMAPS/F/morango.bmp","BITMAPS/F/uva.bmp","BITMAPS/F/melancia.bmp"};

    string v2[10] = {"abacaxi","banana","maca","laranja","caju","framboesa","abacate","morango","uva","melancia"};

    int pos=0;
    bool achou=false;

    while(pos < 10 && !achou){
        if(n == v2[pos])
            achou = true;
        pos++;
    }

    return v[pos];
}


fruta* criaFruta(string n){

    fruta *novaFruta = new fruta;

    novaFruta->nome = n;
    string file_name = getFileName(n);
    novaFruta->img = load_bitmap(file_name.c_str(),NULL);

    return novaFruta;
}


bool igual(fruta *f1,fruta *f2){

    if(f1->nome == f2->nome)
        return true;
    return false;
}

vector<fruta *> vet_frutas(int x){

    string v[10] = {"abacaxi","banana","maca","laranja","caju","framboesa","abacate","morango","uva","melancia"};
    
    vector<fruta *> frutas;

    fruta* aux;

    for(int i=0;i<x;i++){
     
        aux = criaFruta(v[i]);
        
     
        frutas.push_back(aux);

    }

    return frutas;

} 

