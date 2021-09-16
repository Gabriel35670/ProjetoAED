/*
  Listagem de dados com "nome valor empresa" de arquivo binario,
  com nome e empresa sem espacos (substituidos por sublinha). nome
  e empresa contem 40 caraceres com terminacao '\0'; valor no 
  formato IEEE 754 de precisao simples (float).
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
	float fortuna;
	char empresa[40];

}Registros;

int main(){
	FILE *arquivo;
	Registros r[TAM_MAX];

	arquivo = fopen("dados.bin", "rb+"); // acesso de leitura
	if(arquivo == NULL)
		perror("Erro ao abrir dados.bin");
	else{
		// Varredura do arquivo
		int i=0;
		while(fread(&r[i],sizeof(Registros),1,arquivo) == 1){														
			
			if(i == 9){
				r[i].fortuna = 47.5;
				fseek(arquivo,-sizeof(Registros),SEEK_CUR);
				fwrite(&r[i],sizeof(Registros),1,arquivo);
			}
			i += 1;
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
