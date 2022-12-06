#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define MAX 10

void inicializacao_Usuarios()
{
    FILE* ponteiro_Arq;
    Usuario user[MAX];

    for (int i = 0; i < MAX; i++)
    {
        user[i].CPF = 0;
        strcpy(user[i].nome, '\0');
        strcpy(user[i].ID, '\0');
        user[i].qtde_de_pontos = 0;
        strcpy(user[i].senha, '\0');
        
        for (int j = 0; i < 20; j++)
        {
            user[i].produtos[j] = 0;
        }
    }

    ponteiro_Arq = fopen("usuarios.txt", "w");

    for(int i = 0; i < 5; i++)
    {
        fprintf(ponteiro_Arq, "ID: %s\n", user[i].ID);
        fprintf(ponteiro_Arq, "CPF: %d\n", &user[i].CPF);
        fprintf(ponteiro_Arq, "Nome: %s\n", user[i].nome);
        fprintf(ponteiro_Arq, "Senha: %s\n", user[i].senha);
        fprintf(ponteiro_Arq, "Quantidade de pontos: %d\n", &user[i].qtde_de_pontos);

        for (int j = 0; ponteiro_Arq != '\n'; j++)
        {
            fprintf(ponteiro_Arq, "%d ", &user[i].produtos[j]);
        }
 
    }

    fclose(ponteiro_Arq);
}

void finalizacao_Usuarios()
{
    FILE* ponteiro_Arq;
    Usuario user[MAX];
    int TAM = 0;

    ponteiro_Arq = fopen("usuarios.txt", "r");

    for(int i = 0; i < 5; i++)
    {
        fprintf(ponteiro_Arq, "ID: %s\n", user[i].ID);
        fprintf(ponteiro_Arq, "CPF: %d\n", user[i].CPF);
        fprintf(ponteiro_Arq, "Nome: %s\n", user[i].nome);
        fprintf(ponteiro_Arq, "Senha: %s\n", user[i].senha);
        fprintf(ponteiro_Arq, "Quantidade de pontos: %d\n", user[i].qtde_de_pontos);

        for (int j = 0; j < 20; j++)
        {
            fprintf(ponteiro_Arq, "%d ", user[i].produtos[j]);
        }

        fputc('\n', ponteiro_Arq);
    }

    fclose(ponteiro_Arq);
}