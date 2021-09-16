#include "struct.h"

int criaArquivo(char *n_arq){

    FILE *arquivo = fopen(n_arq,"w+");


    if(arquivo == NULL){
        printf("Deu bo");
        return FALSE;
    }

    fclose(arquivo);
    return TRUE;
    
}

FILE* abre_arquivo(int m,char *n_arq){


    char metodo[1];

    if(m == 0)//metodo r

        metodo[0] = 'r';
    

    else if(m == 1)//metodo w

       metodo[0] = 'w';

    else//metodo a
      metodo[0] = 'a';

    FILE *arquivo;
    arquivo = fopen(n_arq,metodo);

    if(arquivo == NULL)

        return NULL;

    return arquivo;

    return NULL;
}

FILE* fecha_arquivo(FILE *arquivo){

    if(!fclose(arquivo))
        return NULL;

    printf("ERRO AO FECHAR O ARQUIVO, PROGRAMA ENCERRANDO\n");
    return NULL;
}

void escreve_arquivo(FILE *arquivo,Reg registro,int *posicao_final){

    char delimitador = '|';
    //Precisa estar em modo A/W
    int tamS1 = strlen(registro.nome);
    int tamS2 = strlen(registro.cpf);
    int tamS3 = strlen(registro.idade);

    fwrite(registro.nome,tamS1,1,arquivo);
    fwrite(&delimitador,sizeof(delimitador),1,arquivo);

    fwrite(registro.cpf,tamS2,1,arquivo);
    fwrite(&delimitador,sizeof(delimitador),1,arquivo);


    fwrite(registro.idade,tamS3,1,arquivo);
    fwrite(&delimitador,sizeof(delimitador),1,arquivo);
    char quebra_linha = '\n';
    fwrite(&quebra_linha,sizeof(quebra_linha),1,arquivo);

    *posicao_final = ftell(arquivo);
}

void le_arquivo(FILE *arquivo){

    //Arquivo necessariaente precisa estar em modo de leitura
    char c;
    char delimitador = '|';
    char nLina = '\n';

    while(!feof(arquivo)){
        c = fgetc(arquivo);
        if(c == delimitador)
            printf(" ");
        else if(c == nLina)
            printf("\n");
        else
            printf("%c",c);    
    }
}
