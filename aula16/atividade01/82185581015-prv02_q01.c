// Atividade 01 - Árvores
//   Considere o arquivo poema_horizonte.txt, disponível na Semana 16.
//   Desenvolva um programa em C/C++ que implemente a contagem de palavras utilizando uma estrutura hierárquica.

// O programa deverá:
//   a) Ao iniciar, carregar automaticamente os dados do arquivo em uma estrutura hierárquica;
//   b) Permitir a inserção de uma nova palavra após o término da carga inicial;
//   c) Permitir a pesquisa de uma palavra, informando se ela existe na estrutura e a quantidade de vezes em que aparece. Caso a palavra não seja localizada, o programa deverá informar essa condição;
//   d) Listar todas as palavras, em ordem alfabética, e o numero de ocorrências. 
//   e) Possuir opção para encerrar o programa.

// Para cada pesquisa realizada, o programa deverá apresentar o número de acessos realizados na estrutura.
// O menu do programa deverá conter as seguintes opções:
//   1) Pesquisar palavra
//   2) Inserir nova palavra
//   3) Sair

// Critérios de Correção
// • 1,0 ponto
// Se o programa compilar e executar corretamente, e se o arquivo for nomeado conforme o padrão: <matricula>-prv02_q01.cpp  onde <matricula> corresponde à matrícula do estudante no SIGAA.

// • 1,0 ponto
// Se o programa realizar corretamente a leitura do arquivo, carregar os valores na estrutura e permitir a pesquisa (somente para valores válidos), informando o número de acessos realizados, conforme solicitado nos itens a e c.

// • 1,0 ponto
// Se o programa possibilitar a inserção de uma nova palavra na estrutura, conforme solicitado no item b.

// • 2,0 pontos
// Se o programa listar todas as palavras, conforme item d.

#include <stdio.h>
#include "arvore.h"

void exibeMenu() {
  printf("Insira a opção desejada:\n");
  printf("1) Pesquisar palavra\n");
  printf("2) Inserir nova palavra\n");
  printf("3) Sair\n_");
}

int main() {
  FILE *poema = fopen("poema.txt", "r");
  if (poema == NULL) {
    printf("Erro ao abrir arquivo");
    return 1;
  }

  TArvore *poemaEmArvore = NULL;
  char palavra[47];
  int numeroDePalavrasLidas = 0;

  while (fscanf(poema, "%46s", palavra) == 1) {
    numeroDePalavrasLidas++;
    poemaEmArvore = insere_binario(poemaEmArvore, palavra);
  }
  printf("Palavras lidas: %d\n", numeroDePalavrasLidas);
  fclose(poema);

  exibeMenu();
  
  int opcaoDesejada;
  scanf("%d", &opcaoDesejada);

  switch (opcaoDesejada) {
    case 1:
      printf("\n1) Pesquisar palavra\n");
      printf("Insira a palavra que deseja buscar\n_");

      char palavraABuscar[47];
      scanf("%s", palavraABuscar);

      int totalDeAcessos = 0;
      TArvore *resultadoDaBusca = buscaBinaria(poemaEmArvore, palavraABuscar, &totalDeAcessos);
      if (resultadoDaBusca != NULL) {
        printf("Palavra \"%s\" encontrada ", resultadoDaBusca->vocabulo);
        printf("em %d acessos.\n", totalDeAcessos);
        printf("Ocorrências de \"%s\" no poema: %d\n", resultadoDaBusca->vocabulo, resultadoDaBusca->ocorrencias);
        return 0;
      } else {
        printf("Palavra inexistente no poema");
        return 0;
      }
    
    case 2:
      printf("\n2) Inserir nova palavra (ao fim do poema)\n");
      printf("Digite a palavra que deseja inserir\n_");

      char palavraAInserir[47];
      scanf("%s", palavraAInserir);

      TArvore *novaPalavra = (TArvore*) malloc(sizeof(TArvore));
      novaPalavra->esq = NULL;
      strcpy(novaPalavra->vocabulo, palavraAInserir);
      novaPalavra->dir = NULL;

      insere_binario(poemaEmArvore, palavraAInserir);

      FILE *arquivoAtualizado = fopen("poema.txt", "a");
      fprintf(arquivoAtualizado, " %s", palavraAInserir);
      fclose(arquivoAtualizado);

      return 0;

    default:
      printf("\n 3) Saindo...\n\n");
      return 0;
  }
}