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
} Usuario;

// Funcoes de usuarios
void inicializacao_Usuarios(Usuario usuarios[]);
void finalizacao_Usuarios(Usuario usuarios[]);

// Funcoes de produtos do usuario
void inicializacao_Produtos(Usuario usuarios[]);
void finalizacao_Produtos(Usuario usuarios[]);
void adicionar_Produto(int idUsuario);
void remover_Produto(int idProduto);

#endif