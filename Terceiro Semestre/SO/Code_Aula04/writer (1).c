/*
Programa em C para Fila de mensagem (Processo Writer) 
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
	message.mesg_type = 1; 

	printf("Dados Escritos: "); 
	fgets(message.mesg_text,200,stdin); 

	// msgsnd envia uma mensagem 
	msgsnd(msgid, &message, sizeof(message), 0); 

	// mostra a mensagem 
	printf("A mensagem enviada é : %s \n", message.mesg_text); 

	return 0; 
} 
