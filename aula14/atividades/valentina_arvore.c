// Considere o arquivo dados.txt apresentado na Semana 12. Faça dois programas:

// um programa que carregue os dados na memória e implemente a pesquisa binária em uma estrutura linear;
// outro programa que implemente a pesquisa em uma estrutura hierárquica.
// Os programas devem:

// iniciar automaticamente;
// carregar os dados;
// ordená-los, se necessário;
// pesquisar o nome "Valentina Moura";
// encerrar automaticamente.
// Todos os processos devem ser executados sem interação com o usuário.

// Ao final, cada programa deve apresentar:

// o tempo total necessário para executar todos os processos;
// o número de acessos realizados durante a pesquisa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"

TArvore *insere_por_nome(TArvore *a, int matricula, char nome[30]) {
  if (a == NULL) {
    a = Cria(NULL, matricula, nome, NULL);
  } else if (strcmp(nome, a->nome) < 0) {
    a->esq = insere_por_nome(a->esq, matricula, nome);
  } else if (strcmp(nome, a->nome) > 0) {
    a->dir = insere_por_nome(a->dir, matricula, nome);
  }
  return a;
}

// Função auxiliar para buscar por nome na árvore
TArvore *busca_por_nome(TArvore *a, const char *nome, int *acessos) {
  if (a == NULL) {
    return NULL;
  }
  
  (*acessos)++;
  int cmp = strcmp(nome, a->nome);

  if (cmp == 0) {
    return a;
  } else if (cmp < 0) {
    return busca_por_nome(a->esq, nome, acessos);
  } else {
    return busca_por_nome(a->dir, nome, acessos);
  }
}

int main(void) {
  clock_t inicio, fim;
  double tempoTotal;

  inicio = clock();

  FILE *arquivo = fopen("dados.txt", "r");
  if (arquivo == NULL) {
    arquivo = fopen("dados.txt", "r");
  }

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo dados.txt\n");
    return 1;
  }

  TArvore *raiz = NULL;

  char linha[100];
  int matricula;
  char nome[30];
  
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (sscanf(linha, "%d %29[^\n]", &matricula, nome) == 2) {
      raiz = insere_por_nome(raiz, matricula, nome);
    }
  }

  fclose(arquivo);

  int acessos = 0;
  TArvore *resultado = busca_por_nome(raiz, "Valentina Moura", &acessos);

  fim = clock();
  tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  if (resultado != NULL) {
    printf("Estudante encontrado:\n");
    printf("Matrícula: %d\n", resultado->matricula);
    printf("Nome: %s\n\n", resultado->nome);
  } else {
    printf("Estudante 'Valentina Moura' não encontrado.\n\n");
  }

  printf("Número de acessos durante a busca: %d\n", acessos);
  printf("Tempo total de execução: %.6f segundos\n", tempoTotal);

  raiz = Destroi(raiz);

  return 0;
}
