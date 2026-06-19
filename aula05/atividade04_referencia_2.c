// Considerando o programa abaixo, qual será o valor de I no final do programa?

#include <stdlib.h>
#include <stdio.h>

// void somaUm(int &x) { // c++
void somaUm(int *x) { // c puro
  // x++; // c++
  (*x)++; // c puro
}

void main() {
  int i=0;

  while (i<10) {
    somaUm(&i);
  }
  printf("valor de i : %d \n",i);
}
