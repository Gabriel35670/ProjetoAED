#include "screen.h"

//screen.h

enum
{
	TITLESCREEN,
	SSCREEN,
	MSCREEN,
	MEMORYSCREEN,
	GAMESCREEN,
	FINALSCREEN,
	CONFIGSCREEN,
	OUT
};

//Feito
void menu(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game)
{

	BITMAP *single, *single_highlight, *multi, *multi_highlight, *config, *config_highlight;
	Button *b_single, *b_multi, *b_config;

	//BITMAPS
	single = load_bitmap("BITMAPS/Tittle/Single.bmp", NULL);
	single_highlight = load_bitmap("BITMAPS/Tittle/Single_Highlight.bmp", NULL);

	multi = load_bitmap("BITMAPS/Tittle/Multi.bmp", NULL);
	multi_highlight = load_bitmap("BITMAPS/Tittle/Multi_Highlight.bmp", NULL);

	config = load_bitmap("BITMAPS/Tittle/Config.bmp", NULL);
	config_highlight = load_bitmap("BITMAPS/Tittle/Config_Highlight.bmp", NULL);

	//BUTTONS
	b_single = create_button(single, single_highlight, click, 90, height / 1.3);
	b_multi = create_button(multi, multi_highlight, click, 90, height / 1.2);
	b_config = create_button(config, config_highlight, click, 90, height / 1.1);

	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_single);
		button_input(b_multi);
		button_input(b_config);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Jogo da Memoria");

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

		//BUTTONS
		button_draw(b_single, buffer);
		button_draw(b_multi, buffer);
		button_draw(b_config, buffer);

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

	BITMAP *nome, *voltar, *voltar_highlight, *start, *start_highlight;
	Button *b_start, *b_voltar;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
	voltar_highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);

	start = load_bitmap("BITMAPS/Single/start.bmp", NULL);
	start_highlight = load_bitmap("BITMAPS/Single/start_highlight.bmp", NULL);

	nome = load_bitmap("BITMAPS/Single/nome.bmp", NULL);

	//BUTTONS
	b_start = create_button(start, start_highlight, click, width / 1.2, height / 1.2);
	b_voltar = create_button(voltar, voltar_highlight, click, width / 12, height / 11.5);

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_start);
		button_input(b_voltar);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//BITMAPS
		draw_sprite(buffer, nome, width / 6, height / 3);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Single screen");
		textprintf_centre_ex(buffer, verdana, width / 2.7, height / 2.9, 0x0, -1, "%s", j->getNome().c_str());
		//UPDATE
		if (b_start->ativado)
		{
			exit_screen = true;
			*screen_state = MEMORYSCREEN;
		}
		else if (b_voltar->ativado)
		{
			b_voltar->ativado = false;
			exit_screen = true;
			*screen_state = TITLESCREEN;
			j->controlaCont(1);
			delete j;
		}

		//BUTTONS
		button_draw(b_start, buffer);
		button_draw(b_voltar, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}
	destroy_bitmap(voltar_highlight);
	destroy_bitmap(voltar);
	destroy_bitmap(nome);
	destroy_bitmap(start);
	destroy_bitmap(start_highlight);

	destroy_button(b_start);
	destroy_button(b_voltar);
}
END_OF_FUNCTION(single_screen)

//Verificar como realizar
void multi_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game)
{

	bool exit_screen = false;

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "MULTI SCREEN");

		//UPDATE

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
END_OF_FUNCTION(multi_screen)

//Ultima coisa
void config_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game)
{
	string dificuldade[] = {"Facil", "Medio", "Dificil"};
	int i = 0;

	BITMAP *setaDireitaFrutas, *setaEsquerdaFrutas, *setaDireitaDificuldade, *setaEsquerdaDificuldade, *highlight, *voltar, *highlightDireitaFrutas, *highlightEsquerdaFrutas, *highlightDireitaDificuldade, *highlightEsquerdaDificuldade;
	Button *bSetaDireitaFrutas, *bSetaEsquerdaFrutas, *bSetaDireitaDificuldade, *bSetaEsquerdaDificuldade, *b_voltar;

	bool exit_screen = false;

	//BITMAPS
	voltar = load_bitmap("BITMAPS/Single/voltar.bmp", NULL);
	setaDireitaFrutas = load_bitmap("BITMAPS/Single/setaDireita.bmp", NULL);
	setaEsquerdaFrutas = load_bitmap("BITMAPS/Single/setaEsquerda.bmp", NULL);
	setaDireitaDificuldade = load_bitmap("BITMAPS/Single/setaDireita.bmp", NULL);
	setaEsquerdaDificuldade = load_bitmap("BITMAPS/Single/setaEsquerda.bmp", NULL);
	highlight = load_bitmap("BITMAPS/Single/voltar_highlight.bmp", NULL);
	highlightDireitaFrutas = load_bitmap("BITMAPS/Single/highlightDireita.bmp", NULL);
	highlightEsquerdaFrutas = load_bitmap("BITMAPS/Single/highlightEsquerda.bmp", NULL);
	highlightDireitaDificuldade = load_bitmap("BITMAPS/Single/highlightDireita.bmp", NULL);
	highlightEsquerdaDificuldade = load_bitmap("BITMAPS/Single/highlightEsquerda.bmp", NULL);

	b_voltar = create_button(voltar, highlight, click, width / 20, height / 22);
	bSetaDireitaFrutas = create_button(setaDireitaFrutas, highlightDireitaFrutas, click, width / 1.45, height / 7);
	bSetaEsquerdaFrutas = create_button(setaEsquerdaFrutas, highlightEsquerdaFrutas, click, width / 2, height / 7);
	bSetaDireitaDificuldade = create_button(setaDireitaDificuldade, highlightDireitaDificuldade, click, width / 1.42, height / 3.5);
	bSetaEsquerdaDificuldade = create_button(setaEsquerdaDificuldade, highlightEsquerdaDificuldade, click, width / 2, height / 3.5);

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
		textprintf_centre_ex(buffer, verdana, width / 1.5, height / 3, 0x0, -1,"%s", game->getDificuldade().c_str());

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
	/*
	BITMAP *setaDireitaFrutas, *setaEsquerdaFrutas, *setaDireitaDificuldade, *setaEsquerdaDificuldade, *highlight, *voltar, *highlightDireitaFrutas, 
	*highlightEsquerdaFrutas, *highlightDireitaDificuldade, *highlightEsquerdaDificuldade;
	Button *bSetaDireitaFrutas, *bSetaEsquerdaFrutas, *bSetaDireitaDificuldade, *bSetaEsquerdaDificuldade, *b_voltar;
	*/
	destroy_bitmap(setaDireitaFrutas);
	destroy_bitmap(setaEsquerdaFrutas);
	destroy_bitmap(setaDireitaDificuldade);
	destroy_bitmap(setaEsquerdaDificuldade);
	destroy_bitmap(highlight);
	destroy_bitmap(voltar);
	destroy_bitmap(highlightDireitaFrutas);
	destroy_bitmap(highlightEsquerdaFrutas);
	destroy_bitmap(highlightEsquerdaDificuldade);
	destroy_bitmap(highlightDireitaDificuldade);

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
	//P = CriarPilha(10);
	game->embaralha(P);

	//int tamanho = P1->tamanhoMAX;

	inicia_timer(game->getTempoSeq());
	//int controle = getTimer();

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Pilha Correta, memorize a ordem!");

		//TIMER
		textprintf_centre_ex(buffer, verdana, SCREEN_W / 2, SCREEN_H / 9, makecol(0, 0, 0), -1,
							 "%02d: %02d", (((getTimer() / 1000) / 60) % 60), ((getTimer() / 1000) % 60));

		//BITMAPS
		imprimePILHA(P, buffer, width, height);

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
		verifica_botao(b_maca,&(*j1), noh[2], &contadorPilha, height, 160);

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
	BITMAP *sair = load_bitmap("BITMAPS/Final/sair.bmp", NULL);

	//BITMAPS(highlights)
	BITMAP *sair_highlight = load_bitmap("BITMAPS/Final/sair_highlight.bmp", NULL);

	//BUTTONS
	Button *b_sair = create_button(sair, sair_highlight, click, width / 2.5, height / 8);

	bool exit_screen = false;

	//Comparar pilhas
	int resultado = ComparaPilhas(P, j1->getPilha());

	while (!(key[KEY_ESC] || exit_screen))
	{

		//Botoes iniciados
		button_input(b_sair);

		//Tela de fundo
		draw_sprite(buffer, logo, 0, 0);

		//Titulo do jogo
		textprintf_centre_ex(buffer, verdana, width / 2, height / 12, 0x0, -1, "Tela final");
		textprintf_centre_ex(buffer, verdana, width / 2, height / 10, 0x0, -1, "Voce acertou %d de %d", resultado,game->getQtdFrutas());

		textprintf_centre_ex(buffer, verdana, width / 2, height / 3, 0x0, -1, "Pilha correta:");
		textprintf_centre_ex(buffer, verdana, width / 2, height / 1.3, 0xfffffff, -1, "Pilha do %s:", j1->getNome().c_str());

		//IMPRESSAO DAS PILHAS
		imprimePILHA(P, buffer, width, height);
		imprimePILHA(j1->getPilha(), buffer, width, height, 1);

		//UPDATE
		if (b_sair->ativado)
		{
			*screen_state = OUT;
			exit_screen = true;
			P = LiberarPilha(P);
			j1->LPilha();
		}

		//BUTTONS
		button_draw(b_sair, buffer);

		//MOUSE
		draw_sprite(buffer, cursor, mouse_x - 6, mouse_y - 6);

		//BUFFER
		draw_sprite(screen, buffer, 0, 0);

		//RESTO
		rest(10);
		clear(buffer);
	}

	destroy_bitmap(sair);
	destroy_bitmap(sair_highlight);

	destroy_button(b_sair);
}
END_OF_FUNCTION(final_screen)

void verifica_botao(Button *b1, Jogador *j1, No *noh, int *cont, int height, int dF)
{

	if (b1->ativado && b1)
	{

		b1->ativado = false;

		if (b1->pos_y == (500) && Empilhar(j1->getPilha(), noh))
		{
			change_pos_button(720 -((*cont)*(80)),height/2,b1);

			*cont += 1;
		}
		else
		{
			if (Desempilhar(j1->getPilha(), noh, false))
			{
				change_pos_button(dF,height/1.2,b1);
				*cont -= 1;
			}
		}
	}
}

//Fruta.cpp
string getFileName(string n)
{

	//File names
	string v[10] = {"Pilha/F/abacaxi.bmp", "Pilha/F/banana.bmp", "Pilha/F/maca.bmp", "Pilha/F/laranja.bmp", "Pilha/F/caju.bmp",
					"Pilha/F/framboesa.bmp", "Pilha/F/abacate.bmp", "Pilha/F/morango.bmp", "Pilha/F/uva.bmp", "Pilha/F/melancia.bmp"};

	string v2[10] = {"abacaxi", "banana", "maca", "laranja", "caju", "framboesa", "abacate", "morango", "uva", "melancia"};

	int pos = 0;
	bool achou = false;

	while (pos < 10 && !achou)
	{
		if (n == v2[pos])
			achou = true;
		pos++;
	}
	pos -= 1;
	return v[pos];
}

fruta *criaFruta(string n)
{

	fruta *novaFruta = new fruta;

	novaFruta->nome = n;
	string file_name = getFileName(n);
	novaFruta->img = load_bitmap(file_name.c_str(), NULL);

	return novaFruta;
}

bool igual(fruta *f1, fruta *f2)
{

	if (f1->nome == f2->nome)
		return true;
	return false;
}

vector<fruta *> vet_frutas(int x)
{

	string v[10] = {"abacaxi", "banana", "maca", "laranja", "caju", "framboesa", "abacate", "morango", "uva", "melancia"};

	vector<fruta *> frutas;

	fruta *aux;

	for (int i = 0; i < x; i++)
	{

		aux = criaFruta(v[i]);

		frutas.push_back(aux);
	}

	return frutas;
}

//No.cpp
No *criaNo(fruta *fruta)
{

	No *N;
	N = new No;

	N->proximo = NULL;
	N->f = fruta;

	return N;
}

No *LiberaNo(No *X)
{

	delete X;

	return X;
}

//Pilha.cpp

PILHA *CriarPilha(int tamanhoMAX)
{

	PILHA *P = new PILHA;
	P->tamanhoMAX = tamanhoMAX;
	P->topo = NULL;

	return P;
}
bool Cheia(PILHA *P)
{

	int contador = 0;
	No *aux = P->topo;
	while (aux != NULL)
	{
		aux = aux->proximo;
		contador++;
	}

	return contador == P->tamanhoMAX;
}

bool Vazia(PILHA *P)
{

	return P->topo == NULL;
}

bool Empilhar(PILHA *P, No *novo)
{

	if (Cheia(P) || novo == NULL)
	{
		return false;
	}
	else
	{
		if (Vazia(P))
		{
			novo->proximo = NULL;
			P->topo = novo;
		}
		else
		{
			No *aux;
			aux = P->topo;
			P->topo = novo;
			P->topo->proximo = aux;
		}
	}
	return true;
}

bool Desempilhar(PILHA *P, No *X, bool acabou)
{

	if (Vazia(P))
	{
		return false;
	}
	if (acabou && P->topo == X)
	{
		No *lixo;

		X->f = P->topo->f;
		lixo = P->topo;
		P->topo = P->topo->proximo;
		lixo = LiberaNo(lixo);

		return true;
	}
	else
	{
		if (P->topo == X)
		{
			X->f = P->topo->f;
			P->topo = P->topo->proximo;
			return true;
		}
	}

	return false;
}

int ComparaPilhas(PILHA *P1, PILHA *P2)
{

	int igualdades = 0;

	No *N1 = P1->topo;
	No *N2 = P2->topo;

	while (N1 != NULL && N2 != NULL)
	{

		if (igual(N1->f, N2->f))
		{

			igualdades++;
		}
		N1 = N1->proximo;
		N2 = N2->proximo;
	}

	return igualdades;
}
void imprimePILHA(PILHA *P, BITMAP *buffer, int width, int height, int jeito)
{

	No *aux;
	aux = P->topo;

	double contador = 0;
	if (!jeito)
	{
		while (aux != NULL)
		{

			draw_sprite(buffer, aux->f->img, 1 + (80 * contador), height / 2);
			contador += 1;
			aux = aux->proximo;
		}
	}
	else
	{
		while (aux != NULL)
		{

			draw_sprite(buffer, aux->f->img, 1 + (80 * contador), height / 1.2);
			contador += 1;
			aux = aux->proximo;
		}
	}
}
PILHA *LiberarPilha(PILHA *P)
{

	if (!Vazia(P))
	{
		No *proxNode,
			*atual;

		atual = P->topo;
		while (atual != NULL)
		{
			proxNode = atual->proximo;
			delete atual;
			atual = proxNode;
		}
		P->topo = NULL;
	}

	return P;
}

//Jogador.cpp

int Jogador::contador = 0;

Jogador::Jogador(string nome, int t)
{

	setNome(nome);
	this->P = CriarPilha(t);
	pontuacao = 0;
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

string Jogador::getNome() const
{
	return nome;
}

void Jogador::controlaCont(int x)
{
	this->contador -= x;
}

bool Jogador::JogadorEmpilha(No *n)
{

	if (Empilhar(this->P, n))
		return true;
	return false;
}

PILHA *Jogador::getPilha()
{
	return this->P;
}

void Jogador::LPilha()
{

	this->P = LiberarPilha(this->P);
}
//Jogo.cpp

Jogo::Jogo(int tempoSeq, int tempoGam, int qtdFrutas, string difi)
{
	setQtdFrutas(qtdFrutas);
	setTempoSeq(tempoSeq);
	setTempoGam(tempoGam);
	setDificuldade(difi);
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

void Jogo::setQtdFrutas(int frutas)
{
	if (frutas <= 0)
	{
		cout << "Quantidade de frutas inválida" << endl;
	}
	else if (frutas > 10)
	{
		cout << "Quantidade máxima de frutas atingida" << endl;
	}
	else
	{
		qtdFrutas = frutas;
	}
}

void Jogo::setDificuldade(string difi)
{
	if (difi == "Facil" || difi == "Medio" || difi == "Dificil")
	{
		dificuldade = difi;
	}
	else
	{
		cout << "Dificuldade inválida";
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

int Jogo::getQtdFrutas() const
{
	return qtdFrutas;
}

string Jogo::getDificuldade() const
{
	return dificuldade;
}

void Jogo::embaralha(PILHA *P)
{
	vector<fruta *> frutas;

	frutas = vet_frutas(qtdFrutas);
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
