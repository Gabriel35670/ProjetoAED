#include "struct.h"


int main(){


    char *n_arq = "arquivo.txt";

    int valor;
    printf("Digite sua opcao:\n\n1)Criar/Resetar arquivo\n2)Continuar arquivo\n");
    scanf("%d",&valor);
    printf("\n\n");

    if(valor == 1){
        int valor = criaArquivo(n_arq);

        if(!valor)
            return 0;
    }

    //r=0,w=1,a= qlqr outro valor
    int metodo = 3;
    FILE *arq = abre_arquivo(metodo,n_arq);

    if(arq == NULL) return 0;

    Reg registro;

    sleep(5);

    registro.idade = "18";
    registro.nome = "Gabriel_Orlando";
    registro.cpf = "416-408-348-42";

    int pos;

    Reg registro2,registro3;

    registro2.idade = "17";
    registro2.nome = "Felipe Orlando";
    registro2.cpf = "435-996-354-X";


    registro3.idade = "54";
    registro3.nome = "Claudia Meirelles";
    registro3.cpf = "659-115-418-13";

    escreve_arquivo(arq,registro,&pos);
    escreve_arquivo(arq,registro2,&pos);
    escreve_arquivo(arq,registro3,&pos);

    
    arq = fecha_arquivo(arq);


    arq = abre_arquivo(0,n_arq);
    le_arquivo(arq);

    arq = fecha_arquivo(arq);


    
   
    return 0;
}