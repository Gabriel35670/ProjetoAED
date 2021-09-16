/* Sobrescrever o comportamento padrão de um sinal (signal handler).
Prof. Kelen 
September 2021 SO
DC/UFSCar
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// handler for common signals that terminate process
static void end_handler(int signal) {
    printf("Não foi desta vez!\nAinda estou vivo!! :)\n");
}

int main(int argc, char *argv[]) {
    // set handlers
    if ((signal(SIGINT, end_handler) == SIG_ERR) || (signal(SIGHUP, end_handler) ==  
            SIG_ERR) || (signal(SIGTERM, end_handler) == SIG_ERR)) {
        printf("Error while setting a signal handler\n");
        exit(EXIT_FAILURE);
    }   
    while (1) { } // infinite loop
    return 0;  
}