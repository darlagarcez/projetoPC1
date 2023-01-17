#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "usuarios.h"
#include "produtos.h"
#include "funcoesmatematicas.h"
#define MAX 10

/* 
    PROGRAMA PARA VENDAS DE LIVROS A PARTIR DE PONTOS
    (feito na IDE "Visual Studio Code") 
*/

// FUNCAO PRINCIPAL
int main()
{
    Usuario usuarios[MAX];

    limpar_tela();

    inicializacao(usuarios);

    menu_inicio(usuarios);

    return 0;
}