#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "usuarios.h"
#include "produtos.h"
#define MAX 10

int main()
{
    Usuario usuarios[MAX];
    int opcao;
    int retorno;

    limpar_tela();

    inicializacao(usuarios);

    do
    {
        puts("#####################################");
	    puts("#                                   #");											   
	    puts("#            SEBO ONLINE            #");				   
	    puts("#                                   #");									   
        puts("# ESCOLHA UMA ACAO:                 #");
	    puts("# 1 - LOGIN                         #");
	    puts("# 2 - SE CADASTRAR                  #");
	    puts("#                                   #");									   
        puts("#####################################");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            retorno = 0;
            limpar_tela();
            menu_Login(usuarios);
            break;

        case 2:
            retorno = 0;
            limpar_tela();
            adicionar_usuario(usuarios);
            break;

        default:
            retorno = 1;
            limpar_tela();
            puts("Operacao invalida!\nDigite novamente:\n");
            break;
        }
    } while (retorno != 0);

    finalizacao(usuarios);

    return 0;
}