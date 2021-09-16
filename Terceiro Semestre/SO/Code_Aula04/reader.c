/*
Programa em C para Fila de mensagem (Processo Reader) 
Prof. Kelen 
September 2021 SO
DC/UFSCar
*/

#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// estrutura para fila de mensagem 
struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	// ftok gera uma chave única 
	key = ftok("progfile", 65); 

	// msgget cria uma fila de mensagem e retorna um identificador
	msgid = msgget(key, 0666 | IPC_CREAT); 

	// msgrcv rebe uma messagem 
	msgrcv(msgid, &message, sizeof(message), 1, 0); 

	// mostra a mensagem 
	printf("A mensagem recebida é: %s \n", message.mesg_text); 

	// destroi a fila de mensagem 
	msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 
