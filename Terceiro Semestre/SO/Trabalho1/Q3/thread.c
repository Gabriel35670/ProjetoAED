#include "central.h"
/*
Gabriel Meireles Carvalho Orlando-790728-Ciência Da Computação
Pedro Gonçalves dos Santos-794042-Ciência Da Computação
*/

void* estrutura(void *arg){

    sleep(10);
    pthread_exit(0);

    return NULL;
}

pthread_t tid[500];

int main(void)
{
    int i = 0;
    int err,err2;
    clock_t tempo;

    tempo = clock();
    while(i < 500)
    {
        err = pthread_create(&(tid[i]), NULL, &estrutura, NULL);

        if (err != 0)
            i = 5000;
        i++;
    }
    printf("threads criadas\n");
    tempo = clock() - tempo;
    printf("Tempo de execucao: %lf segundos\n", ((double)tempo)/((CLOCKS_PER_SEC/1000)));

    printf("FInalizando as tarefas\n");

    //Finalizando as threads
    int j=0;
    while(j < 500)
    {
        err2 = pthread_join(tid[j],NULL);

        if (err2 != 0)
            i = 5000;
        j++;
    }
    if(j == 500)
        printf("Todas as threads foram terminadas\n");

    FILE *arquivo = fopen("arquivo2.dat","ab+");
    double t = ((double)tempo)/((CLOCKS_PER_SEC/1000));
    arq tempos;
    tempos.tempo = t;

    fwrite(&tempos , 1 , sizeof(arq) , arquivo );
    fclose(arquivo);

 
    
    return 0;
}