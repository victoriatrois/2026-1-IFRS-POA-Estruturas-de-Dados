typedef struct Nodo {
  struct Nodo *esq;
  int info;
  struct Nodo *dir;
} TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, int info, TArvore* dir) {
  TArvore *p;

  p = (TArvore*) malloc(sizeof(TArvore));
  if (p == NULL) {
    printf("ERRO FATAL: Falta de Mem�ria\n");
    getchar();
    exit(0); 

  } else {
    // a) o programa deverá informar se o valor é inédito na estrutura ✅
    informaIneditismo();
    p->info = info;
    p->esq = esq;
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
    printf("%d ", a->info);
    Caminhamento_Pre_Ordem(a->esq);
    Caminhamento_Pre_Ordem(a->dir);
  }
}

void Caminhamento_In_Fixado(TArvore *a) {
  if (!Vazia(a)) {
    Caminhamento_In_Fixado(a->esq);
    printf("%d ", a->info);
    Caminhamento_In_Fixado(a->dir);
  }
}

void exibeDecrescente(TArvore *a) {
  if (!Vazia(a)) {
    exibeDecrescente(a->dir);
    printf("%d ", a->info);
    exibeDecrescente(a->esq);
  }
}

void Caminhamento_Pos_Fixado(TArvore *a) {
  if (!Vazia(a)) {
    Caminhamento_Pos_Fixado(a->esq);
    Caminhamento_Pos_Fixado(a->dir);
    printf("%d ", a->info);
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

//  Ao inserir um novo número, o programa deverá informar se
//  o valor é inédito na estrutura ou se ele já existe na árvore ✅
TArvore *insere_binario(TArvore *a, int info) {
  if (a == NULL) {
    a = Cria(NULL, info, NULL);
    } else if (info == a->info) {
      informaRepeticao();
      // eu deveria guardar os valores repetidos?
    } else if (info < a->info) {
      a->esq = insere_binario(a->esq, info);

    } else if (info >= a->info) {
      a->dir = insere_binario(a->dir, info);
    }
    return a;
}

void informaIneditismo() {
  printf("\nO valor sendo inserido é inédito\n");
}

void informaRepeticao() {
  printf("\nO valor sendo inserido jã existe\n");
}


TArvore *busca_binaria(TArvore *a, int valor, int *comparacoesFeitas) {
  if (a == NULL) {
    return NULL;
  }
  
  (*comparacoesFeitas)++;

  if (valor == a->info) {
    return a;
  } else if (valor < a->info) {
    return busca_binaria(a->esq, valor, comparacoesFeitas);
  } else {
    return busca_binaria(a->dir, valor, comparacoesFeitas);
  }
}
