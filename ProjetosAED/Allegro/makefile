all : main

main : main.o button.o screen.o
	g++ main.o button.o screen.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp button.h screen.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 


screen.o : screen.cpp screen.h button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c screen.cpp
	
button.o : button.cpp button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c button.cpp