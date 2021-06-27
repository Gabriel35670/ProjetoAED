#include "screen.h"
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

//Feito
void menu(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game)
{

	BITMAP *single, *single_highlight, *multi, *multi_highlight, *config, *config_highlight, *logo_game, *sair_highlight, *sair;
	Button *b_single, *b_multi, *b_config, *b_sair;

	//BITMAPS
	single = load_bitmap("BITMAPS/Tittle/Single.bmp", NULL);
	single_highlight = load_bitmap("BITMAPS/Tittle/Single_Highlight.bmp", NULL);

	multi = load_bitmap("BITMAPS/Tittle/Multi.bmp", NULL);
	multi_highlight = load_bitmap("BITMAPS/Tittle/Multi_Highlight.bmp", NULL);

	config = load_bitmap("BITMAPS/Tittle/Config.bmp", NULL);
	config_highlight = load_bitmap("BITMAPS/Tittle/Config_Highlight.bmp", NULL);

	logo_game = load_bitmap("BITMAPS/Tittle/logo.bmp", NULL);

	sair = load_bitmap("BITMAPS/Final/sair.bmp", NULL);
	sair_highlight = load_bitmap("BITMAPS/Final/sair_highlight.bmp", NULL);


	//BUTTONS
	b_single = create_button(single, single_highlight, click, 90, height / 1.32);
	b_multi = create_button(multi, multi_highlight, click, 90, height / 1.2);
	b_config = create_button(config, config_highlight, click, 90, height / 1.1);
	b_sair = create_button(sair, sair_highlight, click, width-200, height / 9);


	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_single);
		button_input(b_multi);
		button_input(b_config);
		button_input(b_sair);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);
		draw_sprite(buffer, logo_game, width / 2.6, height / 12);
		//Titulo do jogo

		//UPDATE
		if (b_single->ativado)
		{

			exit_screen = true;
			*screen_state = SSCREEN;
		}
		else if (b_multi->ativado)
		{
			exit_screen = true;
			*screen_state = MSCREEN;
		}
		else if (b_config->ativado)
		{
			exit_screen = true;
			*screen_state = CONFIGSCREEN;
		}
		else if(b_sair->ativado){
			exit_screen = true;
			*screen_state = OUT;
		}

		//BUTTONS
		button_draw(b_single, buffer);
		button_draw(b_multi, buffer);
		button_draw(b_config, buffer);
		button_draw(b_sair,buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

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
void single_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogador *j, Jogo *game)
{

	BITMAP *voltar, *voltar_highlight, *start, *start_highlight, *edit, *edit_highlight, *check, *check_highlight;
	Button *b_start, *b_voltar, *b_editName, *b_checkName;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
	voltar_highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);

	start = load_bitmap("BITMAPS/Single/start.bmp", NULL);
	start_highlight = load_bitmap("BITMAPS/Single/start_highlight.bmp", NULL);

	edit = load_bitmap("BITMAPS/Single/fundo_branco.bmp", NULL);
	edit_highlight = load_bitmap("BITMAPS/Single/highlightedit.bmp", NULL);

	check = load_bitmap("BITMAPS/Single/check.bmp", NULL);
	check_highlight = load_bitmap("BITMAPS/Single/highlightCheck.bmp", NULL);

	//BUTTONS
	b_start = create_button(start, start_highlight, click, width / 1.2, height / 1.2);
	b_voltar = create_button(voltar, voltar_highlight, click, width / 12, height / 11.5);
	b_editName = create_button(edit, edit_highlight, click, width / 1.9, height / 3.1);
	b_checkName = create_button(check, check_highlight, click, 600, 800);

	string name = j->getNome();

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_start);
		button_input(b_voltar);
		button_input(b_editName);
		button_input(b_checkName);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Digite seu nome e comece o jogo!");
		textprintf_centre_ex(buffer, verdana, width / 2.2, height / 2.9, 0x0, -1, "%s", name.c_str());
		//UPDATE

		if (b_start->ativado)
		{
			exit_screen = true;
			*screen_state = MEMORYSCREEN;
		}
		if (b_voltar->ativado)
		{
			b_voltar->ativado = false;
			exit_screen = true;
			*screen_state = TITLESCREEN;
			j->controlaCont(1);
			delete j;
		}

		if (b_editName->ativado)
		{
			change_pos_button(width / 1.7, height / 3.1, b_checkName);
			digita(&name);
		}

		if (b_checkName->ativado)
		{
			b_editName->ativado = false;
			change_pos_button(600, 800, b_checkName);
			b_checkName->ativado = false;
		}

		//BUTTONS
		button_draw(b_start, buffer);
		button_draw(b_voltar, buffer);
		button_draw(b_editName, buffer);
		button_draw(b_checkName, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}
	//Muda nome
	if (*screen_state == MEMORYSCREEN)
		j->setNome(name);

	destroy_bitmap(voltar_highlight);
	destroy_bitmap(voltar);
	destroy_bitmap(start);
	destroy_bitmap(start_highlight);

	destroy_bitmap(check);
	destroy_bitmap(check_highlight);
	destroy_bitmap(edit);
	destroy_bitmap(edit_highlight);

	destroy_button(b_start);
	destroy_button(b_voltar);
	destroy_button(b_checkName);
	destroy_button(b_editName);
}
END_OF_FUNCTION(single_screen)

//Verificar como realizar
void multi_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game, Jogador *j1, Jogador *j2)
{

	BITMAP *voltar, *voltar_highlight, *start, *start_highlight, *edit, *edit_highlight, *check, *check_highlight;
	Button *b_start, *b_voltar, *b_editName1, *b_checkName1, *b_editName2, *b_checkName2;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
	voltar_highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);

	start = load_bitmap("BITMAPS/Single/start.bmp", NULL);
	start_highlight = load_bitmap("BITMAPS/Single/start_highlight.bmp", NULL);

	edit = load_bitmap("BITMAPS/Single/fundo_branco.bmp", NULL);
	edit_highlight = load_bitmap("BITMAPS/Single/highlightedit.bmp", NULL);

	check = load_bitmap("BITMAPS/Single/check.bmp", NULL);
	check_highlight = load_bitmap("BITMAPS/Single/highlightCheck.bmp", NULL);


	//BUTTONS
	b_start = create_button(start, start_highlight, click, width / 1.2, height / 1.2);
	b_voltar = create_button(voltar, voltar_highlight, click, width / 12, height / 11.5);
	b_editName1 = create_button(edit, edit_highlight, click, width / 1.9, height / 4.3);
	b_editName2 = create_button(edit, edit_highlight, click, width / 1.9, height / 3.1);
	b_checkName1 = create_button(check, check_highlight, click, 600, 800);
	b_checkName2 = create_button(check, check_highlight, click, 600, 800);

	string name1 = j1->getNome();
	string name2 = j2->getNome();

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_start);
		button_input(b_voltar);
		button_input(b_editName1);
		button_input(b_editName2);
		button_input(b_checkName1);
		button_input(b_checkName2);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Digitem seus nomes e comecem o jogo!");
		textprintf_centre_ex(buffer, verdana, width / 2.2, height / 4, 0x0, -1, "%s", name1.c_str());
		textprintf_centre_ex(buffer, verdana, width / 2.2, height / 2.9, 0x0, -1, "%s", name2.c_str());
		//UPDATE

		if (b_start->ativado)
		{
			exit_screen = true;
			*screen_state = MEMORYSCREEN;
		}
		if (b_voltar->ativado)
		{
			b_voltar->ativado = false;
			exit_screen = true;
			*screen_state = TITLESCREEN;
			j1->controlaCont(1);
			delete j1;
		}
		if (b_editName1->ativado && !b_editName2->ativado)
		{
			change_pos_button(width / 1.7, height / 4.3, b_checkName1);
			digita(&name1);
		}

		if (b_editName2->ativado && !b_editName1->ativado)
		{
			change_pos_button(width / 1.7, height / 3.1, b_checkName2);
			digita(&name2);
		}

		if (b_checkName1->ativado)
		{
			b_editName1->ativado = false;
			change_pos_button(600, 800, b_checkName1);
			b_checkName1->ativado = false;
		}
		if (b_checkName2->ativado)
		{
			b_editName2->ativado = false;
			change_pos_button(600, 800, b_checkName2);
			b_checkName2->ativado = false;
		}

		//BUTTONS
		button_draw(b_start, buffer);
		button_draw(b_voltar, buffer);
		button_draw(b_editName1, buffer);
		button_draw(b_editName2, buffer);
		button_draw(b_checkName1, buffer);
		button_draw(b_checkName2, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}
	//Muda nome
	if (*screen_state == MEMORYSCREEN)
	{
		j1->setNome(name1);
		j2->setNome(name2);
	}

	destroy_bitmap(voltar_highlight);
	destroy_bitmap(voltar);
	destroy_bitmap(start);
	destroy_bitmap(start_highlight);

	destroy_button(b_start);
	destroy_button(b_voltar);
	destroy_button(b_editName1);
	destroy_button(b_editName2);
	destroy_button(b_checkName1);
	destroy_button(b_checkName2);
}
END_OF_FUNCTION(multi_screen)

//Ultima coisa
void config_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game)
{
	string dificuldade[] = {"Facil", "Medio", "Dificil"};
	int i = 0;

	BITMAP *setaDireita, *setaEsquerda, *highlight, *voltar, *highlightSeta;
	Button *bSetaDireitaFrutas, *bSetaEsquerdaFrutas, *bSetaDireitaDificuldade, *bSetaEsquerdaDificuldade, *b_voltar;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
	setaDireita = load_bitmap("BITMAPS/Single/setaDireita.bmp", NULL);
	setaEsquerda = load_bitmap("BITMAPS/Single/setaEsquerda.bmp", NULL);
	highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);
	highlightSeta = load_bitmap("BITMAPS/Single/highlightSeta.bmp", NULL);

	b_voltar = create_button(voltar, highlight, click, width / 20, height / 22);
	bSetaDireitaFrutas = create_button(setaDireita, highlightSeta, click, width / 1.4, height / 7);
	bSetaEsquerdaFrutas = create_button(setaEsquerda, highlightSeta, click, width / 2, height / 7);
	bSetaDireitaDificuldade = create_button(setaDireita, highlightSeta, click, width / 1.4, height / 3.5);
	bSetaEsquerdaDificuldade = create_button(setaEsquerda, highlightSeta, click, width / 2, height / 3.5);

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_voltar);
		button_input(bSetaDireitaFrutas);
		button_input(bSetaEsquerdaFrutas);
		button_input(bSetaDireitaDificuldade);
		button_input(bSetaEsquerdaDificuldade);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Ajustes no Jogo");
		textprintf_centre_ex(buffer, verdana, width / 3.5, height / 6, 0x0, -1, "Quantidade de frutas: ");
		textprintf_centre_ex(buffer, verdana, width / 1.5, height / 6, 0x0, -1, "%d", game->getQtdFrutas());
		textprintf_centre_ex(buffer, verdana, width / 3.5, height / 3, 0x0, -1, "Dificuldade do tempo: ");
		textprintf_centre_ex(buffer, verdana, width / 1.5, height / 3, 0x0, -1, "%s", game->getDificuldade().c_str());

		//UPDATE
		if (bSetaDireitaFrutas->ativado)
		{
			bSetaDireitaFrutas->ativado = false;
			game->setQtdFrutas(game->getQtdFrutas() + 1);
		}
		if (bSetaEsquerdaFrutas->ativado)
		{
			bSetaEsquerdaFrutas->ativado = false;
			game->setQtdFrutas(game->getQtdFrutas() - 1);
		}

		if (bSetaEsquerdaDificuldade->ativado)
		{
			bSetaEsquerdaDificuldade->ativado = false;
			if (i > 0)
			{
				i--;
				game->setDificuldade(dificuldade[i]);
			}
			else
			{

				i = 2;
				game->setDificuldade(dificuldade[i]);
			}
		}
		if (bSetaDireitaDificuldade->ativado)
		{
			bSetaDireitaDificuldade->ativado = false;
			if (i < 2)
			{
				i++;
				game->setDificuldade(dificuldade[i]);
			}
			else
			{
				i = 0;
				game->setDificuldade(dificuldade[i]);
			}
		}

		if (b_voltar->ativado)
		{
			b_voltar->ativado = false;
			exit_screen = true;
			*screen_state = TITLESCREEN;
		}
		//BUTTONS
		button_draw(b_voltar, buffer);
		button_draw(bSetaDireitaFrutas, buffer);
		button_draw(bSetaEsquerdaFrutas, buffer);
		button_draw(bSetaDireitaDificuldade, buffer);
		button_draw(bSetaEsquerdaDificuldade, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}
	

	//Seta o tempo de acordo com a dificuldade
	
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
	destroy_bitmap(setaDireita);
	destroy_bitmap(setaEsquerda);
	destroy_bitmap(highlight);
	destroy_bitmap(voltar);
	destroy_bitmap(highlightSeta);

	destroy_button(bSetaDireitaFrutas);
	destroy_button(bSetaEsquerdaFrutas);
	destroy_button(bSetaDireitaDificuldade);
	destroy_button(bSetaEsquerdaDificuldade);
	destroy_button(b_voltar);
}
END_OF_FUNCTION(config_screen)

//Em andamento
void memory_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogo *game)
{

	bool exit_screen = false;
	game->embaralha(P);


	inicia_timer(game->getTempoSeq());

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//EScrita topo da pagina
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Pilha Correta, memorize a ordem!");

		//TIMER
		textprintf_centre_ex(buffer, verdana, SCREEN_W / 2, SCREEN_H / 9, makecol(0, 0, 0), -1,
							 "%02d: %02d", (((getTimer() / 1000) / 60) % 60), ((getTimer() / 1000) % 60));

		//BITMAPS
		imprimePILHA(P, buffer, width, height / 2, game->getQtdFrutas(), verdana);

		//UPDATE
		if (((getTimer() / 1000) % 60) == 0)
		{
			exit_screen = true;
			*screen_state = GAMESCREEN;
			trava_timer();
		}

		//BUTTONS

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}
}
END_OF_FUNCTION(memory_screen)

void game_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogador *j1, Jogo *game)
{

	//Cria frutas
	string v[10] = {"abacaxi", "banana", "maca", "laranja", "caju", "framboesa", "abacate", "morango", "uva", "melancia"};
	No *noh[10];
	fruta *f[10];
	for (int i = 0; i < 10; i++)
	{

		f[i] = criaFruta(v[i]);
		noh[i] = criaNo(f[i]);
	}

	bool exit_screen = false;

	//BITMAPS FRUTAS(NO TOTAL SAO 10)
	BITMAP *abacaxi = load_bitmap("Pilha/F/abacaxi.bmp", NULL);
	BITMAP *banana = load_bitmap("Pilha/F/banana.bmp", NULL);
	BITMAP *maca = load_bitmap("Pilha/F/maca.bmp", NULL);
	BITMAP *laranja = load_bitmap("Pilha/F/laranja.bmp", NULL);
	BITMAP *caju = load_bitmap("Pilha/F/caju.bmp", NULL);
	BITMAP *framboesa = load_bitmap("Pilha/F/framboesa.bmp", NULL);
	BITMAP *abacate = load_bitmap("Pilha/F/abacate.bmp", NULL);
	BITMAP *morango = load_bitmap("Pilha/F/morango.bmp", NULL);
	BITMAP *uva = load_bitmap("Pilha/F/uva.bmp", NULL);
	BITMAP *melancia = load_bitmap("Pilha/F/melancia.bmp", NULL);

	//BITMAPS(highlights)
	BITMAP *fruta_highlight = load_bitmap("Pilha/F/fruta_highlight.bmp", NULL);

	//BUTTONS
	Button *b_abacaxi = create_button(abacaxi, fruta_highlight, click, 1, height / 1.2);
	Button *b_banana = create_button(banana, fruta_highlight, click, 80, height / 1.2);
	Button *b_maca = create_button(maca, fruta_highlight, click, 160, height / 1.2);
	Button *b_laranja = create_button(laranja, fruta_highlight, click, 240, height / 1.2);
	Button *b_caju = create_button(caju, fruta_highlight, click, 320, height / 1.2);
	Button *b_framboesa = create_button(framboesa, fruta_highlight, click, 400, height / 1.2);
	Button *b_abacate = create_button(abacate, fruta_highlight, click, 480, height / 1.2);
	Button *b_morango = create_button(morango, fruta_highlight, click, 560, height / 1.2);
	Button *b_uva = create_button(uva, fruta_highlight, click, 640, height / 1.2);
	Button *b_melancia = create_button(melancia, fruta_highlight, click, 720, height / 1.2);

	//OUTRO BITMAP
	BITMAP *finalizar = load_bitmap("BITMAPS/Game/finalizar.bmp", NULL);
	BITMAP *finalizar_highlight = load_bitmap("BITMAPS/Game/finalizar_highlight.bmp", NULL);

	//Buttons
	Button *b_finalizar = create_button(finalizar, finalizar_highlight, click, width - 200, height / 9);

	inicia_timer(game->getTempoGam());
	int contadorPilha = 0;

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_abacaxi);
		button_input(b_banana);
		button_input(b_maca);
		button_input(b_laranja);
		button_input(b_caju);
		button_input(b_framboesa);
		button_input(b_abacate);
		button_input(b_morango);
		button_input(b_uva);
		button_input(b_melancia);

		button_input(b_finalizar);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Replique a pilha!");

		//TIMER
		textprintf_centre_ex(buffer, verdana, SCREEN_W / 2, SCREEN_H / 9, makecol(0, 0, 0), -1,
							 "%02d: %02d", (((getTimer() / 1000) / 60) % 60), ((getTimer() / 1000) % 60));

		//UPDATE
		if (((((getTimer() / 1000) % 60) == 0) && ((((getTimer() / 1000) / 60) % 60)) == 0) || b_finalizar->ativado)
		{
			exit_screen = true;
			*screen_state = FINALSCREEN;
			trava_timer();
		}

		//UPDATE DAS FRUTAS

		//ABACAXI
		verifica_botao(b_abacaxi, &(*j1), noh[0], &contadorPilha, height, 1);

		//BANANA
		verifica_botao(b_banana, &(*j1), noh[1], &contadorPilha, height, 80);

		//MACA
		verifica_botao(b_maca, &(*j1), noh[2], &contadorPilha, height, 160);

		//LARANJA
		verifica_botao(b_laranja, &(*j1), noh[3], &contadorPilha, height, 240);

		//CAJU
		verifica_botao(b_caju, &(*j1), noh[4], &contadorPilha, height, 320);

		//FRAMBOESA
		verifica_botao(b_framboesa, &(*j1), noh[5], &contadorPilha, height, 400);

		//ABACATE
		verifica_botao(b_abacate, &(*j1), noh[6], &contadorPilha, height, 480);

		//MORANGO
		verifica_botao(b_morango, &(*j1), noh[7], &contadorPilha, height, 560);

		//UVA
		verifica_botao(b_uva, &(*j1), noh[8], &contadorPilha, height, 640);

		//MELANCIA
		verifica_botao(b_melancia, &(*j1), noh[9], &contadorPilha, height, 720);

		//BUTTONS
		button_draw(b_abacaxi, buffer);
		button_draw(b_banana, buffer);
		button_draw(b_maca, buffer);
		button_draw(b_laranja, buffer);
		button_draw(b_caju, buffer);
		button_draw(b_framboesa, buffer);
		button_draw(b_abacate, buffer);
		button_draw(b_morango, buffer);
		button_draw(b_uva, buffer);
		button_draw(b_melancia, buffer);
		button_draw(b_finalizar, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}

	//BITMAPS
	destroy_bitmap(fruta_highlight);
	destroy_bitmap(abacaxi);
	destroy_bitmap(banana);
	destroy_bitmap(maca);
	destroy_bitmap(laranja);
	destroy_bitmap(caju);
	destroy_bitmap(framboesa);
	destroy_bitmap(abacate);
	destroy_bitmap(morango);
	destroy_bitmap(uva);
	destroy_bitmap(melancia);

	destroy_bitmap(finalizar_highlight);
	destroy_bitmap(finalizar);

	//BUTTONS
	destroy_button(b_abacaxi);
	destroy_button(b_banana);
	destroy_button(b_maca);
	destroy_button(b_laranja);
	destroy_button(b_caju);
	destroy_button(b_framboesa);
	destroy_button(b_abacate);
	destroy_button(b_morango);
	destroy_button(b_uva);
	destroy_button(b_melancia);

	destroy_button(b_finalizar);
}
END_OF_FUNCTION(game_screen)

void final_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogador *j1, Jogo *game)
{

	//BITMAPS
	BITMAP *irMenu = load_bitmap("BITMAPS/Final/irMenu.bmp", NULL);

	//BITMAPS(highlights)
	BITMAP *irMenu_highlight = load_bitmap("BITMAPS/Final/irMenu_highlight.bmp", NULL);

	//BUTTONS
	Button *b_irMenu = create_button(irMenu, irMenu_highlight, click, width / 2.5, height / 6);

	bool exit_screen = false;

	//Comparar pilhas
	int resultado = ComparaPilhas(P, j1->getPilha());

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_irMenu);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 10, 0x0, -1, "Voce acertou %d de %d", resultado, game->getQtdFrutas());

		textprintf_centre_ex(buffer, verdana, width / 2, height / 2.5, 0x0, -1, "Pilha correta:");
		textprintf_centre_ex(buffer, verdana, width / 2, height / 1.3, 0xfffffff, -1, "Pilha do %s:", j1->getNome().c_str());

		//IMPRESSAO DAS PILHAS
		imprimePILHA(P, buffer, width, height / 2, game->getQtdFrutas(), verdana);
		imprimePILHA(j1->getPilha(), buffer, width, height / 1.2, game->getQtdFrutas(), verdana);

		//UPDATE
		if (b_irMenu->ativado)
		{
			*screen_state = TITLESCREEN;
			exit_screen = true;
			P = LiberarPilha(P);
			j1->LPilha();
			delete j1;
			delete P;
		}

		//BUTTONS
		button_draw(b_irMenu, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}

	destroy_bitmap(irMenu);
	destroy_bitmap(irMenu_highlight);

	destroy_button(b_irMenu);
}
END_OF_FUNCTION(final_screen)

void final_screen_multi(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogador *j1, Jogador *j2, Jogo *game)
{

	//BITMAPS
	BITMAP *irMenu = load_bitmap("BITMAPS/Final/irMenu.bmp", NULL);

	//BITMAPS(highlights)
	BITMAP *irMenu_highlight = load_bitmap("BITMAPS/Final/irMenu_highlight.bmp", NULL);

	//BUTTONS
	Button *b_irMenu = create_button(irMenu, irMenu_highlight, click, width / 2.5, height / 8);

	bool exit_screen = false;

	//Comparar pilhas
	int resultado = ComparaPilhas(P, j1->getPilha());
	int resultado2 = ComparaPilhas(P, j2->getPilha());


	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_irMenu);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		if (resultado != resultado2)
		{
			textprintf_centre_ex(buffer, verdana, width / 2, height / 30, 0x0, -1, "O jogador vencedor foi: %s", resultado > resultado2 ? j1->getNome().c_str() : j2->getNome().c_str());
		}
		else
		{
			textprintf_centre_ex(buffer, verdana, width / 2, height / 30, 0x0, -1, "EMPATE! Ambos fizeram %d pontos", resultado);
		}
		textprintf_centre_ex(buffer, verdana, 640, 120, 0x0, -1, "Pilha correta:");
		textprintf_centre_ex(buffer, verdana, 640, 250, 0x0, -1, "Pilha do %s:", j1->getNome().c_str());
		textprintf_centre_ex(buffer, verdana, 640, height / 1.3, 0xfffffff, -1, "Pilha do %s:", j2->getNome().c_str());

		//IMPRESSAO DAS PILHAS
		imprimePILHA(P, buffer, width, 150, game->getQtdFrutas(), verdana);
		imprimePILHA(j1->getPilha(), buffer, width, 300, game->getQtdFrutas(), verdana);
		imprimePILHA(j2->getPilha(), buffer, width, 500, game->getQtdFrutas(), verdana);
		//UPDATE
		if (b_irMenu->ativado)
		{
			*screen_state = TITLESCREEN;
			exit_screen = true;
			P = LiberarPilha(P);
			j1->LPilha();
			j2->LPilha();
			delete j1;
			delete j2;
			delete P;
		}

		//BUTTONS
		button_draw(b_irMenu, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}

	destroy_bitmap(irMenu);
	destroy_bitmap(irMenu_highlight);

	destroy_button(b_irMenu);
}
END_OF_FUNCTION(final_screen)

void verifica_botao(Button *b1, Jogador *j1, No *noh, int *cont, int height, int dF)
{

	if (b1->ativado && b1)
	{

		b1->ativado = false;

		if (b1->pos_y == (500) && Empilhar(j1->getPilha(), noh))
		{
			change_pos_button(720 - ((*cont) * (80)), height / 2, b1);

			*cont += 1;
		}
		else
		{
			if (Desempilhar(j1->getPilha(), noh, false))
			{
				change_pos_button(dF, height / 1.2, b1);
				*cont -= 1;
			}
		}
	}
}
