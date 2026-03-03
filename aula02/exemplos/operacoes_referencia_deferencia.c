#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[3]= {10, 15, 9}; 
  int *p; 
  p= a; // ou a = &p[0]; 
  printf ("Valor de a na posicao 0 %d %x\n", *p, p);
  p++; 
  printf ("Valor de a na posicao 1 %d %x\n", *p, p);
  p++; 
  printf ("Valor de a na posicao 2 %d %x\n", *p, p);
  p++; 
}