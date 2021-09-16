#include "central.h"


int main(){

    arq registros;
    FILE *arquivo;
    double contador=0;
    int i=0;
    arquivo = fopen("arquivo.dat", "rb+"); // acesso de leitura
	if(arquivo == NULL)
		perror("Erro ao abrir dados.bin");
	else{
		// Varredura do arquivo
		while(fread(&registros,sizeof(arq),1,arquivo) == 1){

            printf("Tempo {%d} -> %lf\n",i,registros.tempo);												
			i += 1;
            contador += registros.tempo;
        }
	}

    double media_tempo = contador/i;
    printf("A media de tempo de criacao dos PROCESSOS foi %lf\n",media_tempo);

    fclose(arquivo);

    contador=0;
    i=0;
    arquivo = fopen("arquivo2.dat", "rb+"); // acesso de leitura
	if(arquivo == NULL)
		perror("Erro ao abrir arquivos2.dat");
	else{
		// Varredura do arquivo
		while(fread(&registros,sizeof(arq),1,arquivo) == 1){

            printf("Tempo {%d} -> %lf\n",i,registros.tempo);												
			i += 1;
            contador += registros.tempo;
        }
	}

    media_tempo = contador/i;
    printf("A media de tempo de criacao das THREADS foi %lf\n",media_tempo);

    fclose(arquivo);


    return 0;
}