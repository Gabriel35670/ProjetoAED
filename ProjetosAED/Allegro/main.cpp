#include <allegro.h>

#include <iostream>
#include "screen.h"

using namespace std;
/* g++ -Wall main.cpp -o programa `allegro-config --libs` 
SO: Linux

g++ main.cpp screen.cpp timer/timer.cpp buttons/button.cpp -o ed -I c:\MinGW\include -L c:\MinGW\lib C:\MinGW\lib\liballeg.a 
SO: Windows
*/
//funções
volatile int sai = 0;
void sair() { sai = TRUE; }

//Variáveis Globais
int width = 800;
int height = 600;

BITMAP *buffer, *logo, *cursor;
FONT *verdana;
SAMPLE *click;

//Estados da tela
enum
{
	TITLESCREEN,
	SSCREEN,
	MSCREEN,
	MEMORYSCREEN,
	GAMESCREEN,
	FINALSCREEN,
	FINALSCREENMULTI,
	CONFIGSCREEN,
	OUT
};
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

	screen_state = TITLESCREEN;
}
int main()
{

	init();

	//BITMAP GLOBAL
	buffer = create_bitmap(width, height);
	logo = load_bitmap("BITMAPS/Principais/Fundo.bmp", NULL);

	//FONT GLOBAL
	verdana = load_font("FONTS/verdana.pcx", NULL, NULL);

	//MOUSE GLOBAL
	cursor = load_bitmap("BITMAPS/Principais/cursor.bmp", NULL);

	//SOM GLOBAL
	click = load_sample("SAMPLES/click.wav");

	//int single =0;
	PILHA *P_principal;
	Jogador *j1;
	Jogador *j2;
	bool jafoi = false;
	Jogo *game = new Jogo(16000, 90000, 5, "Facil");
	int multi_single;
	while (!(sai || key[KEY_ESC]))
	{
		if (game->getDificuldade() == "Facil")
		{
			game->setTempoSeq(16000);
			game->setTempoGam(90000);
		}
		else if (game->getDificuldade() == "Medio")
		{
			game->setTempoSeq(11000);
			game->setTempoGam(60000);
		}
		else if (game->getDificuldade() == "Dificil")
		{
			game->setTempoSeq(6000);
			game->setTempoGam(30000);
		}
		if (screen_state == TITLESCREEN)
			menu(buffer, logo, cursor, verdana, click, height, width, &screen_state, game);
		else if (screen_state == SSCREEN)
		{

			if (!jafoi)
			{
				j1 = new Jogador("Jogador 1", game->getQtdFrutas());
				jafoi = true;
			}

			single_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j1, game);
			if (screen_state == MEMORYSCREEN)
			{
				multi_single = 0;
				P_principal = CriarPilha(game->getQtdFrutas());
			}
			else
				jafoi = false;
		}

		else if (screen_state == MSCREEN)
		{
			if (!jafoi)
			{
				j1 = new Jogador("Jogador 1", game->getQtdFrutas());
				j2 = new Jogador("Jogador 2", game->getQtdFrutas());
				jafoi = true;
			}

			multi_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, game, j1, j2);
			if (screen_state == MEMORYSCREEN)
			{
				multi_single = 1;
				P_principal = CriarPilha(game->getQtdFrutas());
			}
			else
				jafoi = false;
		}
		else if (screen_state == CONFIGSCREEN)
			config_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, game);

		else if (screen_state == MEMORYSCREEN)
			memory_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, game);

		else if (screen_state == GAMESCREEN)
			for (int i = 0; i <= multi_single; i++)
			{
				if (i == 0)

					game_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j1, game);

				else if (i == 1)
				{
					game_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j2, game);
					screen_state = FINALSCREENMULTI;
				}

				if (multi_screen == 0)
				{
					screen_state = FINALSCREEN;
				}
			}
		else if (screen_state == FINALSCREEN)
			final_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, j1, game);
		else if (screen_state == FINALSCREENMULTI)
			final_screen_multi(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, j1, j2, game);
		else if (screen_state == OUT)
			key[KEY_ESC] = true;
	}

	destroy_bitmap(buffer);
	destroy_bitmap(logo);
	destroy_bitmap(cursor);

	destroy_sample(click);

	destroy_font(verdana);

	if (screen_state != TITLESCREEN)
	{
		P_principal = LiberarPilha(P_principal);
		j1->LPilha();
		delete j1;
		delete game;
	}

	return 0;
}
END_OF_MAIN()
