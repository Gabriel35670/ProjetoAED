#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Jogador
{

    private:
        string nome;
        int pontuacao;
        static int contador;

    public:
        Jogador(string nome);
        ~Jogador();

        void setNome(string);
        string getNome() const;

        void aumentaPontuacao();
        int getPontos() const;
        void controlaCont(int x);


};

#endif