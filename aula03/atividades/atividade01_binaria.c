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
#define TAMANHO 995332

void buscaBinaria(int lista[], int numeroDeInteresse) {
  int posicaoInicial = 0;
  int meio = 0;
  int posicaoFinal = TAMANHO - 1;
  int acessos = 0;
  int encontrado = 0;

  while (posicaoInicial <= posicaoFinal) {
    acessos++; 
    meio = (posicaoInicial + posicaoFinal)/2;
    
    if (lista[meio] == numeroDeInteresse) {
        encontrado = 1;
        break;
    }
    else if (lista[meio] < numeroDeInteresse) {
      posicaoInicial = meio + 1;
    }
    else {
      posicaoFinal = meio - 1; 
    }
  }

  if (encontrado) {
    printf(
      "Total de acessos para achar o número %d: %d\n\n",
      numeroDeInteresse,
      acessos);
  } else {
    printf("Valor %d NAO localizado\n", numeroDeInteresse);
    printf("Total de acessos para identificar que o número não existia no conjunto de dados: %d", acessos);
  }
}

int main(void) {
  int numerosCarregadosEmMemoria[TAMANHO];
  FILE *arquivo = fopen("dados.txt", "r");

  int numerosLidos = 0;
  int numerosDeInteresse[6] = {7341488, 85, 265654, 732765, 8313596, 45744};

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.");
    return 1;
  }

  while (
    numerosLidos < TAMANHO &&
    fscanf(arquivo, "%d", &numerosCarregadosEmMemoria[numerosLidos]) == 1 
  ) {
    numerosLidos++;
  }

  fclose(arquivo);

  for (int i = 0; i < 6; i++) {
    printf("Busca %d:\n", i +1);
    buscaBinaria(
      numerosCarregadosEmMemoria,
      numerosDeInteresse[i]);
  }
 
  return 0;
}
