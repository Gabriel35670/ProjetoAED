#include "timer.h"

volatile int timer=0;

void incremeta_timer(){
    timer++;
}

void inicia_timer(){

    LOCK_FUNCTION(incrementa_timer);
	LOCK_VARIABLE(timer);
	install_int_ex(incremeta_timer, MSEC_TO_TIMER(1));

}   

volatile int getTimer(){

    return timer;
}

void trava_timer(){

    timer =0;
}
