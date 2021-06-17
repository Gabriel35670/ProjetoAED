#include "screen.h"


//screen.h

enum{TITLESCREEN,SSCREEN,MSCREEN,MEMORYSCREEN,GAMESCREEN,FINALSCREEN,CONFIGSCREEN};



//Feito
void menu(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	BITMAP *single,*single_highlight,*multi,*multi_highlight,*config,*config_highlight;
	Button *b_single,*b_multi, *b_config;

	//BITMAPS
	single = load_bitmap("BITMAPS/Tittle/Single.bmp", NULL);
  	single_highlight = load_bitmap("BITMAPS/Tittle/Single_Highlight.bmp", NULL);

  	multi = load_bitmap("BITMAPS/Tittle/Multi.bmp", NULL);
  	multi_highlight = load_bitmap("BITMAPS/Tittle/Multi_Highlight.bmp", NULL);

	config = load_bitmap("BITMAPS/Tittle/Config.bmp",NULL);
	config_highlight = load_bitmap("BITMAPS/Tittle/Config_Highlight.bmp", NULL);
		
	//BUTTONS
	b_single = create_button(single, single_highlight,click,90, height/1.3);
  	b_multi = create_button(multi, multi_highlight,click,90, height/1.2);
	b_config = create_button(config,config_highlight,click,90,height/1.1);

	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		button_input(b_single);
		button_input(b_multi);
		button_input(b_config);
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"Jogo da Memoria");
		
		//UPDATE
		if(b_single->ativado){

			exit_screen = true;
			*screen_state = SSCREEN;



		}
		else if(b_multi->ativado){
			exit_screen = true;
			*screen_state = MSCREEN;
		}
		else if(b_config->ativado){
			exit_screen = true;
			*screen_state = CONFIGSCREEN;
		}

		//BUTTONS
		button_draw(b_single, buffer);
    	button_draw(b_multi, buffer);
		button_draw(b_config,buffer);

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}

	//Finalização		
		destroy_bitmap(multi);
		destroy_bitmap(single_highlight);
		destroy_bitmap(single);
		destroy_bitmap(multi_highlight);
		destroy_bitmap(config);
		destroy_bitmap(config_highlight);

		destroy_button(b_single);
		destroy_button(b_multi);
		destroy_button(b_config);

}
END_OF_FUNCTION(menu)


//Arrumar a fonte do nome do jogador
void single_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,Jogador *j){

	BITMAP *nome,*voltar,*voltar_highlight,*start,*start_highlight;
	Button *b_start,*b_voltar;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
  	voltar_highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);

	start = load_bitmap("BITMAPS/Single/start.bmp", NULL);
  	start_highlight = load_bitmap("BITMAPS/Single/start_highlight.bmp", NULL);

	nome = load_bitmap("BITMAPS/Single/nome.bmp",NULL);

	//BUTTONS
	b_start = create_button(start, start_highlight,click,width/1.2, height/1.2);
  	b_voltar = create_button(voltar, voltar_highlight,click,width/12, height/11.5);
	
	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		button_input(b_start);
		button_input(b_voltar);
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//BITMAPS
		draw_sprite(buffer,nome,width/6,height/3);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"Single screen");
		textprintf_centre_ex(buffer, verdana, width/2.7, height/2.9, 0x0, -1,"%s",j->getNome().c_str());
		//UPDATE
		if(b_start->ativado){
			exit_screen = true;
			*screen_state = MEMORYSCREEN;
		}
		else if(b_voltar->ativado){
			exit_screen = true;
			*screen_state = TITLESCREEN;
			j->controlaCont(1);
			delete j;

		}

		//BUTTONS
		button_draw(b_start, buffer);
    	button_draw(b_voltar, buffer);
		
		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
}
END_OF_FUNCTION(single_screen)


//Verificar como realizar
void multi_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"MULTI SCREEN");
		
		//UPDATE

		//BUTTONS

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
}
END_OF_FUNCTION(multi_screen)


//Ultima coisa
void config_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"CONFIG SCREEN");
		
		//UPDATE

		//BUTTONS

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
}
END_OF_FUNCTION(config_screen)


//Em andamento
void memory_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;
	Jogo game(30,1.30);
	PILHA *P1;

	P1 = CriarPilha(10);
	game.embaralha(P1,10);
	
	//int tamanho = P1->tamanhoMAX;
	
	inicia_timer();
	//int controle = getTimer();

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"Pilha Correta, memorize a ordem!");

		//TIMER
		textprintf_centre_ex(buffer, verdana, SCREEN_W/2, SCREEN_H/9, makecol(0,0,0), -1,
       "%02d: %02d",(((getTimer()/1000)/60)%60) ,((getTimer()/1000)%60));

		//BITMAPS
		imprimePILHA(P1,buffer,width,height);


		//UPDATE
		if(((getTimer()/1000)%60) == 30){
			exit_screen = true;
			*screen_state = GAMESCREEN;
			trava_timer();
		}

		//BUTTONS

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
	//P1 = LiberarPilha(P1);

}
END_OF_FUNCTION(memory_screen)

void game_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;
	

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"GAME SCREEN");
		
		//UPDATE

		//BUTTONS

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
}
END_OF_FUNCTION(game_screen)

void final_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"Tela final");
		
		//UPDATE

		//BUTTONS

		//MOUSE
		draw_sprite(buffer,cursor,mouse_x-6,mouse_y-6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);
		
		//RESTO
		rest(10);
		clear(buffer);	
	}
}
END_OF_FUNCTION(final_screen)

//Fruta.cpp
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

//No.cpp
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

//Pilha.cpp

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
        if(Desempilhar(P,aux))
			;
    }

    return P;
}

//Jogador.cpp

int Jogador::contador = 0;

Jogador::Jogador(string nome)
{

    setNome(nome);
    pontuacao =0;
}

Jogador::~Jogador() {}

void Jogador::setNome(string n)
{

    if (n != "\0")
        nome = n;
    else
    {
        string v[4] = {"Jogador1", "Jogador2", "Jogador3", "Jogador4"};

        nome = v[contador];
    }

    contador++;
}

void Jogador::aumentaPontuacao()
{
    pontuacao++;
}

int Jogador::getPontos() const
{
    return pontuacao;
}

string Jogador::getNome() const{
    return nome;
}

void Jogador::controlaCont(int x){
    this->contador -= x;
}

//Jogo.cpp

Jogo::Jogo(int tempoSeq, int tempoGam)
{

    setTempoSeq(tempoSeq);
    setTempoGam(tempoGam);
}

Jogo::~Jogo() {}

void Jogo::setTempoSeq(int tempoSeq)
{
    if (tempoSeq <= 0)
    {
        cout << "Tempo inválido" << endl;
    }
    else
    {
        tempoSequencia = tempoSeq;
    }
}

void Jogo::setTempoGam(int tempoGam)
{
    if (tempoGam <= 0)
    {
        cout << "Tempo inválido" << endl;
    }
    else
    {
        tempoGameplay = tempoGam;
    }
}

int Jogo::getTempoGam() const
{
    return tempoGameplay;
}

int Jogo::getTempoSeq() const
{
    return tempoSequencia;
}

void Jogo::embaralha(PILHA *P,int tamanho)
{
    vector<fruta *> frutas;

    frutas = vet_frutas(tamanho);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gera uma "seed" aleatoria

    shuffle(frutas.begin(), frutas.end(), default_random_engine(seed));

    int tam = frutas.size();
    for (int i = 0; i < tam; i++)
    {
        No *N;
        N = new No;
        N->f = frutas[i];
        Empilhar(P, N);
    }
}
