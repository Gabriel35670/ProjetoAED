/*
Exemplo de uso de pipes. O pai fala e o filho escuta
Prof. Kelen 
September 2021 SO
DC/UFSCar
*/


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   
int  main (void) {
  int mypipe[2];
  char *str_pai = "Semana 4 - SO!";
  int nwrite = strlen(str_pai) + 1;
  char *str_filho = (char*) malloc(nwrite);
  int nread;
  pipe (mypipe);   /* Cria o pipe mypipe.
		      mypipe[0] - leitura
		      mypipe[1] - escrita			 
		   */
     
  if (fork() != 0) { /* Processo pai */
    nwrite = write(mypipe[1], str_pai, strlen(str_pai) + 1);
    printf("Processo pai escreveu %d caracteres: %s\n",
	   nwrite, str_pai);
  }
  else { /* Processo filho */
    nread = read(mypipe[0], str_filho, nwrite);
    printf("Processo filho leu %d caracteres: %s\n",
	   nread, str_filho);
  }

  close (mypipe[0]); /* Fecha canal de leitura */
  close (mypipe[1]); /* Fecha canal de escrita */
  
  return 0;
}
