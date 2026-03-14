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
  int x, i=0, vetor[TAMANHO] = {21,12,3,14,5,20,50,10,35,9,19,33,44,16,37,8,39,22,6,7};

  printf("Qual N�mero deseja localizar?:"); 
  scanf("%d",&x);

  while (i < TAMANHO && vetor[i]!=x) {
    i++;
  }

  if (vetor[i]==x) {
    printf("Valor %d Localizado!", x ); 
  } else {
    printf("Valor %d NAO Localizado!", x); 
  }
}
