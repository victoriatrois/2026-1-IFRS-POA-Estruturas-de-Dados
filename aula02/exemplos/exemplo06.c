#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[20];
  int idade;
} Cpessoa;

int main(void) {
  char condicao = 's';
  Cpessoa aluno;
  FILE *bin;

  if((bin = fopen("arquivo_binario.txt","ab")) == NULL) {
    printf("Erro ao abrir arquivo");
  }

  while (condicao == 's' || condicao == 'S') {
    printf("Informe o nome:"); 
    scanf("%s", aluno.nome);
  
    printf("Informe a idade:"); 
    scanf("%d", &aluno.idade);
    getchar();
    
    // método usado para escrever em arquivos co modo de escrita "<modo_base>b"
    fwrite(&aluno, 1, sizeof(aluno), bin);
    
    printf("Continuar S/N?:"); 
    scanf("%c", &condicao);
  }
}

