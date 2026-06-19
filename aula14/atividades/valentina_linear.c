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

typedef struct {
  int matricula;
  char nome[50];
} Registro;

int comparar(const void *a, const void *b) {
  return strcmp(((Registro *)a)->nome, ((Registro *)b)->nome);
}

int buscaBinaria(Registro *registros, int tamanho, const char *nomeBuscado, int *acessos) {
  int esquerda = 0;
  int direita = tamanho - 1;
  
  while (esquerda <= direita) {
    (*acessos)++;
    int meio = (esquerda + direita) / 2;
    int comparacao = strcmp(registros[meio].nome, nomeBuscado);
    
    if (comparacao == 0) {
      return meio;
    } else if (comparacao < 0) {
      esquerda = meio + 1;
    } else {
      direita = meio - 1;
    }
  }
  return -1;
}

int main(void) {
  clock_t inicio, fim;
  double tempoTotal;

  inicio = clock();

  FILE *arquivo = fopen("dados.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo dados.txt\n");
    return 1;
  }

  int capacidade = 1000;
  int tamanho = 0;
  Registro *registros = (Registro *)malloc(capacidade * sizeof(Registro));
  
  if (registros == NULL) {
    printf("Erro ao alocar memória\n");
    fclose(arquivo);
    return 1;
  }

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (sscanf(linha, "%d %49[^\n]", &registros[tamanho].matricula, registros[tamanho].nome) == 2) {
      tamanho++;

      if (tamanho >= capacidade) {
        capacidade *= 2;
        registros = (Registro *)realloc(registros, capacidade * sizeof(Registro));
        if (registros == NULL) {
          printf("Erro ao realocar memória\n");
          fclose(arquivo);
          return 1;
        }
      }
    }
  }

  fclose(arquivo);

  qsort(registros, tamanho, sizeof(Registro), comparar);

  int acessos = 0;
  int indice = buscaBinaria(registros, tamanho, "Valentina Moura", &acessos);

  fim = clock();
  tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  if (indice != -1) {
    printf("Estudante encontrado:\n");
    printf("Matrícula: %d\n", registros[indice].matricula);
    printf("Nome: %s\n\n", registros[indice].nome);
  } else {
    printf("Estudante 'Valentina Moura' não encontrado.\n\n");
  }

  printf("Número de acessos durante a busca: %d\n", acessos);
  printf("Tempo total de execução: %.6f segundos\n", tempoTotal);

  free(registros);

  return 0;
}
