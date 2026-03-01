// Considerando o arquivo listaDecidades.txt, formado por três colunas (Nome da cidade, População e UF),
// gere um programa que leia o arquivo e mostre o conteúdo na tela.
// Mostre o conteúdo do Arquivo na ordem inversa a leitura do arquivo (mostrar do final para o inicio).

#include <stdio.h>

#define NUM_MAX_DE_CIDADES 500

typedef struct {
  char nomeDaCidade[12];
  unsigned int populacao;
  char uf[3];
} Cidade;

int main() {
  Cidade cidades[NUM_MAX_DE_CIDADES];
  
  int numDeCidades = 0;
  int camposLidos = 0;
  
  FILE *listaDecidades = fopen("cidades.txt", "r");

  if (listaDecidades == NULL) {
    printf("Erro ao abrir o arquivo\n");

    return 1;
  }

  while (numDeCidades < NUM_MAX_DE_CIDADES) {
    camposLidos = fscanf(listaDecidades, "%11s %u %2s",
                   cidades[numDeCidades].nomeDaCidade,
                   &cidades[numDeCidades].populacao,
                   cidades[numDeCidades].uf);

    if (camposLidos != 3) {
        break;
    }

    numDeCidades++;
  }

  fclose(listaDecidades);

  for (int i = numDeCidades - 1; i >= 0; i--) {
    printf("%s %u %s\n",
            cidades[i].nomeDaCidade,
            cidades[i].populacao,
            cidades[i].uf);

  }

  return 0;
}