#include <stdio.h>
#include <stdlib.h>
// a ) Faça um programa recursivo de conte de 1 até 100, apresentando os valores de forma Crescente.
// porque incrementa funciona
void incrementa(int n) {
  if (n == 1) {
    printf("%d ", n);
  } else {
    // se adiciona o if aqui, insere uma quebra de linha antes do 1
    incrementa(n - 1);
    // se adiciona o if aqui, insere uma quebra de linha antes do 100
    printf("%d ", n);
    // se adiciona o if aqui, insere uma quebra de linha depois do 100
    if (n == 100) {
      printf("\n");
    }
  }
}

// e incrementaAtehCem não?
void incrementaAtehCem() {
  int n = 100;
  if (n == 1) {
    printf("%d ", n);
  } else {
    n--;
    incrementaAtehCem();
    printf("%d ", n);
  }
}

// b ) Altere programa recursivo que conte de 1 até 100, apresentando os valores de forma Decrescente.
// porque decrementa funciona
void decrementa(int n) {
  if (n == 1) {
    printf("%d\n", n);
  } else {
    printf("%d ", n);
    decrementa(n - 1);
  }
}

// e decrementaDeCem não?
void decrementaDeCem() {
  int n = 100;
  if (n == 1) {
    printf("%d\n", n);
  } else {
    printf("%d ", n);
    decrementaDeCem(n - 1);
  }
}

int main() {
  printf("Incrementando...\n");
  incrementa(100);
  
  printf("Decrementando...\n");
  decrementa(100);
  
  exit(1);
}
