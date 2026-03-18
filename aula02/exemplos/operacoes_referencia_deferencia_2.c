#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[3]= {10, 15, 9}; 
  int *p; 

  p= a; // ou p = &p[0]; 

  //somando o valor 20 na posicao a[0]
  (*p)= (*p)+20; 

  //somando o valor 30 na posicao a[2]
  *(p+2)= *(p+2)+30; 

  printf ("Valor de a na posicao 0 %d\n", *p); 
  p++; 

  printf ("Valor de a na posicao 1 %d\n", *p); 

  printf ("Valor de a na posicao 2 %d\n", *(p+1)); 
}