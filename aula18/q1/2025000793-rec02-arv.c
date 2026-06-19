// Questão – Árvore Binária de Busca
// Considere o programa de Árvore Binária de Busca fornecido,
// que atualmente permite a inserção de valores inteiros.

// Realize as modificações necessárias para atender aos seguintes requisitos:
//   a) Ao inserir um novo número, o programa deverá informar se
//      o valor é inédito na estrutura ou se ele já existe na árvore.
//   b) Criar uma opção de menu para pesquisar um número na árvore.
//      Caso o número seja encontrado, o programa deverá informar quantas vezes
//      esse valor foi inserido na estrutura.
//   c) Criar uma opção de menu para exibir todos os elementos da árvore em ordem decrescente.

// Critérios de Correção pontos 4,0
//   1,0 ponto ✅
//     ✅O programa compila e executa corretamente.
//     O arquivo foi entregue com o nome:
//     ✅ <matricula>-rec02_arv.cpp onde <matricula> corresponde ao número de matrícula do estudante no SIGAA.
//   1,0 ponto
//     Implementação correta do item (a). ✅
//   1,0 ponto
//     Implementação correta do item (b).
//   2,0 pontos
//     Implementação correta do item (c). ✅

  #include <stdio.h>
  #include <stdlib.h>
  #include "arvore.h"

  int main(void) {
  TArvore *raiz;
  int valor;

   printf("Informe o Valor da Raiz: "); 
  scanf("%d",&valor);

  raiz = Cria(NULL, valor, NULL);

  while (valor!=0) {
    printf("Digite o Valor da Folha: "); 
    scanf("%d",&valor);

    if (valor != 0) {
      raiz = insere_binario(raiz, valor);
    }
  }

  printf("Caminhamentos na Arvore:\n\n");

  printf("\n - Pre-Ordem: \t");
  Caminhamento_Pre_Ordem(raiz);
  
  printf("\n - In-Fixado: \t");
  Caminhamento_In_Fixado(raiz);
  
  printf("\n - Pos-Fixado: \t");
  Caminhamento_Pos_Fixado(raiz);
  
  printf("\n - Decrescente:\t");
  exibeDecrescente(raiz);

  printf("\nQual o valor deseja buscar?\n");
  int comparacoesFeitas;
  scanf("%d", &valor);
  TArvore * busca = busca_binaria(raiz, valor, &comparacoesFeitas);
  
  if (busca == valor) {
    printf("Valor não encontrado\n");
  } else {
    printf("Valor \'%d\' encontrado em %d comparações\n", busca->info, comparacoesFeitas);

  }

  Destroi(raiz);
}
