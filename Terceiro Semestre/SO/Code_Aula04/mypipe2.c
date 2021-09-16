/* Exemplo de uso de pipes. O pai fala e o filho escuta, mas desta vez usando a entrada e saída padrão. 
Simula:   pai | filho
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

  pipe (mypipe);   /* Cria o pipe mypipe.
		      mypipe[0] - canal de leitura
		      mypipe[1] - canal de escrita			 
		   */
     
  if (fork() != 0) { /* Processo pai */
    if (dup2(mypipe[1], 1) == -1) 
      perror("dup2");
    printf("%s\n", str_pai); /* Processo pai escreve na saída padrão. */
  }
  else { /* Processo filho */
    if (dup2(mypipe[0], 0) == -1)
      perror("dup2");
    scanf("%s", str_filho); /* Processo filho lê da entrada padrão. */
    
    printf("Processo filho leu %ld caracteres: %s\n",
	  strlen(str_filho), str_filho);
  }

  close (mypipe[0]); /* Fecha canal de leitura */
  close (mypipe[1]); /* Fecha canal de escrita */
  
  return 0;
}
