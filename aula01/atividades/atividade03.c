// Considerando o arquivo nomes.txt, composto por duas colunas (Nome e Idade),
// desenvolva um programa que leia o arquivo e exiba seu conteúdo na tela.

// Atenção: a coluna Nome possui 22 caracteres.
// Ajuste o programa para ler corretamente essa coluna de 22 caracteres seguida da idade.

// Neste momento, evite utilizar inteligência artificial para gerar o código (você pode, no entanto, usar a IA para entender como ler uma coluna com 20 caracteres).
// Todas as informações necessárias estão disponíveis no arquivo exemplo01.

#include <stdio.h>

int main() {
  char nome[21];
  int idade;

  FILE *nomes = fopen("nomes.txt", "r");

  if (nomes == NULL) {
    printf("Erro ao abrir o arquivo");

    return 1;
  }

  while (fscanf(nomes, "%21c%d", nome, &idade) == 2) {
    printf("%-21s \t %d", nome, idade);
  }

  fclose(nomes);

  return 0;
}