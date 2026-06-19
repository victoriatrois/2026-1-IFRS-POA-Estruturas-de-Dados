// Considerando o programa abaixo, responda:

#include <stdio.h>
#include <stdlib.h>
int main (void) {
  int *p, a, *i;
  i=&a; 
  p=&a;

  a = 30;

  p = (int *) malloc (a * sizeof(int));

  if (!p) {
    printf ("** Erro: Memoria Insuficiente **");
    exit (1);
  }
  printf ("p: %d\n", *i); // 30
  printf ("sizeof(p): %d\n", sizeof(p)); // 8
}


// Quantos bytes ocupam o ponteiro p? Oito, já que 30 é composto de dois inteiros
// Qual é resultado de impressão de *(i) no final do programa? 30
// (Justifique a resposta, apresentando a execução com os valores). 