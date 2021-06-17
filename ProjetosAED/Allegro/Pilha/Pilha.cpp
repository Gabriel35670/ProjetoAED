#include "Pilha.h"


PILHA* CriarPilha(int tamanhoMAX){

    PILHA *P = new PILHA;
    P->tamanhoMAX = tamanhoMAX;
    P->topo = NULL;
    

    return P;
}
bool Cheia(PILHA *P){

    int contador=0;
    No *aux = P->topo;
    while(aux != NULL){
        aux = aux->proximo;
        contador++;
    }
    
    return contador == P->tamanhoMAX;
}

bool Vazia(PILHA *P){

    return P->topo == NULL;
}

bool Empilhar(PILHA *P,No *novo){

    if(Cheia(P) || novo == NULL){
        return false;
    }
    else{
        if(Vazia(P)){
            novo->proximo = NULL;
            P->topo = novo;
        }
        else{
            No *aux;
            aux = P->topo;
            P->topo = novo;
            P->topo->proximo = aux;
        }
    }
    return true;
}

bool Desempilhar(PILHA *P,No *X){

    if(Vazia(P)){
        return false;
    }
    No *lixo;
    
    lixo = P->topo;
    X->f = P->topo->f;
    P->topo = P->topo->proximo;
    
    lixo = LiberaNo(lixo);

    return true;
}

int ComparaPilhas(PILHA *P1, PILHA *P2){

    int igualdades=0;

    No *N1 = P1->topo;
    No *N2 = P2->topo;

    while(N1 != NULL && N2 != NULL){

        if(igual(N1->f,N2->f)){
            
            igualdades++;
        }
        N1 = N1->proximo;
        N2 = N2->proximo;
    }

    return igualdades;
}

void imprimePILHA(PILHA *P,BITMAP *buffer,int width,int height){

    No *aux;
    aux = P->topo;

    double contador=0;

    while(aux != NULL){
        
        draw_sprite(buffer,aux->f->img,1+(80*contador),height/3);
        contador += 1;
        aux = aux->proximo;
    }

}

PILHA* LiberarPilha(PILHA *P){

    No *aux;
    fruta *f;
    f = criaFruta("MELAO");
    aux = criaNo(f);
    while(!Vazia(P)){
        Desempilhar(P,aux);
    }

    return P;
}

//Teste para verificar erros
/*int sai=0;

void sair(){sai=1;}
int width =800;
int height=600;

void init()
{
  //Iniciação
	allegro_init();
	install_timer();
	install_mouse();
    install_keyboard();
	set_color_depth(32);
	set_window_title("Jogo da Pilha");
	set_close_button_callback(sair);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);  
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);

}



int main(){

    init();

    fruta *f[10];
    string v[10] = {"abacaxi","banana","maca","laranja","caju","framboesa","abacate","morango","uva","melancia"};


   for(int j=0;j<10;j++){
       f[j] = criaFruta(v[j]);
   }

    No *noh[10];

    for(int i=0;i<10;i++){
        noh[i] = criaNo(f[i]);
    }

    PILHA *P1 = CriarPilha(10);
    BITMAP *buffer;
    buffer = create_bitmap(width, height);

    for(int w=0;w<10;w++)
        if(Empilhar(P1,noh[w]))
            cout<<"Empilhado com sucesso\n";

    while (!(sai || key[KEY_ESC])){
        imprimePILHA(P1,buffer,width,height);
    //impressao(P1);
    
    //BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);

    }

}
*/