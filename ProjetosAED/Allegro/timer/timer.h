#ifndef TEMPINHO_H
#define TEMPINHO_H

#include <time.h>
#include <allegro.h>
#include <iostream>

void inicia_timer(int tempSeq);

void decrementa_timer();

volatile int getTimer();

void trava_timer();

#endif