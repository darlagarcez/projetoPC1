all: main

main: menu.o usuarios.o main.o 
	gcc -o main main.o usuarios.o menu.o

main.o: main.c 
	gcc -c main.c -W -Wall -ansi -pedantic

usuarios.o: usuarios.c
	gcc -c usuarios.c -W -Wall -ansi -pedantic

menu.o: menu.c
	gcc -c menu.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
