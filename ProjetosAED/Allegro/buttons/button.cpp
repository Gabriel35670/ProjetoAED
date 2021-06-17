#include "button.h"

Button* create_button(BITMAP* image, BITMAP* h_image, SAMPLE* h_effect, int x, int y)
{
   Button* b = (Button*) malloc(sizeof(Button));

   b->img = image;
   b->h_img = h_image;
   b->h_click = h_effect;
   b->pos_x = x;
   b->pos_y = y;
   b->highlightON = FALSE;
   b->ativado = FALSE;
   b->bip = 0;

   return b;
}

void button_input(Button* b)
{
  if(mouse_x > b->pos_x && mouse_x < b->pos_x + b->img->w
  && mouse_y > b->pos_y && mouse_y < b->pos_y + b->img->h
  && getpixel(b->img, mouse_x - b->pos_x, mouse_y - b->pos_y) != makecol(255,0,255))
  {
    b->highlightON = TRUE;
    b->bip++;

    if(b->bip == 1)
     play_sample(b->h_click, 255, 128, 1000, FALSE);

    if(mouse_b == 1)
    {
       mouse_b = 0;

       if(b->ativado == TRUE)
        b->ativado = FALSE;
       else
        b->ativado = TRUE;
    }

  }
  else
  {
    b->highlightON = FALSE;
    b->bip = 0;
  }
}

void button_update(Button* b)
{
  if(b->ativado)
  {

  }
}


void button_draw(Button* b, BITMAP* buffer)
{
    draw_sprite(buffer,  b->img, b->pos_x,  b->pos_y);

    if(b->highlightON)
       draw_sprite(buffer,  b->h_img, b->pos_x,  b->pos_y);
}


void destroy_button(Button* b)
{
    free(b);
}
