// Considerando o código

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 44

int main(void) {
  // char * letras = (char*) malloc(100);
  char * letras = (char*) calloc(44, sizeof(char));
  strcpy(letras, "Linguagem C - Eu adoro programar em C \n");

  int i = 0;
  while (i < tamanho) {
    printf("%c", *letras);
    i++;
    letras++;
  }

  return 0;
}

// Execute e descreva o que o programa imprime.
// O programa imprime a frase "Linguagem C - Eu adoro programar em C"
// Isso acontece caractere a caractere e não para após a frase ter seus 40 characteres impressos,
// o loop repete 100 vezes, mesmo sem ter o que imprimir.

// Após executar e descrever o programa:
//   * altere a função malloc para calloc (veja a sintaxe/diferença-a)
//   * execute novamente.
//   * Responda: qual foi a mudança?
//     Visualmente não há mudanças, mas ao inicializar o a execução do programa
//     cada pocisão alocada é inicializada com zeros, o que não acobtece com o malloc().
//     