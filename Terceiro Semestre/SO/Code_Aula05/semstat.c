/*****************************************************************************
 MODULE: semstat.c
A companion command line tool for the semtool package.  semstat displays the current value of all semaphores in the set created by semtool.
Fonte: Burkett(1995). Excerpt from "Linux Programmer's Guide: A command line tool for tinkering with SysV style Semaphore Sets
Prof. Kelen 
September 2020 SO
DC/UFSCar
*****************************************************************************/


#define _GNU_SOURCE 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>


#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
  /* a união semun é definida pela inclusão de <sys/sem.h> */
#else
   // de acordo com X/OPEN estrutura deve ser definida no programa
  union semun {
    int val;                     // valor para SETVAL 
     struct semid_ds *buf;       // buffer para IPC_STAT, IPC_SET 
     unsigned short int *array;  // vetor para GETALL, SETALL 
     struct seminfo *__buf;      // buffer para IPC_INFO 
  };
#endif

/* Estruturas de dados (definidas em sys/sem.h)
struct sembuf {
  ushort sem_num;
  short  sem_op;
  short  sem_flg;
}
union semun {
  int val;                    // value for SETVAL
  struct semid_ds *buf;       // buffer for IPC_STAT, IPC_SET
  unsigned short int *array;  // array for GETALL, SETALL
  struct seminfo *__buf;      // buffer for IPC_INFO
};
struct semid_ds {
  struct ipc_perm sem_perm;            // permissions .. see ipc.h 
  __kernel_time_t sem_otime;           // last semop time 
  __kernel_time_t sem_ctime;           // last change time 
  struct sem      *sem_base;           // ptr to first semaphore in array 
  struct sem_queue *sem_pending;       // pending operations to be processed 
  struct sem_queue **sem_pending_last; // last pending operation 
  struct sem_undo *undo;               // undo requests on this array 
  unsigned short  sem_nsems;           // no. of semaphores in array 
}
*/

/* prototipos */
/* int semctl (int semid, int semnum, int cmd, union semun arg) */
/* int semop (int semid, struct sembuf *sops, unsigned nsops) */
/* int semget (key_t key, int nsems, int semflg) */


int get_sem_count(int sid);
void show_sem_usage(int sid);
int get_sem_count(int sid);
void dispval(int sid);

int main(int argc, char *argv[])
{
        key_t key;
        int   semset_id;

        /* Create unique key via call to ftok() */
        key = ftok(".", 's');

        /* Open the semaphore set - do not create! */
        if((semset_id = semget(key, 1, 0666)) == -1) 
        {
                printf("Semaphore set does not exist\n");
                exit(1);
        }

        show_sem_usage(semset_id); 
        return(0);
}

void show_sem_usage(int sid)
{
        int cntr=0, maxsems, semval;

        maxsems = get_sem_count(sid);

        while(cntr < maxsems) {
                semval = semctl(sid, cntr, GETVAL, 0);
                printf("Semaphore #%d:  --> %d\n", cntr, semval);
                cntr++;
        }
}

int get_sem_count(int sid)
{
        int rc;
        struct semid_ds mysemds;
        union semun semopts;

        /* Get current values for internal data structure */
        semopts.buf = &mysemds;

        if((rc = semctl(sid, 0, IPC_STAT, semopts)) == -1) {
                perror("semctl");
                exit(1);
        }

        /* return number of semaphores in set */
        return(semopts.buf->sem_nsems);
}

void dispval(int sid)
{
        int semval;

        semval = semctl(sid, 0, GETVAL, 0);
        printf("semval is %d\n", semval);
}