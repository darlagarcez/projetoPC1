#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "produtos.h"
#define MAX 10

void inicializacao_Produtos(Usuario usuarios[]);
void finalizacao_Produtos(Usuario usuarios[]);

void inicializacao_Produtos(Usuario usuarios[])
{
    FILE* ponteiro_Arq;
    int i, j;
    char ID_para_comparacao[6];

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < 20; j++)
        {
            strcpy(usuarios[i].produtos[j].ID, "0");
            strcpy(usuarios[i].produtos[j].nome, "0");
            strcpy(usuarios[i].produtos[j].autor, "0");
            usuarios[i].produtos[j].ano = 0;
            usuarios[i].produtos[j].qtde_de_pontos = 0;
            usuarios[i].produtos[j].nivel_de_qualidade = 0.0;
        }
    }

    ponteiro_Arq = fopen("produtos.txt", "r");

    // Passagem de dados do arquivo para o vetor de produtos dentro de usuarios
    for (i = 0; i < MAX; i++)
    {
        rewind(ponteiro_Arq);
        j = 0;

        while (!(feof(ponteiro_Arq)))
        {
            fscanf(ponteiro_Arq, "ID: %s\n", ID_para_comparacao);

            if (strncmp(usuarios[i].ID, usuarios[i].produtos[j].ID, 3) == 0)
            {
                strcpy(usuarios[i].produtos[j].ID, ID_para_comparacao);
                fscanf(ponteiro_Arq, "Nome: %s\n", usuarios[i].produtos[j].nome);
                fscanf(ponteiro_Arq, "Autor(a): %s\n", usuarios[i].produtos[j].autor);
                fscanf(ponteiro_Arq, "Ano: %d\n", &usuarios[i].produtos[j].ano);
                fscanf(ponteiro_Arq, "Quantidade de pontos: %d\n", &usuarios[i].qtde_de_pontos);
                fscanf(ponteiro_Arq, "Nivel de qualidade: %f\n", &usuarios[i].produtos[j].nivel_de_qualidade);

                j++;
            }
        }
    }

    fclose(ponteiro_Arq);
}

void finalizacao_Produtos(Usuario usuarios[])
{
    FILE* ponteiro_Arq;
    int i, j;

    ponteiro_Arq = fopen("produtos.txt", "w");

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < 20 ; j++)
        {
            if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
            {
                fprintf(ponteiro_Arq, "ID: %s\n", usuarios[i].produtos[j].ID);
                fprintf(ponteiro_Arq, "Nome: %s\n", usuarios[i].produtos[j].nome);
                fprintf(ponteiro_Arq, "Autor(a): %s\n", usuarios[i].produtos[j].autor);
                fprintf(ponteiro_Arq, "Ano: %d\n", usuarios[i].produtos[j].ano);
                fprintf(ponteiro_Arq, "Quantidade de pontos: %d\n", usuarios[i].qtde_de_pontos);
                fprintf(ponteiro_Arq, "Nivel de qualidade: %f\n", usuarios[i].produtos[j].nivel_de_qualidade);
            }
        }
        fputc('\n', ponteiro_Arq);
    }

    fclose(ponteiro_Arq);
}