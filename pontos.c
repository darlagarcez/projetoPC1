#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

float questionario();
float calculo_nivel_qualidade(float notas[7], int idade);
int calculo_pontos(float nivel_de_qualidade);
float nivel_do_dano();

float questionario()
{
    int idade;
    float perguntas[7];
    char perguntas_str[8][60] = {"O livro contém todas as páginas?", "O livro está com a lombada quebrada?",
                                "O livro contém alguma página riscada?", "O livro contém alguma página amassada?",
                                "O livro contém algum dano visível?", "O livro contém algum dano por umidade (mofo, por exemplo)?",
                                "O livro está com as páginas amareladas?"};
    float nivel_de_qualidade;
    int pontos;

    printf("Quanto meses faz que o usuário comprou o produto? (Valor arrendondado)");
    scanf("%d", idade);

    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", perguntas_str[i]);
        printf("1 - Sim\t2 - Nao\n");
        printf("Opcao: ");
        scanf("%f", perguntas[i]);
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
            if (perguntas[i] == 1.0)
                perguntas[i] = 5.0;
            else if (perguntas[i] == 2.0)
                perguntas[i] = nivel_do_dano();
        }
    }

    nivel_de_qualidade = calculo_nivel_qualidade(perguntas, idade);

    return nivel_de_qualidade;

}

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

    media = media + (float) idade;

    return (media / 2);
}

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

float nivel_do_dano()
{
    float opcao;

    printf("De 1 à 5, defina o nivel do dano:\n");
    printf("1 - Muito pequeno\t2 - Pequeno\t3 - Medio\t4 - Grande\t5 - Muito grande\n");
    printf("Opcao: ");
    scanf("%f", opcao);

    if (opcao == 1.0)
        return 4.0;
    else if (opcao == 2.0)
        return 2.5;
    else if (opcao == 3.0)
        return 1.0;
    else if (opcao == 4.0 || opcao == 5.0)
        return 0.5;
}