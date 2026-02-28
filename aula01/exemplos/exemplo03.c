#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
int i;
unsigned int numAleatorio;

  FILE *txt;

  // substitui o arquivo, caso exista
  if ((txt = fopen("Arquivo.txt", "w")) == NULL) {
    printf("Erro ao abrir arquivo");
  } else {
    // define a semente inicial do gerador de números aleatórios
    i = 0;
    numAleatorio = ((unsigned) time(NULL));

    srand(numAleatorio) ; 

    while(i < 100) {
      float c = rand() % 100;
      fprintf(txt, "%u - Execução %d - número gerado: %.0f\n",numAleatorio, i, c);
      ++i;
    }

    fclose(txt);
  }
}
