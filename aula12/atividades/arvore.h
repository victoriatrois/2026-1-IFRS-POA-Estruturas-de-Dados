#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
  struct Nodo *esq;
  struct Nodo *dir;
  int matricula; // info refatorado para matricula
  char nome[30]; // nome adicionado
} TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, int matricula, char nome[30], TArvore* dir) {
  TArvore *p;

  p = (TArvore*) malloc(sizeof(TArvore));
  if (p == NULL)
      {
      printf("ERRO FATAL: Falta de Memória\n");
      getchar();
      exit(0); 

      }
  else
      {
      p->matricula = matricula;
      strncpy(p->nome, nome, 29); // sugestão da IA: usar strncpy para evitar overflow
      p->nome[29] = '\0'; // não lê mais que 29 char e finaliza o 30º com \0
      p->esq = esq;
      p->dir = dir;
      }
  return p;
  }

int Vazia(TArvore *a)
{
 if (a == NULL)
     return(1);
 else
     return(0);
}

void Caminhamento_Pre_Ordem(TArvore *a) {
  if (!Vazia(a)) {
    printf("%d %s\n", a->matricula, a->nome);
    Caminhamento_Pre_Ordem(a->esq);
    Caminhamento_Pre_Ordem(a->dir);
  }
}

void Caminhamento_In_Fixado(TArvore *a) {
  if (!Vazia(a)) {
    Caminhamento_In_Fixado(a->esq);
    printf("%d %s\n", a->matricula, a->nome);
    Caminhamento_In_Fixado(a->dir);
  }
}

void Caminhamento_Pos_Fixado(TArvore *a)
{
 if (!Vazia(a)) {
    Caminhamento_Pos_Fixado(a->esq);
    Caminhamento_Pos_Fixado(a->dir);
    printf("%d %s\n", a->matricula, a->nome);
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

TArvore *insere_binario(TArvore *a, int matricula, char nome[30]) {
  if (a == NULL) {
    a = Cria(NULL, matricula, nome, NULL);
  } else if (matricula < a->matricula) {
    a->esq = insere_binario(a->esq, matricula, nome);
  } else if (matricula > a->matricula) {
    a->dir = insere_binario(a->dir, matricula, nome);
  }
  return a;
}

TArvore *busca_binaria(TArvore *a, int matricula, int *comparacoesFeitas) {
  if (a == NULL) {
    return NULL;
  }
  
  (*comparacoesFeitas)++;

  if (matricula == a->matricula) {
    return a;
  } else if (matricula < a->matricula) {
    return busca_binaria(a->esq, matricula, comparacoesFeitas);
  } else {
    return busca_binaria(a->dir, matricula, comparacoesFeitas);
  }
}
