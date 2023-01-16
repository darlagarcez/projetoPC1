#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "produtos.h"
#include "pontos.h"
#define MAX 10

void inicializacao_Usuarios(Usuario usuarios[]);
void finalizacao_Usuarios(Usuario usuarios[]);
void inicializacao_Produtos(Usuario usuarios[]);
void finalizacao_Produtos(Usuario usuarios[]);
void excluir_usuario(Usuario usuarios[], char idUsuario[]);
void adicionar_Produto(Usuario usuarios[], char idUsuario[]);
void comprar_produto(Usuario usuarios[], char idUsuario[], char idProduto[]);
void remover_Produto(Usuario usuarios[], char idUsuario[], char idProduto[]);

void inicializacao_Usuarios(Usuario usuarios[])
{
    FILE *ponteiro_Arq;

    for (int i = 0; i < MAX; i++)
    {
        usuarios[i].CPF = 0;
        strcpy(usuarios[i].nome, "0");
        strcpy(usuarios[i].sobrenome, "0");
        strcpy(usuarios[i].ID, "0");
        usuarios[i].qtde_de_pontos = 0;
        strcpy(usuarios[i].senha, "0");
    }

    ponteiro_Arq = fopen("usuarios.txt", "r");

    // Passagem de dados do arquivo para o vetor de usuarios
    for (int i = 0; i < MAX; i++)
    {
        fscanf(ponteiro_Arq, "ID: %s\n", usuarios[i].ID);
        fscanf(ponteiro_Arq, "CPF: %d\n", &usuarios[i].CPF);
        fscanf(ponteiro_Arq, "Nome: %s\n", usuarios[i].nome);
        fscanf(ponteiro_Arq, "Sobrenome: %s\n", usuarios[i].sobrenome);
        fscanf(ponteiro_Arq, "Senha: %s\n", usuarios[i].senha);
        fscanf(ponteiro_Arq, "Quantidade de pontos: %d\n", &usuarios[i].qtde_de_pontos);
    }

    fclose(ponteiro_Arq);
}

void finalizacao_Usuarios(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
    ponteiro_Arq = fopen("usuarios.txt", "w");

    for (int i = 0; i < MAX; i++)
    {
        fprintf(ponteiro_Arq, "ID: %s\n", usuarios[i].ID);
        fprintf(ponteiro_Arq, "CPF: %d\n", usuarios[i].CPF);
        fprintf(ponteiro_Arq, "Nome: %s\n", usuarios[i].nome);
        fprintf(ponteiro_Arq, "Sobrenome: %s\n", usuarios[i].sobrenome);
        fprintf(ponteiro_Arq, "Senha: %s\n", usuarios[i].senha);
        fprintf(ponteiro_Arq, "Quantidade de pontos: %d\n", usuarios[i].qtde_de_pontos);

        fputc('\n', ponteiro_Arq);
    }

    fclose(ponteiro_Arq);
}

void inicializacao_Produtos(Usuario usuarios[])
{
    FILE *ponteiro_Arq;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
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

        char *token;

        char id[6], nome[50], autor[50];
        int ano, qtde_de_pontos;
        float nivel_de_qualidade;

        strcpy(id, strtok(linhaSemPularLinha, ","));
        strcpy(nome, strtok(NULL, ","));
        strcpy(autor, strtok(NULL, ","));
        ano = atoi(strtok(NULL, ","));
        qtde_de_pontos = atoi(strtok(NULL, ","));
        nivel_de_qualidade = atof(strtok(NULL, ","));

        char id_usuario[4];
        strncpy(id_usuario, id, 3);
        id_usuario[3] = '\0';

        for (int i = 0; i < MAX; i++)
        {
            if (strcmp(usuarios[i].ID, id_usuario) == 0)
            {
                int j = 0;

                while (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                    j++;

                strcpy(usuarios[i].produtos[j].ID, id);
                strcpy(usuarios[i].produtos[j].nome, nome);
                strcpy(usuarios[i].produtos[j].autor, autor);
                usuarios[i].produtos[j].ano = ano;
                usuarios[i].produtos[j].qtde_de_pontos = qtde_de_pontos;
                usuarios[i].produtos[j].nivel_de_qualidade = nivel_de_qualidade;
            }
        }

        //free(token);
    }

    fclose(ponteiro_Arq);
}

void finalizacao_Produtos(Usuario usuarios[])
{
    FILE *ponteiro_Arq;
    ponteiro_Arq = fopen("produtos.txt", "w");

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
            {
                if (i == 0 && j == 0)
                {
                    fprintf(ponteiro_Arq, "%s,%s,%s,%d,%d,%.1f", usuarios[i].produtos[j].ID, 
                    usuarios[i].produtos[j].nome, usuarios[i].produtos[j].autor,
                    usuarios[i].produtos[j].ano, usuarios[i].produtos[j].qtde_de_pontos,
                    usuarios[i].produtos[j].nivel_de_qualidade);
                }
                else
                {
                    fprintf(ponteiro_Arq, "\n%s,%s,%s,%d,%d,%.1f", usuarios[i].produtos[j].ID, 
                    usuarios[i].produtos[j].nome, usuarios[i].produtos[j].autor,
                    usuarios[i].produtos[j].ano, usuarios[i].produtos[j].qtde_de_pontos,
                    usuarios[i].produtos[j].nivel_de_qualidade);
                }
            }
        }
    }

    fclose(ponteiro_Arq);
}

void excluir_usuario(Usuario usuarios[], char idUsuario[])
{

}

void adicionar_Produto(Usuario usuarios[], char idUsuario[])
{
    char id_aux[3];
    char nome[50];
    char autor[50];
    int ano;
    char ID[6];
    int qtde_de_pontos;
    float nivel_de_qualidade;

    strcpy(ID, idUsuario);

    printf("Nome do livro: ");
    scanf("%s", nome);
    getchar();
    printf("Autor do livro: ");
    scanf("%s", autor);
    printf("Ano do lancamento do livro: ");
    scanf("%d", &ano);

    nivel_de_qualidade = questionario();

    qtde_de_pontos = calculo_pontos(nivel_de_qualidade);

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(usuarios[i].ID, idUsuario) == 0)
        {
            int j = 0;

            while (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                j++;

            if (j < 10)
            {
                strcat(ID, "0");
                sprintf(id_aux, "%d", j);
                strcat(ID, id_aux);
            }
            else
            {
                sprintf(id_aux, "%d", j);
                strcat(ID, id_aux);
            }

            strcpy(usuarios[i].produtos[j].ID, ID);
            strcpy(usuarios[i].produtos[j].nome, nome);
            strcpy(usuarios[i].produtos[j].autor, autor);
            usuarios[i].produtos[j].ano = ano;
            usuarios[i].produtos[j].qtde_de_pontos = qtde_de_pontos;
            usuarios[i].produtos[j].nivel_de_qualidade = nivel_de_qualidade;

        }
    }
}

void comprar_produto(Usuario usuarios[], char idUsuario[], char idProduto[])
{

}

void remover_Produto(Usuario usuarios[], char idUsuario[], char idProduto[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(usuarios[i].ID, idUsuario) == 0)
        {
            int j = 0;

            while (strcmp(usuarios[i].produtos[j].ID, idProduto) != 0)
                j++;

            strcpy(usuarios[i].produtos[j].ID, "0");
            strcpy(usuarios[i].produtos[j].nome, "0");
            strcpy(usuarios[i].produtos[j].autor, "0");
            usuarios[i].produtos[j].ano = 0;
            usuarios[i].produtos[j].qtde_de_pontos = 0;
            usuarios[i].produtos[j].nivel_de_qualidade = 0.0;
        }
    }
}