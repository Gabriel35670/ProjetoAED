#include "timer.h"

volatile int timer = 0;

void decrementa_timer()
{
    timer--;
}

void inicia_timer(int tempSeq)
{
    timer = tempSeq;
    LOCK_FUNCTION(decrementa_timer);
    LOCK_VARIABLE(timer);
    install_int_ex(decrementa_timer, MSEC_TO_TIMER(1));
}

volatile int getTimer()
{

    return timer;
}

void trava_timer()
{

    timer = 0;
}
