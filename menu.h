#ifndef MENU_H
#define MENU_H

#include "usuarios.h"

void limpar_tela();

void inicializacao(Usuario usuarios[]);

void menu_Login(Usuario usuarios[]);

void menu_Acoes(Usuario usuarios[]);

void exibir_Usuarios(Usuario usuarios[]);

void perfil_Usuario(Usuario usuarios[], int cpf);

void finalizacao(Usuario usuarios[]);

#endif