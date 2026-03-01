// 2) Considerando o Exemplo04.cpp,
// altere o Programa que modo que ao mostrar o conteúdo do arquivo,
//    todas as vogais tornem-se maiúsculas na tela e em uma novo arquivo, chamado Texto_Alterado.txt.

#include <stdio.h>
#include <stdlib.h>

int main() {
  char caractere; 
  FILE *arquivo = fopen("arquivo.txt","r");
  FILE *texto_alterado = fopen("Texto_Alterado.txt","w");

  if (arquivo == NULL || texto_alterado == NULL) {
    printf("Erro ao abrir arquivo");

    return 1;
  }

  while ((caractere = fgetc(arquivo)) != EOF) {
    switch (caractere) {
      case 'a':
        caractere = 'A';
        break;
      case 'e':
        caractere = 'E';
        break;
      case 'i':
        caractere = 'I';
        break;
      case 'o':
        caractere = 'O';
        break;
      case 'u':
        caractere = 'U';
        break;
    }

    fprintf(texto_alterado,"%c", caractere);
  }

  fclose(arquivo);
  fclose(texto_alterado);
  return 0;
}
