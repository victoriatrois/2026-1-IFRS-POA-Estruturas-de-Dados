// O que imprime o programa a seguir?
// (Faça uma análise antes de executar). 

# include <stdio.h>

// void func(int aa, int bb) { //não retorna nada, as mudanças de valores ocorre apenas dentro do escopo do procedimento
void func(int *aa, int *bb) { //não retorna nada, mas com o endereço dos parâmetros, manipula direto onde se armazena o valor na memória
  int temp;
  temp = *aa; // guarda o valor de aa
  *aa = *bb; // troca o valor de aa pelo de bb
  *bb = temp; // troca o bb pelo valor original de aa
}

int  main() {
  int a = 10, b = 20;
  // func(a, b);
  // printf("a = %d, b = %d\n", a, b); // a = 10, b = 20
  func(&a, &b);
  printf("a = %d, b = %d\n", a, b); // a = 20, b = 10
}

// O que deve ser alterado para realmente realizar a troca de valores? (apresente um código de exemplo).
//   Deve-se passar os parâmetros por reerência, usando o operadores * e &