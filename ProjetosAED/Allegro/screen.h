#ifndef TELAS_H
#define TELAS_H

#include "buttons/button.h"
#include "timer/timer.h"

#include "Jogo.h"

void menu(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game);
void single_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogador *j, Jogo *game);
void multi_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game, Jogador *j1, Jogador *j2);
void memory_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogo *game);
void game_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogador *j1, Jogo *game);
void final_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogador *j1, Jogo *game);
void final_screen_multi(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, PILHA *P, Jogador *j1, Jogador *j2, Jogo *game);
void config_screen(BITMAP *buffer, BITMAP *logo, BITMAP *cursor, FONT *verdana, SAMPLE *click, int height, int width, int *screen_state, Jogo *game);
void verifica_botao(Button *b1, Jogador *j1, No *noh, int *cont, int height, int dF);

#endif
