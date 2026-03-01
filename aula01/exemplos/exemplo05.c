#include <stdio.h>
#include <stdlib.h>

main() {
  char linha[1024]; 

  FILE *txt = fopen("arquivo_texto.txt","r");

  if(txt == NULL) {
    printf("Erro ao abrir arquivo");
  }

  while (!feof(txt)) {
    fgets(linha, 1024, txt);
    printf("%s", linha);
    system("pause");
  }
  fclose(txt);
  system("pause"); 
}
