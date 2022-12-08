#ifndef USUARIOS_H
#define USUARIOS_H

#include "produtos.h"

typedef struct usuario
{
    int CPF;
    char nome[50];
    char ID[4];
    int qtde_de_pontos;
    char senha[20];
    Produto produtos[20];
}Usuario;

void inicializacao_Usuarios(Usuario usuarios[]);
void finalizacao_Usuarios(Usuario usuarios[]);

#endif