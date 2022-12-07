#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define MAX 10

void limpar_tela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}

void inicializacao(Usuario usuarios[])
{
    FILE* ponteiro_Arq;
    int i;

    for (i = 0; i < MAX; i++)
    {
        usuarios[i].CPF = 0;
        strcpy(usuarios[i].nome, "\0");
        strcpy(usuarios[i].ID, "\0");
        usuarios[i].qtde_de_pontos = 0;
        strcpy(usuarios[i].senha, "\0");
    }

    ponteiro_Arq = fopen("usuarios.txt", "r");

    for (i = 0; i < MAX; i++)
    {
        fscanf(ponteiro_Arq, "ID: %s\n", usuarios[i].ID);
        fscanf(ponteiro_Arq, "CPF: %d\n", &usuarios[i].CPF);
        fscanf(ponteiro_Arq, "Nome: %s\n", usuarios[i].nome);
        fscanf(ponteiro_Arq, "Senha: %s\n", usuarios[i].senha);
        fscanf(ponteiro_Arq, "Quantidade de pontos: %d\n", &usuarios[i].qtde_de_pontos);
    }

    fclose(ponteiro_Arq);
}

void menu_Login(Usuario usuarios[])
{
    int CPF_Login;
    char SENHA_Login[20];
    int i;
    int retorno = 1;

    do
    {
        puts("#####################################");
	    puts("");											   
	    puts("               LOGIN");				   
	    puts("");
	    printf("      CPF: ");
	    scanf("%d", &CPF_Login);
        getchar();
	    printf("      SENHA: ");
        scanf("%s", SENHA_Login);
        puts("");
        puts("#####################################");

        for (i = 0; i < MAX || retorno == 0; i++)
        {
            if (usuarios[i].CPF == CPF_Login && strcmp(usuarios[i].senha, SENHA_Login) == 0)
            {
                retorno = 0;
            }
        }
        if (retorno == 1)
        {
            limpar_tela();
            puts("CPF e/ou senha invalidos!\nPor favor, tente novamente\n");
        }
        
    } while (retorno != 0);

    limpar_tela();
    puts("Login realizado com sucesso!\nBEM VINDO(A)!\n");
    puts("Pressione qualquer tecla para continuar...");
    getchar();
}

void menu_Acoes(Usuario usuarios[])
{
    int opcao, opcao2;

    limpar_tela();

    do
    {
        puts("#####################################");
	    puts("#                                   #");											   
	    puts("#            SEBO ONLINE            #");				   
	    puts("#                                   #");									   
        puts("# ESCOLHA UMA ACAO:                 #");
	    puts("# 1 - EXIBIR USUARIOS               #");
	    puts("# 2 - EXIBIR PRODUTOS               #");
	    puts("# 3 - SAIR                          #");
	    puts("#                                   #");									   
        puts("#####################################");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            puts("#####################################");
	        puts("#                                   #");											   
	        puts("#            SEBO ONLINE            #");				   
	        puts("#                                   #");									   
            puts("# EXIBIR USUARIOS:                  #");
	        puts("# 1 - LISTA DE USUARIOS             #");
	        puts("# 2 - USUARIO PELO CPF              #");
	        puts("# 3 - USUARIO PELO NOME             #");
	        puts("#                                   #");									   
            puts("#####################################");
            printf("Opcao: ");
            scanf("%d", &opcao2);

            switch (opcao2)
            {
            case 1:
                exibir_Usuarios(usuarios);
                break;
            
            default:
                break;
            }
            break;

        case 2:
            break;

        default:
            break;
        }
    } while (opcao != 3);
}

void exibir_Usuarios(Usuario usuarios[])
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF != 0)
        {
            puts("-------------------------------------");
            puts("");
            printf("%s\n", usuarios[i].nome);
            puts("");
            printf("%d\n", usuarios[i].qtde_de_pontos);
            puts("");
            puts("-------------------------------------");
            puts("");
        }
    }
    
}

void finalizacao(Usuario usuarios[])
{
    FILE* ponteiro_Arq;
    int i;

    ponteiro_Arq = fopen("usuarios.txt", "w");

    for (i = 0; i < MAX; i++)
    {
        fprintf(ponteiro_Arq, "ID: %s\n", usuarios[i].ID);
        fprintf(ponteiro_Arq, "CPF: %d\n", usuarios[i].CPF);
        fprintf(ponteiro_Arq, "Nome: %s\n", usuarios[i].nome);
        fprintf(ponteiro_Arq, "Senha: %s\n", usuarios[i].senha);
        fprintf(ponteiro_Arq, "Quantidade de pontos: %d\n", usuarios[i].qtde_de_pontos);

        fputc('\n', ponteiro_Arq);
    }

    fclose(ponteiro_Arq);
}