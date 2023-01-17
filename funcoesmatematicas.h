#ifndef FUNCOESMATEMATICAS_H
#define FUNCOESMATEMATICAS_H

void limpar_tela();
void gotoxy(int x,int y);
int validarcpf(char c_pf[]);
float mediap(float notas[],float pesos[], int tam);
float soma(float x, float y);
float subtracao(float x, float y);
float produto(float x, float y);
float divisao(float x, float y);

#endif