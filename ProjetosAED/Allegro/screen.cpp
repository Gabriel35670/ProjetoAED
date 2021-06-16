#include "screen.h"


enum{TITLESCREEN,SSCREEN,MSCREEN,MEMORYSCREEN,GAMESCREEN,FINALSCREEN,CONFIGSCREEN};

void menu(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

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

void single_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
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
END_OF_FUNCTION(single_screen)

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

void memory_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state){

	
	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
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
