#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

// DECLARACAO DE FUNCOES

float questionario();
float calculo_nivel_qualidade(float notas[7], int idade);
int calculo_pontos(float nivel_de_qualidade);
float nivel_do_dano();

// FIM DAS DECLARACOES

// Funcao que realiza o questionario
float questionario()
{
    int idade;
    float perguntas[7];
    char perguntas_str[7][60] = {"O livro contem todas as paginas?", "O livro esta com a lombada quebrada?",
                                "O livro contem alguma pagina riscada?", "O livro contem alguma pagina amassada?",
                                "O livro contem algum dano visivel?", "O livro contem algum dano por umidade (mofo, por exemplo)?",
                                "O livro esta com as paginas amareladas?"};
    float nivel_de_qualidade;
    int pontos;

    limpar_tela();
    printf(" Quanto meses faz que o usuário comprou o produto? (Valor arrendondado) ");
    scanf("%d", &idade);
    getchar();

    for (int i = 0; i < 7; i++)
    {
        printf("\n %s\n", perguntas_str[i]);
        printf(" 1 - Sim\t2 - Nao\n");
        printf(" Opcao: ");
        scanf("%f", &perguntas[i]);
        getchar();
        if (i == 0)
        {
            if (perguntas[i] == 1.0)
                perguntas[i] = 5.0;
            else if (perguntas[i] == 2.0)
                perguntas[i] = 0.5;
        }
        else if (i == 1)
        {
            if (perguntas[i] == 2.0)
                perguntas[i] = 5.0;
            else if (perguntas[i] == 1.0)
                perguntas[i] = 2.5;
        }
        else
        {
            if (perguntas[i] == 2.0)
                perguntas[i] = 5.0;
            else if (perguntas[i] == 1.0)
                perguntas[i] = nivel_do_dano();
        }
    }
    
    nivel_de_qualidade = calculo_nivel_qualidade(perguntas, idade);

    return nivel_de_qualidade;

}

// Funcao que calcula o nivel de qualidade do livro
float calculo_nivel_qualidade(float notas[7], int idade)
{
    float pesos[7] = {1, 1, 2, 2, 1, 1, 2};
    float media;

    if (idade <= 12)
        idade = 5;
    else if (idade > 12 && idade <= 36)
        idade = 4;
    else if (idade > 36 && idade <= 60)
        idade = 3;
    else if (idade > 60 && idade <= 84)
        idade = 2;
    else if (idade > 84)
        idade = 1;

    media = mediap(notas, pesos, 7);

    media = soma(media, (float) idade);

    return divisao(media, 2);
}

// Funcao que calcula a quantidade de pontos do livro
int calculo_pontos(float nivel_de_qualidade)
{
    int pontos;

    if (nivel_de_qualidade >= 4.0)
        pontos = 95;
    else if (nivel_de_qualidade >= 3.0 && nivel_de_qualidade < 4.0)
        pontos = 75;
    else if (nivel_de_qualidade >= 2.0 && nivel_de_qualidade < 3.0)
        pontos = 50;
    else if (nivel_de_qualidade >= 1.0 && nivel_de_qualidade < 2.0)
        pontos = 25;
    else if (nivel_de_qualidade < 1.0)
        pontos = 5;

    return pontos;
}

// Funcao para definir o nivel do dano
float nivel_do_dano()
{
    float opcao;

    printf("\n  De 1 à 5, defina o nivel do dano:\n");
    printf("  1 - Muito pequeno\t2 - Pequeno\t3 - Medio\t4 - Grande\t5 - Muito grande\n");
    printf("  Opcao: ");
    scanf("%f", &opcao);
    getchar();

    if (opcao == 1.0)
        return 4.0;
    else if (opcao == 2.0)
        return 2.5;
    else if (opcao == 3.0)
        return 1.0;
    else if (opcao == 4.0 || opcao == 5.0)
        return 0.5;
}