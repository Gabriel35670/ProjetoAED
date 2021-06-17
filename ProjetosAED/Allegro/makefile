all : main

main : main.o screen.o buttons/button.o  Jogador/Jogador.o timer/timer.o 
	g++ main.o screen.o buttons/button.o Jogador/Jogador.o timer/timer.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp screen.h buttons/button.h Jogador/Jogador.h timer/timer.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 

screen.o : screen.cpp screen.h buttons/button.h Jogador/Jogador.h timer/timer.h  
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c screen.cpp 

button.o : buttons/button.cpp buttons/button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c button.cpp 

Jogador.o: Jogador/Jogador.cpp Jogador/Jogador.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Jogador.cpp

timer.o: timer/timer.cpp timer/timer.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c timer.cpp


