// Faça um programa em C que leia o arquivo "dados.txt" (Código, Produto, Preço e Quantidade) e mostre os dados na tela. 

#include <stdio.h>
#include <stdlib.h>
# include <string.h>

int main() {
  int codigo;
  char produto[99];
  char categoria[21];
  float preco;
  int quantidade;
  char linha[4000];

  FILE *txt;

  if ((txt = fopen("dados.txt","r")) == NULL) {
    printf("Erro ao abrir arquivo");
    return 1;
  } 
  
  while (fgets(linha, sizeof(linha), txt)) {
    char codigo_str[10];
    char meio[200];
    
    strncpy(codigo_str, linha, 6);
    codigo_str[6] = '\0';
    codigo = atoi(codigo_str);
    
    // Parte do meio: de posição 6 até posição 124 (produto + categoria)
    strncpy(meio, linha + 6, 118);
    meio[118] = '\0';
    
    // Dividir meio em produto e categoria
    // Produto: primeiros 98 chars
    strncpy(produto, meio, 98);
    produto[98] = '\0';
    // Remove espaços à direita
    for (int i = 97; i >= 0 && produto[i] == ' '; i--) {
        produto[i] = '\0';
    }
    
    // Categoria: próximos 20 chars
    strncpy(categoria, meio + 98, 20);
    categoria[20] = '\0';
    // Remove espaços à direita
    for (int i = 19; i >= 0 && categoria[i] == ' '; i--) {
        categoria[i] = '\0';
    }
    
    sscanf(linha + 124, "%f %d", &preco, &quantidade);
    
    printf("%d \t %-95s %-20s \t %7.2f \t %d\n", codigo, produto, categoria, preco, quantidade);
  }

  fclose(txt);
  return 0;
}
