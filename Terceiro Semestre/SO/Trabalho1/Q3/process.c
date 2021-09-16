#include "central.h"
/*
Gabriel Meireles Carvalho Orlando-790728-Ciência Da Computação
Pedro Gonçalves dos Santos-794042-Ciência Da Computação

*/

int main(int argc,char  *argv[]){

    pid_t iPid;
    int i=0;
    clock_t tempo;

    tempo = clock();

    while(i < 500){
        iPid = fork();

        if(iPid == 0){

            sleep(10);
            exit(0);
        }
        

        if (iPid < 0){

        perror("Mensagem de erro\n");
        exit(errno);
        }


        i++;
    }


    if(i == 500){
        tempo = clock() - tempo;
        printf("Tempo de execucao: %lf segundos\n", ((double)tempo)/((CLOCKS_PER_SEC/1000)));
    }

    FILE *arquivo = fopen("arquivo.dat","ab+");
    double t = ((double)tempo)/((CLOCKS_PER_SEC/1000));
    arq tempos;
    tempos.tempo = t;

    fwrite(&tempos , 1 , sizeof(arq) , arquivo );
    fclose(arquivo);






    return 0;

}