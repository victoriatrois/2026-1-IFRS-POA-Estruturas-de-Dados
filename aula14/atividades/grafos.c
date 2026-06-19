// Considere o conjunto de cidades do Rio Grande do Sul representado pelos índices abaixo:

// 0 - Porto Alegre
// 1 - Canoas
// 2 - Novo Hamburgo
// 3 - Gramado
// 4 - Caxias do Sul
// 5 - Passo Fundo
// 6 - Erechim
// 7 - Santa Maria
// 8 - Pelotas
// 9 - Rio Grande

// As conexões entre as cidades são dadas pelas seguintes arestas:

// 0 → 1 : 18 km
// 0 → 2 : 45 km
// 1 → 4 : 115 km
// 2 → 3 : 75 km
// 3 → 4 : 70 km
// 4 → 5 : 145 km
// 5 → 6 : 80 km
// 4 → 7 : 290 km
// 7 → 8 : 260 km
// 8 → 9 : 60 km

// Desenvolva um programa utilizando grafos e matriz de adjacência para verificar se existe uma rota disponível entre duas cidades.
// Caso não exista ligação entre duas cidades, o valor da posição na matriz deve ser 0.

// a) O programa deve apresentar ao usuário:

// 0 - Porto Alegre
// 1 - Canoas
// 2 - Novo Hamburgo
// ...
// b) O usuário deverá informar:

// cidade de origem;
// cidade de destino.

// (Utilize os índices das cidades para entrada dos dados).

// c) Realizar a busca da rota, utilizando um algoritmo de percurso em grafos DFS (Busca em Profundidade), ou
// BFS (Busca em Largura). O algoritmo deve percorrer o grafo verificando se existe caminho entre a origem e o destino.

// d) Apresentar o resultado, se existe rota entre as cidades  ou se não existe caminho disponível.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CIDADES 10

typedef struct {
  int distancia[NUM_CIDADES][NUM_CIDADES];
  char* nome[NUM_CIDADES];
} CidadesVizinhas;

CidadesVizinhas mapa = {
  .nome = {
    "Porto Alegre",
    "Canoas",
    "Novo Hamburgo",
    "Gramado",
    "Caxias do Sul",
    "Passo Fundo",
    "Erechim",
    "Santa Maria",
    "Pelotas",
    "Rio Grande"
  },
  .distancia = {
    {0, 18, 45, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 115, 0, 0, 0, 0, 0},
    {0, 0, 0, 75, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 70, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 145, 0, 290, 0, 0},
    {0, 0, 0, 0, 0, 0, 80, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 260, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 60},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  }
};


void exibeCidades(CidadesVizinhas *g) {
  printf("\nCidades disponíveis para busca\n");
  for (int i = 0; i < NUM_CIDADES; i++) {
    printf("%d - %s\n", i, g->nome[i]);
  }
  printf("\n\n");
}

int dfs(CidadesVizinhas *g, int atual, int destino, int visitados[]) {
  visitados[atual] = 1;

  if (atual == destino) {
    return 0;
  }

  for (int i = 0; i < NUM_CIDADES; i++) {
    if (g->distancia[atual][i] > 0 && !visitados[i]) {
        int resultado = dfs(g, i, destino, visitados);

        if (resultado >= 0) {
          return g->distancia[atual][i] + resultado;
        }
    }
  }
  return -1;
}

// BFS: Busca em Largura
bool bfs(CidadesVizinhas *g, int origem, int destino, int *distanciaEncontrada) {
    int fila[NUM_CIDADES];
    int visitados[NUM_CIDADES] = {0};
    int distancias[NUM_CIDADES] = {0};

    int primeiro = 0, ultimo = 0;

    fila[ultimo++] = origem;
    visitados[origem] = 1;
    distancias[origem] = 0;

    while (primeiro < ultimo) {
      int atual = fila[primeiro++];

      if (atual == destino) {
        *distanciaEncontrada = distancias[atual];
        return true;
      }

      for (int i = 0; i < NUM_CIDADES; i++) {
        if (g->distancia[atual][i] > 0 && !visitados[i]) {
          fila[ultimo++] = i;
          visitados[i] = 1;
          distancias[i] = distancias[atual] + g->distancia[atual][i];
        }
      }
    }
    return false;
}

int main() {
  int origem;
  int destino;
  int distancia;
  int algoritmo;
  int visitados[NUM_CIDADES] = {0};
  bool rota;

  exibeCidades(&mapa);

  printf("Digite a cidade de origem (0-9): ");
  scanf("%d", &origem);

  printf("Digite a cidade de destino (0-9): ");
  scanf("%d", &destino);

  if (origem < 0 || origem >= NUM_CIDADES || destino < 0 || destino >= NUM_CIDADES) {
    printf("\nErro: Índice de cidade inválido!\n");
    return 1;
  }
  
  if (origem == destino) {
    printf("\nA origem e o destino são a mesma cidade!\n");
    return 1;
  }
  
  printf("\nEscolha o algoritmo de busca:\n");
  printf("1. DFS - Busca em Profundidade)\n");
  printf("2. BFS - Busca em Amplitude)\n");
  printf("Digite 1 ou 2: ");
  scanf("%d", &algoritmo);

  printf("Origem: %s\n", mapa.nome[origem]);
  printf("Destino: %s\n", mapa.nome[destino]);
  printf("Algoritmo: %s\n", algoritmo == 1 ? "DFS" : "BFS");

  switch (algoritmo) {
    case 1:
      distancia = dfs(&mapa, origem, destino, visitados);
      rota = (distancia >= 0);
      break;

    case 2:
      rota = bfs(&mapa, origem, destino, &distancia);
      break;

    default:
      printf("Escolha inválida!\n");
      return 1;
  }

  if (rota) {
    printf("\nRota encontrada\n");
    printf("Distância: %d km\n", distancia);
  } else {
    printf("\nRota inexistente\n");
    printf("Não há caminho disponível entre essas cidades.\n");
  }

  printf("\n");

  return 0;
}
