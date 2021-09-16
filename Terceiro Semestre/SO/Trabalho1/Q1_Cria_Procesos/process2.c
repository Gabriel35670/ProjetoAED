#include "central.h"
/*
Gabriel Meireles Carvalho Orlando-790728-Ciência Da Computação
Pedro Gonçalves dos Santos-794042-Ciência Da Computação
*/

int main(int argc,char  *argv[]){

    pid_t iPid;
    int i=0;

    while(1){

        iPid = fork();

        if(iPid == 0){

            sleep(10);
            exit(0);
        }
        
        printf("%d\n",i);
        if(errno){

        perror("Mensagem de erro\n");
        exit(0);
        }


        i++;
    }
    return 0;

}