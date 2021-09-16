/* 
Prof. Kelen 
September 2021 SO
DC/UFSCar
*/

#include <stdio.h>
#include <stdlib.h>
     
int main (void) {
  FILE *output;
  int i=0;
  
  output = popen ("more", "w");
  if (!output) {
    fprintf (stderr, "erro em popen.\n");
    return EXIT_FAILURE;
  }
  
  while(1)
    fprintf(output, "%d: Teste para popen ()\n", i++);

  return 0;
}
