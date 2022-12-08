all: main

main: menu.o usuarios.o main.o 
	gcc -o main main.o usuarios.o menu.o 

main.o: main.c 
	gcc -c main.c 

usuarios.o: usuarios.c
	gcc -c usuarios.c 

menu.o: menu.c
	gcc -c menu.c 

clean:
	rm -rf *.o
