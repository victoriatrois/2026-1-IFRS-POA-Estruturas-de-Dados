// O que imprime o programa a seguir?
// 10 e 20 pois as variáveis passadas para o printf na linha 16 estão invertidos

# include <stdio.h>

void func(int *aa, int *bb) {
  int temp;
  temp = *aa;
  *aa = *bb;
  *bb = temp;
}

int  main() {
  int a = 10, b = 20;
  func(&a, &b);
  printf("a = %d, b = %d", b, a);
}