#include <stdio.h>

main(){
int i;
FILE *txt;

// se não tiver permissão de escrita, ou espaço no disco, dará esse erro
if((txt = fopen("Arquivo.txt", "a+")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
else {
        i = 50;
        while(i < 100)
        {
              fprintf(txt, "%d", i);
              if (i %2 == 0) {
                fprintf(txt, " par");
              }
              ++i;
              printf("\n");
          }
		fclose(txt);
      }
}

