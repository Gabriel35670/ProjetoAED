/* Tratamento de Sinais - Programa recebe um sinal SIGSEGV
Imprime uma mensagem quando um SIGSEGV é recebido e restabelece o tratador padrão.
Prof. Kelen 
September 2021 SO
DC/UFSCar
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void trata_SIGSEGV(int signum) {
	printf("Acesso indevido `a memória.\n");
	printf("Nao vou esconder este erro. :-)\n");
	signal(SIGSEGV, SIG_DFL);
	raise(SIGSEGV); /* equivale a kill(getpid(), SIGSEGV); */
}

int main() {
	signal(SIGSEGV, trata_SIGSEGV); //aaaaa


	int *px = (int*) 0x01010101;
	*px = 0;
	return 0;
}