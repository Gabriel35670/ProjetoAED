#include <allegro.h>


#include <iostream>
#include <time.h>

#include "button.h"
#include "screen.h"

using namespace std;
/* g++ -Wall main.cpp -o programa `allegro-config --libs` 
SO: Linux
*/
//funções
volatile int sai=0;
void sair(){ sai = TRUE; }


volatile int timer;

void incrementa_timer(){ timer++;}
END_OF_FUNCTION(incrementa_timer)

//Variáveis Globais
int width  = 800;
int height = 600;

BITMAP *buffer, *logo, *cursor;
FONT *verdana;
SAMPLE* click;

//Estados da tela
enum{TITLESCREEN,SSCREEN,MSCREEN,MEMORYSCREEN,GAMESCREEN,FINALSCREEN,CONFIGSCREEN};
int screen_state;


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

	//TIMER
	timer = 0;

  screen_state = TITLESCREEN;

}

void iniciaTimer(){

	LOCK_FUNCTION(incrementa_timer);
	LOCK_VARIABLE(timer);
	install_int_ex(incrementa_timer, MSEC_TO_TIMER(1));

}

int main() {
	
	init();

	//BITMAP GLOBAL
	buffer = create_bitmap(width, height);
	logo   = load_bitmap("BITMAPS/Fundo.bmp", NULL);

	//FONT GLOBAL
	verdana = load_font("FONTS/verdana.pcx", NULL, NULL);	

	//MOUSE GLOBAL
	cursor = load_bitmap("BITMAPS/cursor.bmp",NULL);

	//SOM GLOBAL
	click = load_sample("SAMPLES/click.wav");


	while (!(sai || key[KEY_ESC]))
	{		
		if(screen_state == TITLESCREEN)
				menu(buffer,logo,cursor,verdana,click,height,width,&screen_state);	
		else if(screen_state == SSCREEN)
			single_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);

		else if(screen_state == MSCREEN)
			multi_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);

		else if(screen_state == CONFIGSCREEN)
			config_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);

		else if(screen_state == MEMORYSCREEN)
			memory_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);

		else if(screen_state == GAMESCREEN)
			game_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);

		else if(screen_state == FINALSCREEN)
			final_screen(buffer,logo,cursor,verdana,click,height,width,&screen_state);
	
	}

	destroy_bitmap(buffer);
	destroy_bitmap(logo);
	destroy_bitmap(cursor);

	destroy_sample(click);

	destroy_font(verdana);
	
	return 0;
}
END_OF_MAIN()




//TIMER
		/*
		textprintf_centre_ex(buffer, verdana, SCREEN_W/2, SCREEN_H/2, makecol(0,0,0), -1,
       "Clock: %02d: %02d",(((timer/1000)/60)%60) ,((timer/1000)%60));
*/