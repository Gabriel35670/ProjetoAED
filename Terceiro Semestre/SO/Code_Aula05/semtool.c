/*****************************************************************************
Exemplo de uso das chamadas de sistemas para semáforos 
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
#include <ctype.h>


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


#define SEM_RESOURCE_MAX        1       /* Inicializa o valor de todos os semaforos*/

void opensem(int *sid, key_t key);
void createsem(int *sid, key_t key, int members);
void locksem(int sid, int member);
void unlocksem(int sid, int member);
void removesem(int sid);
unsigned short get_member_count(int sid);
int getval(int sid, int member);
void dispval(int sid, int member);
void changemode(int sid, char *mode);
void usage(void);

int main(int argc, char *argv[])
{
        key_t key;
        int   semset_id;

        if(argc == 1)
                usage();

        /* Create unique key via call to ftok() */
        key = ftok(".", 's');

        switch(tolower(argv[1][0]))
        {
                case 'c': if(argc != 3)
                                usage();
                          createsem(&semset_id, key,  atoi(argv[2]));
                          break;
                case 'l': if(argc != 3)
                                usage();
                          opensem(&semset_id, key);
                          locksem(semset_id, atoi(argv[2]));
                          break;
                case 'u': if(argc != 3)
                                usage();
                          opensem(&semset_id, key);
                          unlocksem(semset_id, atoi(argv[2]));
                          break;
                case 'd': opensem(&semset_id, key);
                          removesem(semset_id);
                          break;        
                case 'm': opensem(&semset_id, key);
                          changemode(semset_id, argv[2]);
                          break;        
                 default: usage();

        }
        
        return(0);
}

void opensem(int *sid, key_t key)
{
        /* Open the semaphore set - do not create! */

        if((*sid = semget(key, 0, 0666)) == -1) 
        {
                printf("Conjunto de semaforo não existe!\n");
                exit(1);
        }

}

void createsem(int *sid, key_t key, int members)
{
        int cntr;
        union semun semopts;
        //if(members > SEMMSL) {
        //        printf("Sorry, max number of semaphores in a set is %d\n",SEMMSL);
        //        exit(1);
        //}
        printf("Attempting to create new semaphore set with %d members\n", members);

        if((*sid = semget(key, members, IPC_CREAT|IPC_EXCL|0666))
                        == -1) 
        {
                fprintf(stderr, "Conjunto de semaforo já existe!\n");
                exit(1);
        }

        semopts.val = SEM_RESOURCE_MAX;
        
        /* Initialize all members (could be done with SETALL) */        
        for(cntr=0; cntr<members; cntr++)
                semctl(*sid, cntr, SETVAL, semopts);
}

void locksem(int sid, int member)
{
        struct sembuf sem_lock={ 0, -1, IPC_NOWAIT};

        if( member<0 || member>(get_member_count(sid)-1))
        {
                fprintf(stderr, "semaphore member %d out of range\n", member);
                return;
        }

        /* Attempt to lock the semaphore set */
        if(!getval(sid, member))
        {
                fprintf(stderr, "Recursos do semaforo esgotados (no lock)!\n");
                exit(1);
        }
        
        sem_lock.sem_num = member;
        
        if((semop(sid, &sem_lock, 1)) == -1)
        {
                fprintf(stderr, "Lock failed\n");
                exit(1);
        }
        else
                printf("Recursos do Semaforo decrementados por 1 (locked)\n");

        dispval(sid, member);
}

void unlocksem(int sid, int member)
{
        struct sembuf sem_unlock={ member, 1, IPC_NOWAIT};
        int semval;

        if( member<0 || member>(get_member_count(sid)-1))
        {
                fprintf(stderr, "semaphore member %d out of range\n", member);
                return;
        }

        /* Is the semaphore set locked? */
        semval = getval(sid, member);
        if(semval == SEM_RESOURCE_MAX) {
                fprintf(stderr, "Semaforo não bloqueado!\n");
                exit(1);
        }

        sem_unlock.sem_num = member;

        /* Attempt to lock the semaphore set */
        if((semop(sid, &sem_unlock, 1)) == -1)
        {
                fprintf(stderr, "Unlock failed\n");
                exit(1);
        }
        else
                printf("Recursos do Semaforo incrementados por 1 (unlocked)\n");

        dispval(sid, member);
}

void removesem(int sid)
{
        semctl(sid, 0, IPC_RMID, 0);
        printf("Semáforo removido\n");
}

unsigned short get_member_count(int sid)
{
        union semun semopts;
        struct semid_ds mysemds;
        semopts.buf = &mysemds;

        /* Retorna o número de membros em um conjunto de semáforos */
        return(semopts.buf->sem_nsems);
}

int getval(int sid, int member)
{
        int semval;
        semval = semctl(sid, member, GETVAL, 0);
        return(semval);
}

/* As permissões necessárias devem ser passadas como texto (ex: "660") */
void changemode(int sid, char *mode)
{
        int rc;
        union semun semopts;
        struct semid_ds mysemds;

         /* Obtenha os valores atuais para a estrutura de dados interna */
        semopts.buf = &mysemds;

        rc = semctl(sid, 0, IPC_STAT, semopts);

        if (rc == -1) {
                perror("semctl");
                exit(1);
        }
                
        printf("As permissões eram  %o\n", semopts.buf->sem_perm.mode);
                
        /* Altere as permissões no semáforo */
        sscanf(mode, "%o", &semopts.buf->sem_perm.mode);

        /* Atualize a estrutura de dados interna */
        semctl(sid, 0, IPC_SET, semopts);

        printf("Atualizado...\n");

}

void dispval(int sid, int member)
{
        int semval;
        semval = semctl(sid, member, GETVAL, 0);
        printf("semval para membros %d é %d\n", member, semval);
}

void usage(void)
{
        fprintf(stderr, "semtool - A utility for tinkering with semaphores\n");
        fprintf(stderr, "\nUSAGE:  semtool4 (c)reate <semcount>\n");
        fprintf(stderr, "                 (l)ock <sem #>\n");
        fprintf(stderr, "                 (u)nlock <sem #>\n");
        fprintf(stderr, "                 (d)elete\n");
        fprintf(stderr, "                 (m)ode <mode>\n");
        exit(1);
}