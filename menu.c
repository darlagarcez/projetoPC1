#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "produtos.h"
#include "usuarios.h"
#include "funcoesmatematicas.h"
#include "pontos.h"
#define MAX 10

// DECLARACAO DE FUNCOES

void inicializacao(Usuario *usuarios);
void menu_inicio(Usuario *usuarios);
void menu_Login(Usuario *usuarios);
void menu_cadastro(Usuario *usuarios);
void menu_Acoes(Usuario *usuarios, char id[]);
void exibir_Usuarios(Usuario *usuarios, char ID[]);
void perfil_Usuario(Usuario *usuarios, char ID[]);
void exibir_produtos(Usuario *usuarios);
void finalizacao(Usuario *usuarios);

// FIM DAS DECLARACOES

// Funcao de inicializacao do programa
void inicializacao(Usuario *usuarios)
{
    inicializacao_Usuarios(usuarios);
    inicializacao_Produtos(usuarios);
}

// Funcao para exibir o menu inicial
void menu_inicio(Usuario *usuarios)
{
    int opcao;
    int retorno = -1;

    do
    {
        limpar_tela();
        puts(" ESCOLHA UMA ACAO:\n");
        puts(" 1 - Login");
        puts(" 2 - Cadastro\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                retorno = 0;
                limpar_tela();
                menu_Login(usuarios);
                break;

            case 2:
                retorno = 0;
                limpar_tela();
                menu_cadastro(usuarios);
                break;

            default:
                retorno = 1;
                limpar_tela();
                puts(" OPCAO INVALIDA!");
                sleep(1);
                break;
        }
    } while (retorno != 0);
}

// Funcao para exibir o menu de login
void menu_Login(Usuario *usuarios)
{
    char CPF_Login[15];
    char SENHA_Login[20];
    char id[6];
    int retorno = 1;

    do
    {
        int cpf_valido;

        limpar_tela();
        puts(" LOGIN\n");
        puts(" CPF (XXX.XXX.XXX-XX): ");
        puts(" SENHA: ");
        gotoxy(24,3);
        scanf("%s", CPF_Login);
        getchar();
        gotoxy(9,4);
        scanf("%s", SENHA_Login);

        cpf_valido = validarcpf(CPF_Login);

        if (cpf_valido != 0)
        {
            limpar_tela();
            puts(" CPF INVALIDO!");
            puts(" FAVOR, TENTAR NOVAMENTE.\n");
            puts(" Formato do CPF: XXX.XXX.XXX-XX");
            sleep(2);
            menu_inicio(usuarios);
        }
        else
        {
            for (int i = 0; i < MAX; i++)
            {
                if (strcmp(usuarios[i].CPF, CPF_Login) == 0 && strcmp(usuarios[i].senha, SENHA_Login) == 0)
                {
                    retorno = 0;
                    strcpy(id, usuarios[i].ID);
                }
            }
        }
        if (retorno == 1)
        {
            limpar_tela();
            puts(" CPF OU SENHA INVALIDOS!");
            puts(" POR FAVOR, TENTE NOVAMENTE");
            sleep(1);
        }   
    } while (retorno != 0);

    limpar_tela();
    puts(" LOGIN REALIZADO COM SUCESSO");
    puts(" BEM VINDO(A)!\n");
    perfil_Usuario(usuarios, id);
    sleep(3);

    menu_Acoes(usuarios, id);
}

// Funcao para exibir o menu de cadastro
void menu_cadastro(Usuario *usuarios)
{
    char CPF[15];
    char nome[20];
    char sobrenome[20];
    char ID[4];
    char senha[20];
    char id_aux[4];
    int usuario_encontrado = 1;
    int cpf_valido;
    int retorno = 1;

    do
    {
        limpar_tela();
        puts(" CADASTRO\n");
        puts(" PRIMEIRO NOME: ");
        puts(" ULTIMO NOME: ");
        puts(" CPF: ");
        printf(" SENHA: ");
        gotoxy(17,3);
        scanf("%s", nome);
        getchar();
        gotoxy(15,4);
        scanf("%s", sobrenome);
        getchar();
        gotoxy(7,5);
        scanf("%s", CPF);
        getchar();
        gotoxy(9,6);
        scanf("%s", senha);
        
        cpf_valido = validarcpf(CPF);

        if (strlen(senha) < 8)
        {
            limpar_tela();
            retorno = 1;
            puts(" SENHA MUITA PEQUENA!");
            puts(" FAVOR, TENTE NOVAMENTE.");
            sleep(1);
        }
        else if (cpf_valido != 0)
        {
            limpar_tela();
            retorno = 1;
            puts(" CPF INVALIDO!");
            puts(" FAVOR, TENTAR NOVAMENTE.\n");
            puts(" Formato do CPF: XXX.XXX.XXX-XX");
            sleep(2);
        }
        else
        {
            for (int i = 0; i < MAX; i++)
            {
                if (strcmp(usuarios[i].CPF, CPF) == 0)
                {
                    usuario_encontrado = 0;
                    limpar_tela();
                    puts(" CPF JÁ CADASTRADO!");
                    sleep(1);
                    menu_inicio(usuarios);
                }
            }

            if (usuario_encontrado != 0)
            {

                for (int i = 0; i < MAX; i++)
                {
                    if (strcmp(usuarios[i].ID, "0") == 0)
                    {
                        if (i < 10)
                        {
                            strcpy(ID, "00");
                            sprintf(id_aux, "%d", i);
                            strcat(ID, id_aux);
                        }
                        else if (i >= 10 && i < 100)
                        {
                            strcpy(ID, "0");
                            sprintf(id_aux, "%d", i);
                            strcat(ID, id_aux);
                        }
                        else 
                        {
                            sprintf(id_aux, "%d", i);
                            strcat(ID, id_aux);
                        }

                        strcpy(usuarios[i].nome, nome);
                        strcpy(usuarios[i].sobrenome, sobrenome);
                        strcpy(usuarios[i].CPF, CPF);
                        strcpy(usuarios[i].senha, senha);
                        strcpy(usuarios[i].ID, ID);

                        limpar_tela();
                        retorno = 0;
                        puts(" CADASTRO REALIZADO COM SUCESSO!");
                        puts(" BEM VINDO(A)!\n");
                        perfil_Usuario(usuarios, ID);
                        sleep(3);

                        menu_Acoes(usuarios, ID);
                    }
                }
            }
        }
    } while (retorno != 0);
}

// Funcao para exibir o menu de acoes
void menu_Acoes(Usuario *usuarios, char id[])
{
    int opcao, opcao2, opcao3;
    char CPF_usuario[15];
    char idProduto[6];

    do
    {	
        limpar_tela();
	    puts("         SEBO ONLINE\n");
        puts(" ESCOLHA UMA ACAO:\n");
	    puts(" 1 - Comprar produto");
	    puts(" 2 - Adicionar produto");
	    puts(" 3 - Exibir usuarios");
	    puts(" 4 - Exibir produtos");
        puts(" 5 - Excluir conta");
	    puts(" 6 - Sair\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                limpar_tela();
                exibir_produtos(usuarios);
                puts(" Digite o ID do produto: #");
                scanf("%s", idProduto);
                comprar_produto(usuarios, id, idProduto);
                break;
            case 2:
                limpar_tela();
                adicionar_Produto(usuarios, id);
                break;
                
            case 3:
                limpar_tela();
                puts("         SEBO ONLINE\n");
                puts(" EXIBIR USUARIOS:\n");
                puts(" 1 - Lista de usuarios");
                puts(" 2 - Usuario pelo CPF\n");
                printf(" Opcao: ");
                scanf("%d", &opcao2);
                getchar();

                switch (opcao2)
                {
                    case 1:
                        limpar_tela();
                        exibir_Usuarios(usuarios, id);
                        puts(" DESEJA COMPRAR ALGUM PRODUTO?\n");
                        puts(" 1 - Sim");
                        puts(" 2 - Nao\n");
                        printf(" Opcao: ");
                        scanf("%d", &opcao3);
                        getchar();

                        if (opcao3 == 1)
                        {
                            printf("\n Digite o ID do produto: #");
                            scanf("%s", idProduto);
                            comprar_produto(usuarios, id, idProduto);
                        }
                        else if (opcao3 != 2)
                        {
                            limpar_tela();
                            puts(" OPCAO INVALIDA!");
                            sleep(1);
                        }
                        break;
                    
                    case 2:
                        limpar_tela();
                        printf(" Digite o CPF do usuario: ");
                        scanf("%s", CPF_usuario);
                        perfil_Usuario(usuarios, CPF_usuario);
                        getchar();
                        printf(" Pressione qualquer tecla para continuar...");
                        getchar();
                        break;

                    default:
                        limpar_tela();
                        puts(" OPCAO INVALIDA!");
                        sleep(1);
                        break;
                }
                break;

            case 4:
                limpar_tela();
                exibir_produtos(usuarios);
                puts(" DESEJA COMPRAR ALGUM PRODUTO?\n");
                puts(" 1 - Sim");
                puts(" 2 - Nao\n");
                printf(" Opcao: ");
                scanf("%d", &opcao3);
                getchar();

                if (opcao3 == 1)
                {
                    printf("\n Digite o ID do produto: #");
                    scanf("%s", idProduto);
                    comprar_produto(usuarios, id, idProduto);
                }
                else if (opcao3 != 2)
                {
                    limpar_tela();
                    puts(" OPCAO INVALIDA!");
                    sleep(1);
                }
                break;

            case 5:
                limpar_tela();
                exibir_Usuarios(usuarios, id);
                puts(" DESEJA EXCLUIR A CONTA?\n");
                puts(" 1 - Sim");
                puts(" 2 - Nao\n");
                printf(" Opcao: ");
                scanf("%d", &opcao3);
                getchar();

                if (opcao3 == 1)
                {
                    excluir_usuario(usuarios, id);
                    limpar_tela();
                    puts(" CONTA EXCLUIDA!");
                    finalizacao(usuarios);
                    exit(1);
                }
                else if (opcao3 != 2)
                {
                    limpar_tela();
                    puts(" OPCAO INVALIDA!");
                    sleep(1);
                }
                break;

            case 6:
                limpar_tela();
                puts(" PROGRAMA FINALIZADO!");
                finalizacao(usuarios);
                exit(1);
                break;
            
            default:
                limpar_tela();
                puts(" OPCAO INVALIDA!");
                sleep(1);
                break;
        }
    } while (opcao != 5);
}

// Funcao para exibir os usuarios cadastrados
void exibir_Usuarios(Usuario *usuarios, char ID[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(usuarios[i].ID, "0") != 0)
        {
            printf(" %s%c #%-10s", usuarios[i].nome, usuarios[i].sobrenome[0], usuarios[i].ID);
            printf("%d\n", usuarios[i].qtde_de_pontos);
            puts("\n        PRODUTOS\n");
            for (int j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf(" TITULO: %s\n", usuarios[i].produtos[j].nome);
                    printf(" PONTOS: %-5d ID: %-5s\n", usuarios[i].produtos[j].qtde_de_pontos, usuarios[i].produtos[j].ID);
                }
            }
            puts("");
        }
    }
}

// Funcao para exibir o perfil de um usuario especifico
void perfil_Usuario(Usuario *usuarios, char ID[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(usuarios[i].ID, ID) == 0)
        {
            printf(" %s%c #%-10s", usuarios[i].nome, usuarios[i].sobrenome[0], usuarios[i].ID);
            printf("%d\n", usuarios[i].qtde_de_pontos);
            puts("\n        PRODUTOS\n");
            for (int j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf(" TITULO: %s\n", usuarios[i].produtos[j].nome);
                    printf(" PONTOS: %-10d ID: %-5s\n", usuarios[i].produtos[j].qtde_de_pontos, usuarios[i].produtos[j].ID);
                }
            }
            puts("");
        }
    }
}

// Funcao para exibir os produtos cadastrados
void exibir_produtos(Usuario *usuarios)
{
    int i, j;

    for (i = 0; i < MAX; i++)
    {
        if (usuarios[i].CPF != 0)
        {
            
            for (j = 0; j < 20; j++)
            {
                if (strcmp(usuarios[i].produtos[j].ID, "0") != 0)
                {
                    printf(" TITULO: %-50s PONTOS: %-5d\n", usuarios[i].produtos[j].nome, usuarios[i].produtos[j].qtde_de_pontos);
                    printf(" AUTOR: %-50s  ID: %-5s\n", usuarios[i].produtos[j].autor, usuarios[i].produtos[j].ID);
                    printf(" PROPRIETARIO: %s%c #%s\n\n", usuarios[i].nome, usuarios[i].sobrenome[0], usuarios[i].ID);
                }
            }
        }
    }
}

// Funcao para finalizar o programa
void finalizacao(Usuario *usuarios)
{   
    finalizacao_Usuarios(usuarios);
    finalizacao_Produtos(usuarios);
}