#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 6
#define READ 0
#define WRITE 1
int main(){
     pid_t pid1, pid2, pid3, pid4; 
     int status;
     int fd[2]; 
    char buffer[SIZE+1];

    struct rusage usage;

     pipe(fd);
     if ((pid1=fork())==0) { 
            while(1) {
                 read(fd[READ], buffer, SIZE);
                 buffer[SIZE]='\0';
                 write(fd[WRITE], "SO", SIZE);
            }
       } else if ((pid2=fork())==0) { 
             while(1) {
                    read(fd[READ], buffer, 6);
                    buffer[6]='\0';
                    write(fd[WRITE], "turnip", 6);
               }
       } else { // parent
                write(fd[WRITE],"SO",6);
                fprintf(stderr,"Parent: I wrote SO!\n", buffer);
               sleep(3);
               read(fd[READ], buffer, 6); buffer[6]='\0';
               fprintf(stderr,"Parent: I got back a %s!\n", buffer);
               kill(pid1, SIGINT); pid3 = wait(&status, 0, &usage);
               kill(pid2, SIGINT); pid4 = wait(&status, 0, &usage);
        }
}