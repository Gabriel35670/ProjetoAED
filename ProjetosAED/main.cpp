#include "Pilha.h"
#include <string>


int main(){

    PILHA *P1,*P2;

    int t1,t2;

    cout<<"Tamanho maximo da pilha P1: ";
    cin>>t1;

    cout<<"Tamanho maximo da pilha P2: ";
    cin>>t2;

    P1 = CriarPilha(t1);
    P2 = CriarPilha(t2);

    string entrada;
    No *noh;

    while(!Cheia(P1)){

        cout<<"Qual valor adicionar na P1(so para quando cheia): ";
        cin>>entrada;

        if(entrada != "\0"){
            fruta *f;
            f = criaFruta(entrada);
            noh = criaNo(f);
            Empilhar(P1,noh);
        }
    }

    while(!Cheia(P2)){

        cout<<"Qual valor adicionar na P2(so para quando cheia): ";
        cin>>entrada;

        if(entrada != "\0"){
            fruta *f2;
            f2 = criaFruta(entrada);
            noh = criaNo(f2);
            Empilhar(P2,noh);
        }
    }
    cout<<"\n";
    imprimePILHA(P1);
    cout<<"\n";
    imprimePILHA(P2);
    cout<<"\n";

    string op = "s";
    
    fruta *auxiliar;
    auxiliar = criaFruta("sla");


    while(op == "s" || op == "S"){

        cout<<"Deseja retirar um valor de P1:[s/n]: ";
        cin>>op;

        if(op == "s" || op == "S"){
            noh = criaNo(auxiliar);
            Desempilhar(P1,noh);
            cout<<"O valor retirado foi: {"<<noh->f->nome<<"}.\n";
        }
    }

    op = "s";

    while(op == "s" || op == "S"){

        cout<<"Deseja retirar um valor de P2:[s/n]: ";
        cin>>op;

        if(op == "s" || op == "S"){
            noh = criaNo(auxiliar);
            Desempilhar(P2,noh);
            cout<<"O valor retirado foi: {"<<noh->f->nome<<"}.\n";
        }
    }

    cout<<"\n";
    imprimePILHA(P1);
    cout<<"\n";
    imprimePILHA(P2);
    cout<<"\n";

    int igualdade = ComparaPilhas(P1,P2);

    cout<<"Tem "<<igualdade<<" valor(es) iguais(na mesma posicao) em P1 e P2.\n";

    cout<<"\n";
    imprimePILHA(P1);
    cout<<"\n";
    imprimePILHA(P2);
    cout<<"\n";

    noh = LiberaNo(noh);
    P1 = LiberarPilha(P1);
    P2 = LiberarPilha(P2);

    return 0;


}

