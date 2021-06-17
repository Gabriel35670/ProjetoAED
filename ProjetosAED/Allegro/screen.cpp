#include "screen.h"


enum{TITLESCREEN,SSCREEN,MSCREEN,MEMORYSCREEN,GAMESCREEN,FINALSCREEN,CONFIGSCREEN};

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
	/*Jogo game(30,1.30);
	PILHA *P1;

	P1 = CriarPilha(5);
	game.embaralha(P1);
	*/
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
		//imprimePILHA(P1,buffer,widhth,height);


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
