# Estruturas de Dados - 2026.1

## 23/02 - 01 Apresentação. Revisão de Comandos C de Leitura e Escrita em Arquivos

Em c, um arquivo é um fluxo de bytes.

Cada arquivo tem um marcador de final.

Um arquivo, nada mais é que uma árvore balanceada.

Existem métodos para percorrer os arquivos e manipulá-los. Para tal, precisamos informar o modo de abertura que queremos utilizar.

### Modos de abertura

#### r

abre para leitura; arquivo precisa existir.

#### w

abre para escrita; cria se não existir e apaga todo conteúdo se existir.

#### a (append)

abre para escrita no fim; cria se não existir, nunca apaga o que já tinha.

> Em a e a+, mesmo que você mova o cursor com fseek, a escrita continua indo para o final.

#### r+

leitura e escrita; arquivo precisa existir; não apaga conteúdo.

> Em r+, você pode sobrescrever bytes no meio do arquivo.

#### w+

leitura e escrita; cria se não existir e zera conteúdo se existir.

#### a+

leitura e escrita; cria se não existir; escrita é sempre no fim.

#### `<modo base>`b

Executa a mesma operação, só que o arquivo é binário. Ex. a+b, wb, r+b/rb+, etc.

### Métodos de manipulação

#### fopen

retorna um ponteiro do tipo FILE

`FILE *fopen (char *nome_do_arquivo,char *modo);`

#### desafio do exemplo 01

troca a posição do código para o final, nos parâmetros passados no fopen()

#### fclose

libera o ponteiro alocado para a abertura do arquivo, sempre deve ser chamado

`int fclose (FILE *fp);`

#### feof

informa o fim do arquivo

`int feof (FILE *fp);`

#### fscanf

lê dados formatados de um arquivo

`int fscanf (FILE *fp,char *str,variavél);`

#### fprintf

`int fprintf (FILE *fp,char *str,...);`

##### desafio do exemplo 02

Se o número for par, imprimir "par"

#### fgetc

Lê o caractere presente na posição atual do fluxo interno. Após a leitura, a posição atual é avançada para o próximo caractere.

```c
int fgetc (FILE * fp);
```

> extremamente lento

##### desafio do exemplo 04

se tiver um a minúsculo, trocar por um X

TODO
[x] revisar os exemplos, anotar os códigos pertinentes
[x] Atividade 01
[x] Atividade 02

> dica: usar um vetor, alocação manual

[x] Atividade 03
[x] Atividade 04

## 02/03

#### fgets

- lê caracteres até
  - encontrar o \n, que é incluído na string
  - ler o tamanho máximo informado menos 1
  - chegar até o fim do arquivo
- retorna um ponteiro de char em caso de sucesso
- retorna NULL em caso de esso ou fim do arquivo

```c
// sintaxe
char * fgets(char * string, int tamanho, FILE * fluxo);

#include <stdio.h>
#include <stdlib.h>

int main() {
  char linha[1024]; 
  FILE *txt = fopen("arquivo_texto.txt","r")
  if(txt == NULL) {
    printf("Erro ao abrir arquivo");
  } else {
    while (!feof(txt)) {
      fgets(linha, 1024, txt);
      printf("%s", linha);
    }
    fclose(txt);
  }
  return 1;
  }
```

> ao contrário de scanf("%s"), o fgets lê espaços em branco e preserva a quebra de linha no final da string.

#### strtok

- divide uma string em tokens (partes menores) com base no delimitador informado.

```c
// sintaxe
char *strtok(char *str, const char *delim);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char linha[1024]; 
  char * ultima;
  FILE *txt = fopen("c:\\arquivo.txt","r");

  if(txt == NULL) {
    printf("Erro ao abrir arquivo");
  } else {
    while (!feof(txt)) {
      fgets(linha, 1024, txt);
      ultima = strtok (linha, " ");

      while (ultima != NULL) {
        printf ("%s ",ultima);
        ultima = strtok (NULL, " ");
      }
    }

    fclose(txt);
  }
  return 1;
}
```

> Qual o tamanho indicado? para a linha
> 4K

> BOA QUESTÃO PARA PROVA
> como faz um programa que conta quantas vezes uma palavra aparece num texto?

## 02/03 - 02 Tipos de alocação de memória. Representação dos dados. Listas. Pilhas. Filas.

### Tipos de dados

#### Dados simples, ou primitivos:

  - Tipo de dado vinculado a uma certa variável
  - Determina quais valores a variável pode ter e quais operações nas quais ela pode estar envolvida
  - Têm uma única posição fixa de memória

#### Dados compostos

Estruturas que armazenam múltiplos valores e podem ser de tipos iguais ou diferentes

São usados para organizar e manipular conjuntos de dados de forma eficiente.

##### Homogêneos
Estruturas formadas por dados de tipos diferentes, como structures com membros de ao menos dois tipos diferentes

##### Heterogêneos

São estruturas de dados de um mesmo tipo, como vetores, matrizes e structures com membros do mesmo tipo.

Todo vetor é um ponteiro, daí posso:

- atribuir um vetor a um ponteiro
- 


###### Structures, Structs ou Resgistros

Uma structure 

TODO: ver onde cabe
> Atribuir uma variável a um ponteiro, dará erro, pois a variável armazena o seu endereço e o seu valor.
> & é utilizado pra 
> Variável tem endereço e dado

Diferenças fundamentais:

| Aspecto      | Dados Simples  | Dados Compostos           |
| ------------ | -------------- | ------------------------- |
| Valores      | Um único valor | Múltiplos valores         |
| Complexidade | Básico         | Estruturado               |
| Acesso       | Direto         | Por índice/nome/chave     |
| Tamanho      | Fixo e pequeno | Variável, pode ser grande |

### Arquivos Binários

#### fwrite

Escrever em arquivos binários

```c
size_t fwrite(
  void * dados, 
  size_t tamanho,
  size_t numero_de_itens,
  FILE * arquivo);
```

#### fread

Escrever em arquivos binários

```c
size_t fwrite(
  void * dados, 
  size_t tamanho,
  size_t numero_de_itens,
  FILE * arquivo);
```

mat[5] == p*(mat+5)


### Alocação dinâmica

Alocação em tempo de execução (na heap)

#### malloc (memory allocation)

- aloca um bloco contínuo de memória com tamanho não expecificado
- NÃO inicializa a memória
- contém lixo e valores aleatórios
- retorna o ponteiro do início do bloco alocado
- retorna NULL ao falhar ou ao ter memória insuficiente

> É necessário liberar a memória com o `free()`
> É mais seguro validar se o malloc teve cucesso verificando se ele retorna nulo

```c
// sintaxe
void *malloc(size_t tamanho);

// Aloca memória para 1 inteiro
int *num = (int *)malloc(sizeof(int));
*num = 42;
free(num);

// Aloca array de 10 inteiros
int *arr = (int *)malloc(10 * sizeof(int));
arr[0] = 1;  // Valores não são inicializados, contêm lixo
arr[1] = 2;
free(arr);

// Aloca string de 100 caracteres
char *str = (char *)malloc(100 * sizeof(char));
strcpy(str, "Olá");
free(str);
```
 
#### calloc (continuous allocation)

- aloca memória dinâmicamente para um array de elementos
- inicializa todos os bytes como 0
- retorna o ponteiro para o início do bloco alocado
- retorna NULL ao falhar

```c
// sintaxe
void *calloc(size_t numero_de_elementos, size_t tamanho_de_cada_elemento);

// Aloca array de 10 inteiros, todos inicializados com 0
int *arr = (int *)calloc(10, sizeof(int));
// arr[0] = 0, arr[1] = 0, ..., arr[9] = 0

// Aloca string de 100 caracteres, todos '\0'
char *str = (char *)calloc(100, sizeof(char));
// str[0] = '\0', str[1] = '\0', ...

free(arr);
free(str);
```

#### realloc 

- cria um novo bloco de memória alocando mais ou menos memória em relação ao bloco anteriormente alocado
- move o ponteiro do bloco anterior para o novo
- se livra do bloco anterior após a realocação
- retorna NULL ao falhar e NÃO libera o bloco original
- passar zero como parâmetro funciona como o `free()`

```c
// sintaxe
void *realloc(void *ponteiro, size_t novo_tamanho);

// Aloca inicialmente 10 inteiros
int *arr = (int *)malloc(10 * sizeof(int));
arr[0] = 1;
arr[1] = 2;

// Agora precisa de 20 inteiros
arr = (int *)realloc(arr, 20 * sizeof(int)); // é necessário reatribuir o valor como mostrado aqui
// arr[0] e arr[1] ainda têm os valores 1 e 2
// Agora pode usar arr[0] até arr[19]
  free(arr);

// pode-se usar um ponteiro temporário para ter mais segurança
int *temp = realloc(arr, novo_tamanho);
if (temp == NULL) {
    // Erro: memória insuficiente, arr ainda é válido
    free(arr);
    return 1;
}
arr = temp; // vetor atualizado
```

> lento, fazer realocações de bloco 1000 / 10000

#### free

- libera a memória previamente alocada para o ponteiro informado (via malloc ou calloc)
- evita vazamento de memória

```c
// sintaxe
void free(void *ponteiro);

// Aloca memória
int *p = (int *)malloc(100 * sizeof(int));

// Usa a memória
p[0] = 10;
p[1] = 20;

// Libera a memória quando não precisar mais
free(p);
```

> usar o free quando precisar desalocar memória e não finalizar o programa

passar para o caderno:
```c
#include <stdlib.h>
#include <stdio.h>
  int main() {
  int n=0;
  int *pn = &n;

  n = 2015;

  printf("Valor de n: %d \n", n);
  printf("Endereco de n: %x \n", &n);
  printf("Conteudo do Ponteiro de n: %d \n", *pn);
  printf("Ponteiro de n: %x \n", pn);
}
```

## TODO

[x] Desafio em aula 01
[x] Desafio em aula 02
[x] Atividade 01
[x] Atividade 02

# DICAS PARA PROVA:

- ler ordenar e gravar binário
- qual a vantagem de escrever em arq bin? É mais rápido
- Questão de prova:
```c
#include <stdio.h>
#include <stdlib.h> 

int main() { 
  int *a, *b;
  a = (int * ) malloc ( sizeof(int) * 100);
  b = (int * ) malloc ( sizeof(int) * 3 );
 
  for (int i = 0; i< 100; i++) {
    a[i] = i; 
  }

  b[0] = 0; 
  b[1] = 1; 
  b[2] = 2; 

  printf("valor %d - endereco %p \n", a[0] ,&a[0]); 
  printf("valor %d - endereco %p \n", a[1], &a[1]); 
  printf("valor %d - endereco %p \n", a[2], &a[2]); 
  printf("valor %d - endereco %p \n", b[0], &b[0]); 
  printf("valor %d - endereco %p \n", b[1], &b[1]); 
  printf("--> a %d\n", sizeof *a); 
  system("pause");
  return(0);
}
```

## 09/03 - 04 Algoritmos de ordenação

Busca sequencial (O(n) - um acesso por elemento do conjunto), busca binária, busca por interpolação, busca em árvore, Hashing ou tabela de dispersão (O(1) - um acesso por busca)

> Busca por árvore é mais rápida que a busca binária porque a inserção é mais rápida

## 16/03 - 04 Algoritmos de ordenação

Exercícios de recursividade - folhinha

```c
int ff(int n) {
  if (n==0) {
    return 1;
  }  else {
    return ff(n - 1);
    print(“%d”, n);
  }
}

int main(void) {
  print(“%d”, ff(4));
}
```

Pesquisas eficientes exigem dados ordenados (ganho de velocidade no acesso)
Ordenar dados exige processamento extra (desvantagem)

A ordenação é feita pelo índice não pelos dados em sim.

Algoritmos de ordenação podem ser estáveis e não estáveis (instáveis?)

Algoritmos estáveis não realizam trocas, caso os dados já estejam ordenados. Algoritmos instáveis realizam trocas desnecessárias.

Algoritmos famosos:
Bubblesort
Ordenação por contagem
Ordenação por inserção
Mergesort
Quicksort
Ordenação por seleção
