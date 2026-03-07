#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int main(void) {
  char frase[tamanho];

  strcpy(frase, "IFRS - Instituto Federal de Educação Tecnológica \n");

  int i = 0;

  while (frase[i] != '\n') {
    printf("%c", frase[i]);
    i++;
  }

  return 0;
}