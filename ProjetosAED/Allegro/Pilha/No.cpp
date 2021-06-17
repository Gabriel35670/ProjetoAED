#include "No.h"

No* criaNo(fruta *fruta){

    No *N;
    N = new No;

    N->proximo = NULL;
    N->f = fruta;
    
    return N;
}

No* LiberaNo(No *X){

    delete X;

    return X;
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

    fruta *f[7];
    string v[10] = {"abacaxi","banana","maca","laranja","caju","framboesa","abacate","morango","uva","melancia"};


   for(int j=0;j<7;j++){
       f[j] = criaFruta(v[j]);
   }

    No *noh[7];

    for(int i=0;i<7;i++){
        noh[i] = criaNo(f[i]);
    }

    for(int w=0;w<7;w++){
        if(noh[w]->proximo == NULL){

            cout<<"Fruta ["<<w<<"]\n";
            cout<<"Nome:"<<noh[w]->f->nome<<"\n";
            if(!noh[w]->f->img){
                cout<<"Imagem nao carregada\n";
            }
            

        }
    }

}
*/