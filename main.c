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
    int retorno = -1;

    limpar_tela();

    inicializacao(usuarios);

    do
    {
        limpar_tela();
        gotoxy(10,2);
        puts("ESCOLHA UMA ACAO: ");
        gotoxy(5,4);
        puts("1 - Login");
        gotoxy(5,5);
        puts("2 - Cadastro");
        gotoxy(5,7);
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
            gotoxy(10,2);
            puts("OPCAO INVALIDA!");
            pausar_tela(5,4);
            break;
        }
    } while (retorno != 0);

    finalizacao(usuarios);

    return 0;
}