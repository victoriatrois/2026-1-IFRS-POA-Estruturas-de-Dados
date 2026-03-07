// Altere o código para usar alocação dinâmica e ponteiros. 
// Alterar as linhas 10, 15, 17 e 18. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int main(void) {
  char *frase = (char *) malloc(tamanho * sizeof(char));

  if (frase == NULL) {
    printf("Alocação de memória falhou.");
    return 1;
  }

  strcpy(frase, "IFRS - Instituto Federal de Educação Tecnológica \n");

  char *p = frase;
  
  while (*p != '\n') {
    printf("%c", *p);
    p++;
  }

  free(frase);

  return 0;
}