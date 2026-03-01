// 3) Considerando o Exemplo05.cpp,
// altere o programa de que modo que, para cada parágrafo, ao arquivo ser impresso,
//   seja adicionada uma linha em branco

#include <stdio.h>
#include <stdlib.h>

int main() {
  char linha[1024]; 

  FILE *txt = fopen("arquivo_texto.txt","r");

  if(txt == NULL) {
    printf("Erro ao abrir arquivo");
  }

  while (!feof(txt)) {
    fgets(linha, 1024, txt);
    printf("%s", linha);
    
    if(linha[0] == '\n' || (linha[0] == '\r' && linha[1] == '\n')) {
      printf("\n");
    }
  }

  fclose(txt);
}
