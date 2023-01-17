#ifndef MENU_H
#define MENU_H

#include "usuarios.h"

// BIBLIOTECA PARA EXIBICAO DE MENUS

void inicializacao(Usuario *usuarios);
void menu_inicio(Usuario *usuarios);
void menu_Login(Usuario *usuarios);
void menu_cadastro(Usuario *usuarios);
void menu_Acoes(Usuario *usuarios, char id[]);
void exibir_Usuarios(Usuario *usuarios, char ID[]);
void perfil_Usuario(Usuario *usuarios, char ID[]);
void exibir_produtos(Usuario *usuarios);
void finalizacao(Usuario *usuarios);

#endif