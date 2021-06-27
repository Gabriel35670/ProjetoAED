#include "screen.h"

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


//Função global de inicizaliação do allegro
void init()
{
	//Iniciação
	allegro_init();
	install_timer();
	install_mouse();
	install_keyboard();
	set_color_depth(32);
	set_window_title("Memória Empilhada");
	set_close_button_callback(sair);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);

	screen_state = TITLESCREEN;
}
int main()
{

	//Função que inicia o allegro
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

	//Pilha de memoria
	PILHA *P_principal;

	//Jogador 1
	Jogador *j1;

	//Jogador 2
	Jogador *j2;

	//Controle de jogo
	bool jafoi = false;

	//Jogo global, com um valor default de inicio
	Jogo *game = new Jogo(16000, 90000, 5, "Facil");

	//Controle de single player/multiplayer
	int multi_single;


	//Laço principal do jogo, controla os hubs
	while (!(sai || key[KEY_ESC]))
	{
	
		//Tela inicial do jogo
		if (screen_state == TITLESCREEN)
			menu(buffer, logo, cursor, verdana, click, height, width, &screen_state, game);

		//Tela de carregamento single player
		else if (screen_state == SSCREEN)
		{

			//Caso clique em voltar/termine o jogo e queira jogar novamente, para evitar problemas
			if (!jafoi)
			{
				j1 = new Jogador("Jogador 1", game->getQtdFrutas());
				jafoi = true;
			}

			single_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j1, game);
			
			//Caso o jogador realmente queira jogar o jogo em single player
			if (screen_state == MEMORYSCREEN)
			{
				multi_single = 0;
				P_principal = CriarPilha(game->getQtdFrutas());
			}

			//Caso clique em voltar
			else
				jafoi = false;
		}

		//Tela de carregamento multiplayer
		else if (screen_state == MSCREEN)
		{
			//Caso clique em voltar/termine o jogo e queira jogar novamente, para evitar problemas
			if (!jafoi)
			{
				j1 = new Jogador("Jogador 1", game->getQtdFrutas());
				j2 = new Jogador("Jogador 2", game->getQtdFrutas());
				jafoi = true;
			}

			multi_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, game, j1, j2);
			
			//Caso o jogador realmente queira jogar multiplayer
			if (screen_state == MEMORYSCREEN)
			{
				multi_single = 1;
				P_principal = CriarPilha(game->getQtdFrutas());
			}

			//Caso clique em voltar
			else
				jafoi = false;
		}

		//Tela de configuração, determina a dificuldade do jogo e a quantidade de frutas
		else if (screen_state == CONFIGSCREEN)
			config_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, game);

		//Tela que mostra as frutas
		else if (screen_state == MEMORYSCREEN)
			memory_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, game);

		//Tela de jogo
		else if (screen_state == GAMESCREEN)
			for (int i = 0; i <= multi_single; i++)
			{
				//Caso tenha só um jogador
				if (i == 0)

					game_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j1, game);

				//Caso tenha mais de um jogador
				else if (i == 1)
				{
					game_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, j2, game);
					
					//Redirecionamento para a tela multiplayer
					screen_state = FINALSCREENMULTI;
				}
			}
		//Tela final para single player
		else if (screen_state == FINALSCREEN){
			final_screen(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, j1, game);
			
			//Permite jogar denovo
			jafoi = false;
		}

		//Tela final para multiplayer
		else if (screen_state == FINALSCREENMULTI){
			final_screen_multi(buffer, logo, cursor, verdana, click, height, width, &screen_state, P_principal, j1, j2, game);
			
			//Permite jogar novamente
			jafoi = false;
		}

		//Saída do jogo
		else if (screen_state == OUT)
			key[KEY_ESC] = true;
	}

	key[KEY_ESC] = false;

	//Desalocação dos bitmaps/fonts/samples alocados
	destroy_bitmap(buffer);
	destroy_bitmap(logo);
	destroy_bitmap(cursor);

	destroy_sample(click);

	destroy_font(verdana);

	return 0;
}
END_OF_MAIN()
