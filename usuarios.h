#ifndef USUARIOS_H
#define USUARIOS_H

#include "produtos.h"

// BIBLIOTECA PARA MANIPULACAO DE USUARIOS E PRODUTOS

// Estrutura de usuarios
typedef struct usuario
{
    char CPF[15];
    char nome[20];
    char sobrenome[20];
    char ID[4];
    int qtde_de_pontos;
    char senha[20];
    Produto produtos[20];
} Usuario;

// Funcoes de usuarios
void inicializacao_Usuarios(Usuario *usuarios);
void finalizacao_Usuarios(Usuario *usuarios);
void excluir_usuario(Usuario *usuarios, char idUsuario[]);

// Funcoes de produtos do usuario
void inicializacao_Produtos(Usuario *usuarios);
void finalizacao_Produtos(Usuario *usuarios);
void adicionar_Produto(Usuario *usuarios, char idUsuario[]);
void comprar_produto(Usuario *usuarios, char idUsuario[], char idProduto[]);
void remover_Produto(Usuario *usuarios, char idUsuario[], char idProduto[]);

#endif