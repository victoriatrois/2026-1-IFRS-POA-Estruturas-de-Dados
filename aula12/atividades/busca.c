// Dado o programa de exemplo "arvoredinamica.cpp", realize as seguintes alterações:
// Modifique a estrutura do nó da árvore para armazenar:
//   matrícula do estudante;
//   nome do estudante.

// Altere o programa para ler os dados do arquivo dados.txt e inserir todas as informações na árvore binária.
// Após o carregamento dos dados, implemente um menu com as seguintes opções:
//   [1] Buscar estudante por matrícula
//    O usuário deverá informar uma matrícula.
//    O programa deverá localizar o estudante na árvore e apresentar:
//      a matrícula;
//      o nome do estudante;
//      a quantidade de acessos/comparações realizados durante a busca.
//   [2] Listar todos os estudantes
//   O programa deverá apresentar todos os dados armazenados na árvore em ordem crescente de matrícula.

// Observação: Caso a matrícula informada não exista na árvore, o programa deverá apresentar uma mensagem informando que o estudante não foi encontrado.

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {
  char nome[30];
  int matricula;

  TArvore *raiz = NULL;
  FILE *estudantes = fopen("dados.txt", "r");

  if (estudantes == NULL) {
    printf("Erro ao abrir o arquivo");
    return 1;
  }

  char estudante[50];
  while (fgets(estudante, sizeof(estudante), estudantes) != NULL) {
    if (sscanf(estudante, "%d %29[^\n]", &matricula, nome) == 2) { // 29 characteres quaisquer até a quebra de linha
      raiz = insere_binario(raiz, matricula, nome);
    }
  }
  fclose(estudantes);

  int opcao;
  printf("1. Buscar estudante por matrícula\n");
  printf("2. Listar estudantes\n"); 

  printf("Digite a opcao escolhida:_"); 
  scanf("%d",&opcao);

  switch (opcao) {
    case 1:
      printf("Digite a matrícula pela qual deseja buscar\n");
      int matriculaABuscar;
      int numeroDeAcessos = 0;
      int *ponteiroDoNumeroDeAcessos = &numeroDeAcessos;
      scanf("%d", &matriculaABuscar);

      TArvore *busca = busca_binaria(raiz, matriculaABuscar, ponteiroDoNumeroDeAcessos);

      if (busca == NULL) {
        printf("Não há estudantes cadastrados com a matrícula informada.");
      } else {
        printf("Estudante encontrado:\n%d %s\nComparações: %d\n", 
               busca->matricula, busca->nome, numeroDeAcessos);
      }
      break;
    
    case 2:
      printf("Lista completa\n");      
      printf("\nEstudantes em ordem crescente:\n");
      Caminhamento_In_Fixado(raiz);
      printf("\n");
      
      Destroi(raiz);
      return 0;
    
    default:
      printf("Opção inválida. Encerrando...\n"); 
      return 0;
  }
}
