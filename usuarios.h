#ifndef USUARIOS_H
#define USUARIOS_H

typedef struct usuario
{
    int CPF;
    char nome[50];
    char ID[4];
    int qtde_de_pontos;
    char senha[20];
    int produtos[20];
}Usuario;

void inicializacao_Usuarios();
void finalizacao_Usuarios();

#endif