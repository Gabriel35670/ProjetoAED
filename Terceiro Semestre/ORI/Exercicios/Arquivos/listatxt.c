/*
  Listagem de dados no formato "nome valor empresa" de arquivo texto,
  com nome e empresa sem espacos (substituidos por sublinha).
  Jander, 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 500
#define TRUE 1
#define FALSE 0

typedef struct vetor
{
	char nome[40];
	char empresa[40];
	float fortuna;

}Registros;


int main(){
	FILE *arquivo;
	
	Registros r[TAM_MAX];


	arquivo = fopen("dados.txt", "r+"); // acesso de leitura
	if(arquivo == NULL)
		perror("Erro ao abrir dados.txt");
	else{
		int i=0;
		// Varredura do arquivo, linha a linha
		while(fscanf(arquivo, "%s%f%s", r[i].nome, &r[i].fortuna, r[i].empresa) != EOF){
			if()
			i++;-

		}

		int opcao = TRUE;
		int numero;
		while(opcao == TRUE){

			printf("Opcoes:\n1)Digite 1 para verificar um registro n\n2)Digite 0 para sair\n");
			scanf("%d",&opcao);
			if(opcao == TRUE){
				printf("\nDigite o numero de um registro(0 a %d): ",i-1);
				scanf("%d",&numero);
				printf("\n---------------------Registro numero %d---------------------\n\n",numero);
				printf("%s, com US$ %g bi (%s)\n\n", r[numero].nome, r[numero].fortuna, r[numero].empresa);
				printf("---------------------------------------------------------------\n\n");
			}

		}
		fclose(arquivo);
	}

	return 0;
}
