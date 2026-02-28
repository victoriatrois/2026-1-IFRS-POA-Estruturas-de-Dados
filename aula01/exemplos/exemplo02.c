#include <stdio.h>

int main() {
  int i;
  FILE *txt;

  // se não tiver permissão de escrita, ou espaço no disco, dará esse erro
  if ((txt = fopen("Arquivo.txt", "a+")) == NULL) {
    printf("Erro ao abrir arquivo");
  } else {
    i = 50;
    while(i < 100) {
      fprintf(txt, "%d\n", i);
      ++i;
    }
    fclose(txt);
    printf("Arquivo atualizado com sucesso\n");
  }
}
