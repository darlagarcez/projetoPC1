#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

#ifdef _WIN32
    #include <windows.h>
#elif _WIN32
    #include <windows.h>
#else

#endif

// DECLARACAO DE FUNCOES

void limpar_tela();
void gotoxy(int x, int y);
int validarcpf(char c_pf[]);
float mediap(float notas[],float pesos[], int tam);
float soma(float x, float y);
float subtracao(float x, float y);
float produto(float x, float y);
float divisao(float x, float y);

// FIM DAS DECLARACOES

// Funcao para limpar a tela
void limpar_tela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #else

    #endif
}

// Funcao para posicionar o cursor na tela
void gotoxy(int x, int y)
{
    #ifdef __linux__
        printf("%c[%d;%df",0x1B,y,x);
    #elif _WIN32
        COORD coord;
        coord.X = x - 1;
        coord.Y = y - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #elif _WIN64
        COORD coord;
        coord.X = x;
        coord.Y = y - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else

    #endif
}

// Funcao para validar o CPF
int validarcpf(char c_pf[])
{
    int i = 0;
    int ok_qtde = 1;
    int ok_pontuacao = 1;
    int ok_todos_numeros = 1;

    if (strlen(c_pf) != 14)
        ok_qtde = 1;
    else
    {
        ok_qtde = 0;

        if (c_pf[3] != '.' || c_pf[7] != '.' || c_pf[11] != '-')
            ok_pontuacao = 1;
        else
        {
            ok_pontuacao = 0;

            while (i < 14)
            {
                if (i == 3 || i == 7 || i == 11)
                    i++;
                else
                {
                    if (c_pf[i] <= '9' && c_pf[i] >= '0')
                        ok_todos_numeros = 0;
                    else
                        ok_todos_numeros = 1;

                    i++;
                }
            }
        }
    }

    if (ok_qtde == 0 && ok_pontuacao == 0 && ok_todos_numeros == 0)
        return 0;
    else
        return 1;
}

// Funcao para calcular a media ponderada
float mediap(float notas[],float pesos[], int tam)
{
    float media = 0.0;
    float soma_pesos = 0.0;

    for (int i = 0; i < tam; i++)
    {
        media = soma(media, produto(notas[i], pesos[i]));
        soma_pesos = soma(soma_pesos, pesos[i]);
    }

    return divisao(media, soma_pesos);
}

// Funcao para somar dois numeros
float soma(float x, float y)
{
    return (x + y);
}

// Funcao para subtrair dois numeros
float subtracao(float x, float y)
{
    return (x - y);
}

// Funcao para multiplicar dois numeros
float produto(float x, float y)
{
    return (x * y);
}

// Funcao para dividir dois numeros
float divisao(float x, float y)
{
    return (x / y);
}
