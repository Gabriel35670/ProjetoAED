#include <stdio.h>
#include <unistd.h>

int main(){

	int i=0;
	while(i < 10){
		printf("{%d}\n",i);
		i++;
	}
	write(STDOUT_FILENO,"Teste...1,2,3,...\n",19);

	return 0;
}
