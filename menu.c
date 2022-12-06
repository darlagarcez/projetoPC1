#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

void inicializacao()
{
    inicializacao_Usuarios();
}

void menu()
{
    int opcao;

    do
    {
        puts("#####################################");
	    puts("");											   
	    puts("\t\t\tSEBO ONLINE");				   
	    puts("");									   
        puts("ESCOLHA UMA ACAO:");
	    puts("1 - LOGIN");
	    puts("2 - SE CADASTRAR");
	    puts("3 - SAIR");
	    puts("");									   
        puts("#####################################");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //menu_Login();
            break;
        
        case 2:
            //menu_Cadastro();
            break;

        default:
            puts("Operacao invalida!\nDigite novamente:\n");
            break;
        }
    } while (opcao != 3);
}

void finalizacao()
{
    finalizacao_Usuarios();
}