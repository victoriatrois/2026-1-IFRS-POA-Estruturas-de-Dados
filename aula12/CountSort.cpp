#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, int size) {
  int i, min, max;
  int j=0;

  min = max = array[0]; // menor e maior só pode ser iguais nesse ponto

  //Identifica o Maior Elemento
  for(i = 1; i < size;  i++) {
    if (array[i] < min) {
      min = array[i];
    } else if (array[i] > max) {
      max = array[i];
    }
 }
  int range = max - min + 1; // entender um pouco melhor essa linha
  int *count = (int *) malloc(range * sizeof(int)); // cria o vetor auxiliar para contagem

  //Marca Todas as posições com Zero
  for(i = 0; i < range; i++) { // main copy é mais rápido
    count[i] = 0;
  }

  //Marca as posições ocupadas
  for(i = 0; i < size; i++) {
    count[array[i] - min]++; // primeiro pulo do gato
  }

  int indice;
  indice=0;

  //Array recebe as posições ocupadas
  for(i = min; i <= max; i++) {
    for(j = 0; j < count[ i - min ]; j++) {
      array[indice] = i; // segundo pulo do gato
      indice++;
    }
  }
  free(count);
}

int main() {
  //Inicializão do Vetor
  int v[5] = {10, 7, 4, 3, 5};
  int n = 5;
  int i, j = 0, aux;

  //Algoritmo de Ordenação 
  counting_sort(v, n);

  //Laço de impressão do Vetor
  for (int q = 0; q < 5; q++) {
      printf("%d\n",v[q]);
  }
}
