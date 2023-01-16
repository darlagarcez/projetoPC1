#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "usuarios.h"
#include "produtos.h"
#define MAX 10

int main()
{
    Usuario usuarios[MAX];
    int opcao;
    int retorno = -1;

    limpar_tela();

    inicializacao(usuarios);

    menu_inicio(usuarios);

    return 0;
}