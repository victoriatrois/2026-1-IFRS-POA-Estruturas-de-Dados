#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
  struct Nodo *esq;
  // a maior palavra da língua portuguesa tem 46 letras: https://www.bbc.com/portuguese/curiosidades-43938059
  char vocabulo[47];
  int ocorrencias;
  struct Nodo *dir;
} TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, char vocabulo[47], TArvore* dir) {
  TArvore *p;

  p = (TArvore*) malloc(sizeof(TArvore));
  if (p == NULL) {
    printf("ERRO FATAL: Falta de Memória\n");
    getchar();
    exit(0); 
  } else {
    p->esq = esq;
    strcpy(p->vocabulo, vocabulo);
    p->ocorrencias = 1;
    p->dir = dir;
  }
  return p;
}

int Vazia(TArvore *a) {
  if (a == NULL) {
    return(1);
  } else {
    return(0);
  }
}

void Caminhamento_Pre_Ordem(TArvore *a) {
 if (!Vazia(a)) {
    printf("%s ", a->vocabulo);
    Caminhamento_Pre_Ordem(a->esq);
    Caminhamento_Pre_Ordem(a->dir);
  }
}

void Caminhamento_In_Fixado(TArvore *a) {
 if (!Vazia(a)) {
    Caminhamento_In_Fixado(a->esq);
    printf("%s ", a->vocabulo);
    Caminhamento_In_Fixado(a->dir);
  }
}

void Caminhamento_Pos_Fixado(TArvore *a) {
  if (!Vazia(a)) {
    Caminhamento_Pos_Fixado(a->esq);
    Caminhamento_Pos_Fixado(a->dir);
    printf("%s ", a->vocabulo);
  }
}

TArvore *Destroi(TArvore *a) {
  if (!Vazia(a)) {
    Destroi(a->esq); 
    Destroi(a->dir); 
    free(a);         
  }
  return(NULL);
}

TArvore *insere_binario(TArvore *a, char vocabulo[47]) {
  if (a == NULL) {
    a = Cria(NULL, vocabulo, NULL);
  } else if (strcmp(vocabulo, a->vocabulo) < 0) {
    a->esq = insere_binario(a->esq, vocabulo);
  } else if (strcmp(vocabulo, a->vocabulo) > 0) {
    a->dir = insere_binario(a->dir, vocabulo);
  } else {
    a->ocorrencias++;
  }
  return a;
}

TArvore *buscaBinaria(TArvore *a, char vocabulo[47], int *acessos) {
  if (a == NULL) {
    return NULL;
  }
  
  (*acessos)++;
  int cmp = strcmp(vocabulo, a->vocabulo);

  if (cmp == 0) {
    return a;
  } else if (cmp < 0) {
    return buscaBinaria(a->esq, vocabulo, acessos);
  } else {
    return buscaBinaria(a->dir, vocabulo, acessos);
  }
}