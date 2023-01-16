all: main

main: menu.o usuarios.o pontos.o funcoesmatematicas.o main.o 
	gcc -o main main.o usuarios.o pontos.o funcoesmatematicas.o menu.o 

main.o: main.c 
	gcc -c main.c

funcoesmatematicas.o: funcoesmatematicas.c
	gcc -c funcoesmatematicas.c

pontos.o: pontos.c
	gcc -c pontos.c

usuarios.o: usuarios.c
	gcc -c usuarios.c 

menu.o: menu.c
	gcc -c menu.c 

clean:
	rm -rf *.o
