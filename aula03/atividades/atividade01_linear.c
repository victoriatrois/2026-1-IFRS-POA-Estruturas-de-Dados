// Considerando o arquivo DADOS.ZIP, cujo conteúdo está ordenado,
// altere os códigos de busca sequencial e busca binária para
// carregar o conteúdo do arquivo ASCII para um vetor. 
// Logo após o carregamento, faça a contagem de acessos necessários para localizar os seguintes valores:
  // 7341488
  // 85
  // 265654
  // 732765
  // 8313596
  // 45744
// Considerando todos as pesquisas,
//   quantos acessos (no total) cada método de busca teve?
//   qual foi o ganho de desempenho do algoritmo mais eficiente em relação ao menos eficiente?

#include <stdio.h> 
#include <stdlib.h> 
#define TAMANHO 995332

int main(void) {
  int numerosCarregadosEmMemoria[TAMANHO];
  FILE *arquivo = fopen("dados.txt", "r");

  int numeroDeAcessos = 0;
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
    printf("Busca %d:\n", i + 1);

    numeroDeAcessos = 0;

    while (
      numeroDeAcessos < numerosLidos &&
      numerosCarregadosEmMemoria[numeroDeAcessos] != numerosDeInteresse[i]
    ) {
      numeroDeAcessos++;
    }

    if (numeroDeAcessos < numerosLidos && 
        numerosCarregadosEmMemoria[numeroDeAcessos] == numerosDeInteresse[i]) {
      printf(
        "Total de acessos para achar o número %d: %d\n\n",
        numerosDeInteresse[i],
        numeroDeAcessos + 1
      );
    } else {
      printf("Valor %d NAO localizado\n", numerosDeInteresse[i]);
      printf("Total de acessos para identificar que o número não existia no conjunto de dados: %d", numeroDeAcessos + 1);
    }
  }
}
