#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "usuarios.h"
#define MAX 10

#ifdef _WIN32
    #include <windows.h>
#else

#endif

void limpar_tela();
void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int x, int y);
void inicializacao(Usuario usuarios[]);
void menu_Login(Usuario usuarios[]);
void menu_Acoes(Usuario usuarios[]);
void exibir_Usuarios(Usuario usuarios[]);
void perfil_Usuario(Usuario usuarios[], int cpf);
void exibir_produtos(Usuario usuarios[]);
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

void limpar_tela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}

void gotoxy(int x,int y)
{
    #ifdef __linux__
        printf("%c[%d;%df",0x1B,y,x);
    #elif _WIN32
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else

    #endif
}

void pausar_tela(int x, int y)
{
    #ifdef __linux__
        getchar();
        gotoxy(x,y);
        printf("Pressione qualquer tecla para continuar...");
        getchar();
    #elif _WIN32
        system("pause");
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
    int retorno = 1;

    do
    {
        limpar_tela();
        gotoxy(10,2);
        puts("LOGIN");
        gotoxy(5,4);
        puts("USUARIO: ");
        gotoxy(5,5);
        puts("SENHA: ");
        gotoxy(14,4);
        scanf("%d", &CPF_Login);
        getchar();
        gotoxy(13,5);
        scanf("%s", SENHA_Login);

        for (int i = 0; i < MAX || retorno != 0; i++)
        {
            if (usuarios[i].CPF == CPF_Login && strcmp(usuarios[i].senha, SENHA_Login) == 0)
                retorno = 0;
        }
        if (retorno == 1)
        {
            limpar_tela();
            gotoxy(5,2);
            puts("USUARIO OU SENHA INVALIDOS!");
            gotoxy(5,3);
            puts("POR FAVOR, TENTE NOVAMENTE");
            pausar_tela(5,5);
        }
        
    } while (retorno != 0);

    limpar_tela();
    gotoxy(10,2);
    puts("LOGIN REALIZADO COM SUCESSO");
    gotoxy(10,3);
    puts("BEM VINDO(A)!");
    perfil_Usuario(usuarios, CPF_Login);
    menu_Acoes(usuarios);
}

void menu_Acoes(Usuario usuarios[])
{
    int opcao, opcao2;
    int CPF_usuario;

    do
    {	
        limpar_tela();
        gotoxy(10,2);
	    puts("SEBO ONLINE");
        gotoxy(5,4);
        puts("ESCOLHA UMA ACAO:");
        gotoxy(5,5);
	    puts("1 - Comprar produto");
        gotoxy(5,6);
	    puts("2 - Adicionar produto");
        gotoxy(5,7);
	    puts("3 - Exibir usuarios");
        gotoxy(5,8);
	    puts("4 - Exibir produtos");
        gotoxy(5,9);
	    puts("5 - Sair");
        gotoxy(5,11);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 3:
            limpar_tela();
            gotoxy(10,2);
	        puts("SEBO ONLINE");
            gotoxy(5,4);
            puts("EXIBIR USUARIOS:");
            gotoxy(5,5);
	        puts("1 - Lista de usuarios");
            gotoxy(5,7);
	        puts("2 - Usuario pelo CPF");
            gotoxy(5,9);
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
                gotoxy(10,2);
                puts("Digite o CPF do usuario: ");
                scanf("%d", &CPF_usuario);
                perfil_Usuario(usuarios, CPF_usuario);
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

        case 4:
            limpar_tela();
            exibir_produtos(usuarios);
            limpar_tela();
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

    puts("-------------------------------------");

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF != 0)
        {
            puts("");
            printf("%s%20d\n", usuarios[i].nome, usuarios[i].qtde_de_pontos);
            puts("");
            puts("Produtos:");
            for (j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf("%s ", usuarios[i].produtos[j].nome);
                }
            }
            puts("\n");
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
    int i, j;

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF == cpf)
        {
            limpar_tela();
            gotoxy(5,5);
            printf("%s", usuarios[i].nome);
            gotoxy(30,5);
            printf("%d", usuarios[i].qtde_de_pontos);
            gotoxy(5,7);
            puts("Produtos:");
            gotoxy(5,8);
            for (j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                    printf("%s ", usuarios[i].produtos[j].nome);
            }
        }
    }

    pausar_tela(5,10);
}

void exibir_produtos(Usuario usuarios[])
{
    int i, j;

    puts("-------------------------------------");

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF != 0)
        {
            
            for (j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf("Titulo: %s\t\t\tPontos: %d\n", usuarios[i].produtos[j].nome,
                    usuarios[i].produtos[j].qtde_de_pontos);
                    printf("Autor: %s\t\t\tAno: %d\n", usuarios[i].produtos[j].autor,
                    usuarios[i].produtos[j].ano);
                    printf("ID para a compra: %s", usuarios[i].produtos[j].ID);
                    puts("\n");
                    puts("-------------------------------------");
                    puts("");
                }
            }
        }
    }
    getchar();
    puts("Pressione qualquer tecla para continuar...");
    getchar();
}

void finalizacao(Usuario usuarios[])
{   
    finalizacao_Usuarios(usuarios);
    finalizacao_Produtos(usuarios);
}