#include "Fruta.h"

string getFileName(string n){

    //File names
    string v[10] = {"Pilha/F/abacaxi.bmp","Pilha/F/banana.bmp","Pilha/F/maca.bmp","Pilha/F/laranja.bmp","Pilha/F/caju.bmp",
    "Pilha/F/framboesa.bmp","Pilha/F/abacate.bmp","Pilha/F/morango.bmp","Pilha/F/uva.bmp","Pilha/F/melancia.bmp"};

    string v2[10] = {"abacaxi","banana","maca","laranja","caju","framboesa","abacate","morango","uva","melancia"};

    int pos=0;
    bool achou=false;

    while(pos < 10 && !achou){
        if(n == v2[pos])
            achou = true;
        pos++;
    }
    pos -= 1;
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

    vector<fruta *> frutas;
    frutas = vet_frutas(7);
    int tamanho = frutas.size();

    for(int i=0;i<7;i++){
        cout<<"Fruta ["<<i<<"]";
        cout<<"\n";
        cout<<frutas[i]->nome;
        cout<<"\n";
        cout<<getFileName(frutas[i]->nome);
        cout<<"\n";
        if(!frutas[i]->img)
            cout<<"Imagem nao carregada\n";
    }
}
*/
