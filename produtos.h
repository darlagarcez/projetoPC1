#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct produto
{
    char nome[50];
    char autor[50];
    int ano;
    char ID[6];
    int qtde_de_pontos;
    float nivel_de_qualidade;
} Produto;

#endif