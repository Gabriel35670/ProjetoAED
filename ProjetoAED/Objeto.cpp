#include "Objeto.h"



Objeto::Objeto(string nome){

    setNome(nome);

}

Objeto::~Objeto(){}

string Objeto::getNome() const{

    return nome;
}

void Objeto::setNome(string n){

    string vetor[20] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T"};
    int contador=0;
    while(contador < 20 && contador == 0){
        if(nome == vetor[contador])
            nome = n;
        
        contador++;
    }
}

bool Objeto::operator==(const Objeto &o) const{

        if(this->nome == o.nome)
            return true;
        return false;

}