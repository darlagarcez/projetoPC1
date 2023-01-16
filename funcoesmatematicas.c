#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

int validarcpf(char c_pf[]);
float mediap(float notas[],float pesos[], int tam);
float soma(float x, float y);
float subtracao(float x, float y);
float produto(float x, float y);
float divisao(float x, float y);

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

float mediap(float notas[],float pesos[], int tam)
{

}

float soma(float x, float y)
{
    return (x + y);
}

float subtracao(float x, float y)
{
    return (x - y);
}

float produto(float x, float y)
{
    return (x * y);
}

float divisao(float x, float y)
{
    return (x / y);
}