#ifndef TELAS_H
#define TELAS_H

#include "buttons/button.h"
#include "Jogador/Jogador.h"
#include "timer/timer.h"

void menu(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void single_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state,Jogador *j);
void multi_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void memory_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void game_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void final_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void config_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);

#endif


/*

gab04@Nootebook-Gabriel:~/Desktop/AED/Testes/Allegria$ g++ -Wall  main.cpp buttons/button.cpp buttons/button.h timer/timer.cpp timer/timer.h Jogador/Jogador.cpp Jogador/Jogador.h screen.cpp screen.h -o 1 `allegro-config --libs`

*/