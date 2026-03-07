// Considerando que o arquivo "dados.dat" é formado pela estrutura abaixo:
//   *  char [35]
//   *  int 
//   *  float  
// Leia o conteúdo do arquivo e apresente na tela.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char primeiraColuna[35];
  int segundaColuna;
  float terceiraColuna;
} FormatacaoDoArquivo;

int main(void) {
  FormatacaoDoArquivo *linhaDoArquivo = (FormatacaoDoArquivo *) malloc(200 * sizeof(FormatacaoDoArquivo)); // exige o stdlib.h
  FILE *arquivoParaLer; // exige o stdio.h

  if (linhaDoArquivo == NULL) {
    printf("Erro ao alocar memória");
    return 1;
  }

  if ((arquivoParaLer = fopen("dados.dat", "rb")) == NULL) {
    printf("Erro ao abrir o arquivo");
    free(linhaDoArquivo);
    return 1;
  }

  int tamanho = 0;

  while (!feof(arquivoParaLer)) {
    fread(&linhaDoArquivo[tamanho], sizeof(FormatacaoDoArquivo), 1, arquivoParaLer);
    tamanho++;
  }
  
  fclose(arquivoParaLer);

  for (int i = 0; i < tamanho-1; i++) {
    printf("%-35s \t %d \t %f\n",
           linhaDoArquivo[i].primeiraColuna,
           linhaDoArquivo[i].segundaColuna,
           linhaDoArquivo[i].terceiraColuna
          );
  }

  free(linhaDoArquivo);
  
  return 0;
}