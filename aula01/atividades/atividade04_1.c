// 1) Considerando o Exemplo03.cpp,
// altere o programa de modo que ele
//   leia dez (10) nomes de pessoas e suas respectivas idades e
//   grave em um arquivo chamado lista.txt.

#include <stdio.h>

int main() {
  char nome[21];
  int idade;

  int nomesLidos = 0;
  FILE *nomes = fopen("nomes.txt", "r");
  FILE *lista = fopen("lista.txt", "w");

  if (nomes == NULL || lista == NULL) {
    printf("Erro ao abrir o arquivo");

    return 1;
  }

  // while (fscanf(nomes, "%21c%d", nome, &idade) == 2) {
  //   printf("%-21s \t %d", nome, idade);
  // }

  while (
    nomesLidos < 10
    && fscanf(nomes, " %21[^\n]%d", nome, &idade) == 2) {
      fprintf(lista, "%-21s %d\n", nome, idade);

      nomesLidos++;
  }

  fclose(lista);
  fclose(nomes);
  
  return 0;
}
