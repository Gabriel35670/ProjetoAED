
all : main

main : main.o Pilha.o
	g++ main.o Pilha.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main

main.o : main.cpp Pilha.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp 

cinteiros.o : Pilha.cpp Pilha.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Pilha.cpp