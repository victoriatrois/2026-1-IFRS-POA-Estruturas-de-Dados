// Refaça a atividade da semana 12, agora utilizando o nome do estudante
//   Menu interativo:
//     Implemente um menu com as seguintes opções:
//       Inserir Novo valor na árvore
//       Remover valor da árvore
//       Pesquisar valor na árvore
//       Imprimir a árvore (utilizando caminhamento in-fixado). 

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {
  FILE *cadastros = fopen("dados.txt", "r");

  if (cadastros == NULL) {
    printf("Erro ao abrir o arquivo");
    return 1;
  }
  
  TArvore *estudantesPorMatricula = NULL;
  TArvore *estudantesPorNome = NULL;
  char cadastro[50];
  char nome[30];
  int matricula;

  while (fgets(cadastro, sizeof(cadastro), cadastros) != NULL) {
    if (sscanf(cadastro, "%d %29[^\n]", &matricula, nome) == 2) { // 29 characteres quaisquer até a quebra de linha
      printf("%d \n", matricula);
      printf("%s \n", nome);
      estudantesPorMatricula = insere_binario(estudantesPorMatricula, matricula, nome);
      estudantesPorNome = insere_binario_alfabetico(estudantesPorNome, matricula, nome);
    }
  }
  fclose(cadastros);

  int opcao;
  printf("1. Realizar matrícula\n"); // Inserir Novo valor na árvore
  printf("2. Cancelar matrícula\n"); // Remover valor da árvore
  printf("3. Pesquisar matrícula\n"); // Pesquisar valor na árvore
  printf("4. Emitir lista de matrículas\n"); // Imprimir a árvore (utilizando caminhamento in-fixado). 

  printf("Digite a opcao escolhida:_"); 
  scanf("%d",&opcao);

  switch (opcao) {
    case 1:
      printf("Realizar matrícula\n");
      return 0;
    
    case 2:
      printf("\nCancelar matrícula:\n");
      printf("Digite a matrícula a qual deseja cancelar:\n");

      return 0;

    case 3:
      printf("\nPesquisar matrícula\n");
      printf("Digite a matrícula pela qual deseja buscar\n");
      int matriculaABuscar;
      int numeroDeAcessos = 0;
      int *ponteiroDoNumeroDeAcessos = &numeroDeAcessos;
      scanf("%d", &matriculaABuscar);

      TArvore *busca = busca_binaria(estudantesPorMatricula, matriculaABuscar, ponteiroDoNumeroDeAcessos);

      if (busca == NULL) {
        printf("Não há estudantes cadastrados com a matrícula informada.");
      } else {
        printf("Estudante encontrado:\n%d %s\nComparações: %d\n", 
               busca->matricula, busca->nome, numeroDeAcessos);
      }
      return 0;

    case 4:
      printf("\nEmitir lista de matrículas:\n");
      printf("Lista de matrículas:\n");
      Caminhamento_In_Fixado(estudantesPorMatricula);
      printf("\n");

      Destroi(estudantesPorMatricula);
      return 0;

    default:
      printf("Opção inválida. Encerrando...\n"); 
      return 0;
  }
}
