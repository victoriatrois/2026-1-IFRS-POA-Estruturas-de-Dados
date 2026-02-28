// Considerando o arquivo cidades.txt, formado por três colunas (Nome da cidade, População e UF),
// gere um programa que leia o arquivo e mostre o conteúdo na tela.

#include <stdio.h>

int main() {
  char nomeDaCidade[12];
  unsigned int populacao;
  char sigla[3];

  FILE *cidades;

  if ((cidades = fopen("cidades.txt", "r")) == NULL) {
    printf("Erro ao abrir o arquivo");
    return 1;

  } else {
    while (!feof(cidades)) {
      fscanf(cidades, "%s %u %s", nomeDaCidade, &populacao, sigla);
      printf("%s %u %s\n", nomeDaCidade, populacao, sigla);
    }
    return 0;
  }
}
