#ifndef SCREENfunct_H
#define SCREENfunct_H

#include "button.h"


void menu(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void single_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void multi_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void memory_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void game_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void final_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);
void config_screen(BITMAP *buffer,BITMAP *logo,BITMAP *cursor,FONT *verdana,SAMPLE *click,int height,int width,int *screen_state);

#endif