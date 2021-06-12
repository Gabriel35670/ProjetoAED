#include <vector>
#include <algorithm>

#include "Jogador.h"
#include "Pilha.h"
#include "No.h"
#include "Fruta.h"

class Jogo
{

private:
    vector<Jogador *> lista_jogadores;
    int tempoSequência;
    int tempoGameplay;

public:
    Jogo(int tempoSeq, int tempoGam);
    ~Jogo();

    void setTempoSeq(int);
    int getTempoSeq() const;
    void setTempoGam(int);
    int getTempoGam() const;
    void embaralha(PILHA *P);
    void iniciarTempoGam();
    void iniciarTempoSeq();
};