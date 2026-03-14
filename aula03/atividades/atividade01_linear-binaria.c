// Considerando o arquivo DADOS.ZIP, cujo conteúdo está ordenado,
// altere os códigos de busca sequencial e busca binária para carregar
// o conteúdo do arquivo ASCII para um vetor. 
// Logo após o carregamento, faça a contagem de acessos necessários para localizar os seguintes valores:
//   7341488
//   85
//   265654
//   732765
//   8313596
//   45744
// Considerando todos as pesquisas,
//   quantos acessos (no total) cada método de busca teve?
//   qual foi o ganho de desempenho do algoritmo mais eficiente em relação ao menos eficiente?

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 20

int main(void) { 
  int x, vetor[TAMANHO] = {3,5,6,7,8,9,10,12,14,16,19,20,21,22,33,35,37,39,44,53};
  int Cont = 0; 

  printf("Qual Numero deseja localizar?: "); 
  scanf("%d", &x);

  int meio=0, esquerda = 0, direita = TAMANHO - 1; 
  int encontrado = 0;

  while (esquerda <= direita) {  
    Cont++; 
    meio = (esquerda + direita)/2;
    
    if (vetor[meio] == x) {
        encontrado = 1;
        break;
    }
    else if (vetor[meio] < x) {
      esquerda = meio + 1;
    }
    else {
      direita = meio - 1; 
    }
  }
  
  if (encontrado) {
    printf("\nValor %d localizado", x); 
  } else {
    printf("\nValor %d NAO localizado", x); 
  }

  printf("\nAcessos ao Array: %d\n", Cont); 
  return 0;
}
