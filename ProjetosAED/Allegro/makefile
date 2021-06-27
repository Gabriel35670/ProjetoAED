all : main

main : main.o screen.o buttons/button.o timer/timer.o Jogo.o Jogador.o Pilha.o No.o Fruta.o
	g++ main.o screen.o buttons/button.o timer/timer.o Jogo.o Jogador.o Pilha.o No.o Fruta.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp screen.h buttons/button.h timer/timer.h Jogo.h Jogador.h Pilha.h No.h Fruta.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 

screen.o : screen.cpp screen.h 
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c screen.cpp 

button.o : buttons/button.cpp buttons/button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c button.cpp 

timer.o: timer/timer.cpp timer/timer.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c timer.cpp

Jogo.o: Jogo.cpp Jogo.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Jogo.cpp

Jogador.o: Jogador.cpp Jogador.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Jogador.cpp

Pilha.o: Pilha.cpp Pilha.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Pilha.cpp

No.o: No.cpp No.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c No.cpp

Fruta.o: Fruta.cpp Fruta.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c Fruta.cpp



