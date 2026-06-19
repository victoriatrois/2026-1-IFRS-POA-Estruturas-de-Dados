// Qual é a alternativa Correta? Justifique e apresente um exemplo de código. 

// Se você quiser usar o conteúdo do ponteiro *p 15 posições adiante, deverá escrever: 
// a)    *(p+15); 
// b)    *P[15]; 
// c)    &p[15];
// d)    (*p+15);
// e)    NDA; 

#include <stdio.h>

void main() {
  int a[20];
  int *p;

  p = a;
  *(p+15) = 15;

  printf("O valor de a[15] é %d\n", a[15]);
}
