#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "produtos.h"
#define MAX 10

void inicializacao_Usuarios(Usuario usuarios[]);
void finalizacao_Usuarios(Usuario usuarios[]);
void inicializacao_Produtos(Usuario usuarios[]);
void finalizacao_Produtos(Usuario usuarios[]);
void adicionar_Produto(int idUsuario);
void remover_Produto(int idProduto);

void inicializacao_Usuarios(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
    int i;

    for (i = 0; i < MAX; i++)
    {
        usuarios[i].CPF = 0;
        strcpy(usuarios[i].nome, "0");
        strcpy(usuarios[i].ID, "0");
        usuarios[i].qtde_de_pontos = 0;
        strcpy(usuarios[i].senha, "0");
    }

    ponteiro_Arq = fopen("usuarios.txt", "r");

    // Passagem de dados do arquivo para o vetor de usuarios
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

void finalizacao_Usuarios(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
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

void inicializacao_Produtos(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
    int i, j;

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
    while (!feof(ponteiro_Arq))
    {
        char linha[500];
        char linhaSemPularLinha[500];

        fgets(linha, 500, ponteiro_Arq);
        strncpy(linhaSemPularLinha, linha, strlen(linha) - 1);

        const char virgula[2] = ",";
        char *token;

        char id[6], nome[50], autor[50];
        int ano, qtde_de_pontos;
        float nivel_de_qualidade;

        strcpy(id, strtok(linhaSemPularLinha, virgula));
        strcpy(nome, strtok(NULL, virgula));
        strcpy(autor, strtok(NULL, virgula));
        ano = atoi(strtok(NULL, virgula));
        qtde_de_pontos = atoi(strtok(NULL, virgula));
        nivel_de_qualidade = atof(strtok(NULL, virgula));

        char id_usuario[4];
        strncpy(id_usuario, id, 3);
        id_usuario[3] = '\0';

        i = 0;
        while (i < MAX)
        {
            if (strcmp(usuarios[i].ID, id_usuario) == 0)
            {
                j = 0;
                while (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                    j++;

                strcpy(usuarios[i].produtos[j].ID, id);
                strcpy(usuarios[i].produtos[j].nome, nome);
                strcpy(usuarios[i].produtos[j].autor, autor);
                usuarios[i].produtos[j].ano = ano;
                usuarios[i].produtos[j].qtde_de_pontos = qtde_de_pontos;
                usuarios[i].produtos[j].nivel_de_qualidade = nivel_de_qualidade;
                break;
            }
            i++;
        }

        free(token);
    }

    fclose(ponteiro_Arq);
}

void finalizacao_Produtos(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
    int i, j;

    ponteiro_Arq = fopen("produtos.txt", "w");

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < 20; j++)
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