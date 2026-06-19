#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[20];
    char palavra2[20];
    int resultado;

    printf("Digite a primeira palavra: ");
    scanf("%s", palavra1);

    printf("Digite a segunda palavra: ");
    scanf("%s", palavra2);

    resultado = strcmp(palavra1, palavra2);

    if (resultado == 0) {
        printf("As palavras sao iguais.\n");
    } 
    else if (resultado < 0) {
        printf("\"%s\" vem antes de \"%s\" na ordem alfabetica.\n", palavra1, palavra2);
    } 
    else {
        printf("\"%s\" vem depois de \"%s\" na ordem alfabetica.\n", palavra1, palavra2);
    }

    return 0;
}
