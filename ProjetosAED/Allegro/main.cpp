#include <allegro.h>


#include <iostream>
#include <time.h>

#include "button.h"
<<<<<<< HEAD
#include "screen.h"

=======
>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86
using namespace std;
/* g++ -Wall main.cpp -o programa `allegro-config --libs` 
SO: Linux
*/
//funções
<<<<<<< HEAD
volatile int sai=0;
void sair(){ sai = TRUE; }

=======
void sair();
void menu();
void single_screen();
void multi_screen();
void memory_screen();
void game_screen();
void final_screen();
void config_screen();
>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86

volatile int timer;

void incrementa_timer(){ timer++;}
END_OF_FUNCTION(incrementa_timer)

//Variáveis Globais
<<<<<<< HEAD
=======
int sai    = 0;
>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86
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


<<<<<<< HEAD
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
=======

	while (!(sai || key[KEY_ESC]))
	{		
		if(screen_state == TITLESCREEN)
			menu();		
		else if(screen_state == SSCREEN)
			single_screen();

		else if(screen_state == MSCREEN)
			multi_screen();

		else if(screen_state == CONFIGSCREEN)
			config_screen();

		else if(screen_state == MEMORYSCREEN)
			memory_screen();

		else if(screen_state == GAMESCREEN)
			game_screen();

		else if(screen_state == FINALSCREEN)
			final_screen();
>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86
	
	}

	destroy_bitmap(buffer);
	destroy_bitmap(logo);
	destroy_bitmap(cursor);

	destroy_sample(click);

	destroy_font(verdana);
	
	return 0;
}
END_OF_MAIN()
<<<<<<< HEAD
=======
void menu(){

	BITMAP *single,*single_highlight,*multi,*multi_highlight,*config,*config_highlight;
	Button *b_single,*b_multi, *b_config;

	//BITMAPS
	single = load_bitmap("BITMAPS/Single.bmp", NULL);
  	single_highlight = load_bitmap("BITMAPS/Single_Highlight.bmp", NULL);

  	multi = load_bitmap("BITMAPS/Multi.bmp", NULL);
  	multi_highlight = load_bitmap("BITMAPS/Multi_Highlight.bmp", NULL);

	config = load_bitmap("BITMAPS/Config.bmp",NULL);
	config_highlight = load_bitmap("BITMAPS/Config_Highlight.bmp", NULL);
		
	//BUTTONS
	b_single = create_button(single, single_highlight,click,90, height/1.3);
  	b_multi = create_button(multi, multi_highlight,click,90, height/1.2);
	b_config = create_button(config,config_highlight,click,90,height/1.1);


	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
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
			screen_state = SSCREEN;



		}
		else if(b_multi->ativado){
			exit_screen = true;
			screen_state = MSCREEN;
		}
		else if(b_config->ativado){
			exit_screen = true;
			screen_state = CONFIGSCREEN;
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


void sair(){sai= 1;}
END_OF_FUNCTION(sair)


void single_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"Single screen");
		
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

void multi_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
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


void config_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
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

void memory_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
	{		

		//Botoes iniciados
		
	
		//Tela de fundo
		draw_sprite(buffer,logo,0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width/2, height/12, 0x0, -1,"MEMORY SCREEN");
		
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


void game_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
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


void final_screen(){

	
	bool exit_screen = false;

	while (!(sai || key[KEY_ESC] || exit_screen))
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

>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86




//TIMER
		/*
		textprintf_centre_ex(buffer, verdana, SCREEN_W/2, SCREEN_H/2, makecol(0,0,0), -1,
       "Clock: %02d: %02d",(((timer/1000)/60)%60) ,((timer/1000)%60));
*/