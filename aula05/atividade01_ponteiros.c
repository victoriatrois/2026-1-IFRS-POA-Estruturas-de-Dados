// Do mesmo modo que dizemos que o endereço da variável x é E2, podemos dizer que o endereço do array a é E100. Isto é, o endereço do array é o endereço do primeiro byte que o array ocupa.
// De fato, quando declararmos:

#include <stdio.h>

void main() {
  int a[10];
  int *p;

  p = a;
  *p = 10;

  printf("O valor de a[0] é %d\n", a[0]);
}

// é equivalente:   (Faça um exemplo e publique o código)
// a) a[0] = 10; <- correta 
// b) *a[0] = 10;
// c) a= 10;
// d) &a = 10;
// e) NDA