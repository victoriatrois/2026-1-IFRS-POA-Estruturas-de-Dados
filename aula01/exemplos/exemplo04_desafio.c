#include <stdio.h>
#include <stdlib.h>

int main() {
  char caractere; 
  FILE *txt;

  if ((txt = fopen("arquivo.txt","r")) == NULL) {
    printf("Erro ao abrir arquivo");
    return 1;

  } else {
    while ((caractere = fgetc(txt)) != EOF) {
    printf("%c", caractere);
  }

    rewind(txt);
    printf("\n\nTexto hackeado 😜\n");
    while ((caractere = fgetc(txt)) != EOF) {
    if (caractere == 'a') {
      caractere = 'X';
    }
    printf("%c", caractere);
  }

    fclose(txt);
    return 0;
  }
}
