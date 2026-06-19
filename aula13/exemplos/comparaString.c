#include <stdio.h>
#include <string.h>

int main() {
  char string1[30];
  char string2[30];

  printf("Digite uma string: ");
  scanf("%s", string1);

  printf("Digite outra string: ");
  scanf("%s", string2);

  if (strcmp(string1, string2) == 0) {
    printf("strings iguais\n");
  } else if (strcmp(string1, string2) < 0) {
    printf("%s antes de %s", string1, string2);
  } else if (strcmp(string2, string1) > 0) {
    printf("%s antes de %s", string1, string2);
  }

  return 0;
}