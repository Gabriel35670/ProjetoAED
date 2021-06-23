#ifndef BUTTON_H_I
#define BUTTON_H_I

#include <allegro.h>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <iostream>

typedef struct button
{
  BITMAP* img;
  BITMAP* h_img;
  SAMPLE* h_click;

  int pos_x;
  int pos_y;

  int highlightON;
  int ativado;

  int bip;
}Button;


Button* create_button(BITMAP* image, BITMAP* h_image, SAMPLE* h_effect, int x, int y);
void button_input(Button* b);
void button_draw(Button* b, BITMAP* buffer);
void destroy_button(Button* b);
void change_pos_button(int x, int y,Button *b1);
void digita(std::string *n);


#endif // BUTTON_H_I
