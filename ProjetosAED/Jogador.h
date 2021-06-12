#include <string>
#include <iostream>

using namespace std;

class Jogador{

    private:

        string nome;
        int pontuacao;
        static int contador;

    public:

        Jogador(string nome);
        ~Jogador();

        void setNome(string);
        string getNome() const;

        void aumentaPontuacao(int);
        int getPontos() const;
};