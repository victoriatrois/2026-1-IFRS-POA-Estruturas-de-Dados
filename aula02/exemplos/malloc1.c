#include <stdio.h>

int main(void) {
  int *p;
  float a = 100000000; /* Determina o valor de a */
  p= (int *)malloc (a * sizeof(float));
  if (!p) {
    printf ("** Erro: Memória Insuficiente **");

  } else {
    printf ("Memória alocada som sucesso!!!");
  }
return 0;
}