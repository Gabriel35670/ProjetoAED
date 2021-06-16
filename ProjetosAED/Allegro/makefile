all : main

main : main.o button.o
	g++ main.o button.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 

button.o : button.cpp button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c button.cpp