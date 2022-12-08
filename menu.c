#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "usuarios.h"
#define MAX 10

void limpar_tela();
void inicializacao(Usuario usuarios[]);
void menu_Login(Usuario usuarios[]);
void menu_Acoes(Usuario usuarios[]);
void exibir_Usuarios(Usuario usuarios[]);
void perfil_Usuario(Usuario usuarios[], int cpf);
void finalizacao(Usuario usuarios[]);

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
    inicializacao_Usuarios(usuarios);
    inicializacao_Produtos(usuarios);
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
        getchar();
        puts("");
        puts("#####################################");

        for (i = 0; i < MAX || retorno != 0; i++)
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
    perfil_Usuario(usuarios, CPF_Login);
    puts("Pressione qualquer tecla para continuar...");
    getchar();
    menu_Acoes(usuarios);
}

void menu_Acoes(Usuario usuarios[])
{
    int opcao, opcao2;
    int CPF_usuario;

    limpar_tela();

    do
    {
        puts("#####################################");
	    puts("#                                   #");											   
	    puts("#            SEBO ONLINE            #");				   
	    puts("#                                   #");									   
        puts("# ESCOLHA UMA ACAO:                 #");
	    puts("# 1 - COMPRAR PRODUTO               #");
	    puts("# 2 - ADICONAR PRODUTO              #");
	    puts("# 3 - EXIBIR USUARIOS               #");
	    puts("# 4 - EXIBIR PRODUTOS               #");
	    puts("# 5 - SAIR                          #");
	    puts("#                                   #");									   
        puts("#####################################");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 3:
            limpar_tela();
            puts("#####################################");
	        puts("#                                   #");											   
	        puts("#            SEBO ONLINE            #");				   
	        puts("#                                   #");									   
            puts("# EXIBIR USUARIOS:                  #");
	        puts("# 1 - LISTA DE USUARIOS             #");
	        puts("# 2 - USUARIO PELO CPF              #");
	        puts("#                                   #");									   
            puts("#####################################");
            printf("Opcao: ");
            scanf("%d", &opcao2);

            switch (opcao2)
            {
            case 1:
                limpar_tela();
                exibir_Usuarios(usuarios);
                break;
            
            case 2:
                limpar_tela();
                printf("Digite o CPF do usuario: ");
                scanf("%d", &CPF_usuario);
                perfil_Usuario(usuarios, CPF_usuario);
                getchar();
                puts("Pressione qualquer tecla para continuar...");
                getchar();
                break;

            default:
                limpar_tela();
                puts("Opcao invalida!");
                getchar();
                puts("Pressione qualquer tecla para continuar...");
                getchar();
                break;
            }
            break;

        case 2:
            break;

        case 5:
            limpar_tela();
            puts("Programa finalizado!");
            break;
        
        default:
            puts("Opcao invalida!\nPor favor, digite novamente:\n");
            break;
        }
    } while (opcao != 5);
}

void exibir_Usuarios(Usuario usuarios[])
{
    int i, j;

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF != 0)
        {
            puts("-------------------------------------");
            puts("");
            printf("%s\n", usuarios[i].nome);
            puts("");
            printf("Quantidade de pontos: %d\n", usuarios[i].qtde_de_pontos);
            puts("");
            puts("Produtos:");
            for (j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf("%s ", usuarios[i].produtos[j].ID);
                }
            }
            puts("");
            puts("-------------------------------------");
            puts("");
        }
    }
    getchar();
    puts("Pressione qualquer tecla para continuar...");
    getchar();
}

void perfil_Usuario(Usuario usuarios[], int cpf)
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF == cpf)
        {
            puts("-------------------------------------");
            puts("");
            printf("%s\n", usuarios[i].nome);
            puts("");
            printf("Quantidade de pontos: %d\n", usuarios[i].qtde_de_pontos);
            puts("");
            puts("-------------------------------------");
            puts("");
        }
    }
}

void finalizacao(Usuario usuarios[])
{   
    finalizacao_Usuarios(usuarios);
    finalizacao_Produtos(usuarios);
}