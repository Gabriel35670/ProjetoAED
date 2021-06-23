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

void change_pos_button(int x, int y,Button *b1){

    b1->pos_x = x;
    b1->pos_y = y;

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

using namespace std;

void digita(string *n){
    string letra;
    bool apaga = false;

    if(key[KEY_A]){

        key[KEY_A] = false;
        letra = "a";
    }

    if(key[KEY_B]){
        key[KEY_B] = false;
        letra = "b";
    }

    if(key[KEY_C]){
        key[KEY_C] = false;
        letra = "c";
    }

    if(key[KEY_D]){
        letra = "d";
        key[KEY_D] = false;
    }
    if(key[KEY_E]){
        letra = "e";
        key[KEY_E] = false;
    }
    if(key[KEY_F]){
        letra = "f";
        key[KEY_F] = false;
    }
    if(key[KEY_G]){
        letra = "g";
        key[KEY_G] = false;
    }
    if(key[KEY_H]){
        letra = "h";
        key[KEY_H] = false;
    }
    if(key[KEY_I]){
        letra = "i";
        key[KEY_I] = false;
    }
    if(key[KEY_J]){
        letra = "j";
        key[KEY_J] = false;
    }
    if(key[KEY_K]){
        letra = "k";
        key[KEY_K] = false;
    }
    if(key[KEY_L]){
        letra = "l";
        key[KEY_L] = false;
    }

    if(key[KEY_M]){
        letra = "m";
        key[KEY_M] = false;
    }
    if(key[KEY_N]){
        letra = "n";
        key[KEY_N] = false;
    }
    if(key[KEY_O]){
        letra = "o";
        key[KEY_O] = false;
    }
    if(key[KEY_P]){
        letra = "p";
        key[KEY_P] = false;
    }
    if(key[KEY_Q]){
        letra = "q";
        key[KEY_Q] = false;
    }
    if(key[KEY_R]){
        letra = "r";
        key[KEY_R] = false;
    }
    if(key[KEY_S]){
        letra = "s";
        key[KEY_S] = false;
    }
    if(key[KEY_T]){
        letra = "t";
        key[KEY_T] = false;
    }
    if(key[KEY_U]){
        letra = "u";
        key[KEY_U] = false;
    }
    if(key[KEY_V]){
        letra = "v";
        key[KEY_V] = false;
    }
    if(key[KEY_W]){
        letra = "w";
        key[KEY_W] = false;
    }
    if(key[KEY_X]){
        letra = "x";
        key[KEY_X] = false;
    }
    if(key[KEY_Y]){
        letra = "y";
        key[KEY_Y] = false;
    }
    if(key[KEY_Z]){
        letra = "z";
        key[KEY_Z] = false;
    }
    if(key[KEY_BACKSPACE] && n->length() > 0){
        key[KEY_BACKSPACE] = false;
        apaga = true;
    }
    if(key[KEY_1] || key[KEY_1_PAD]){
        letra = "1";
        key[KEY_1] = false;
        key[KEY_1_PAD] = false;
    }

    if(key[KEY_2] || key[KEY_2_PAD]){
        letra = "2";
        key[KEY_2] = false;
        key[KEY_2_PAD] = false;
    }
    if(key[KEY_3] || key[KEY_3_PAD]){
        letra = "3";
        key[KEY_3] = false;
        key[KEY_3_PAD] = false;
    }
    if(key[KEY_4] || key[KEY_4_PAD]){
        letra = "4";
        key[KEY_4] = false;
        key[KEY_4_PAD] = false;
    }
    if(key[KEY_5] || key[KEY_5_PAD]){
        letra = "5";
        key[KEY_5] = false;
        key[KEY_5_PAD] = false;
    }
    if(key[KEY_6] || key[KEY_6_PAD]){
        letra = "6";
        key[KEY_6] = false;
        key[KEY_6_PAD] = false;
    }
    if(key[KEY_7] || key[KEY_7_PAD]){
        letra = "7";
        key[KEY_7] = false;
        key[KEY_7_PAD] = false;
    }
    if(key[KEY_9] || key[KEY_9_PAD]){
        letra = "9";
        key[KEY_9] = false;
        key[KEY_9_PAD] = false;
    }
    if(key[KEY_0] || key[KEY_0_PAD]){
        letra = "0";
        key[KEY_0] = false;
        key[KEY_0_PAD] = false;
    }
    if(key[KEY_8] || key[KEY_8_PAD]){
        letra = "8";
        key[KEY_8] = false;
        key[KEY_8_PAD] = false;
    }
     if(key[KEY_SPACE] && n->length() < 19){
        letra = " ";
        key[KEY_SPACE] = false;
    }
    /*
    Oque falta adicionar -> todos os touchpads
    */
    if(!apaga && n->length() < 20)
        *n += letra;
    else if(apaga)
        n->pop_back();  
        
}

