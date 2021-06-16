all : main

<<<<<<< HEAD
main : main.o button.o screen.o
	g++ main.o button.o screen.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp button.h screen.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 


screen.o : screen.cpp screen.h button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c screen.cpp
	
=======
main : main.o button.o
	g++ main.o button.o -Wall -Werror -Werror=vla -pedantic-errors -g -lm -o main `allegro-config --libs` 

main.o : main.cpp button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c main.cpp `allegro-config --libs` 

>>>>>>> 24f98359048ea0fd5e3834a56de28e0ca5973f86
button.o : button.cpp button.h
	g++ -Wall -Werror -Werror=vla -pedantic-errors -g -lm -c button.cpp