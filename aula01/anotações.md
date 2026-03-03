# 23/02 - 01 Apresentação. Revisão de Comandos C de Leitura e Escrita em Arquivos

Em c, um arquivo é um fluxo de bytes.

Cada arquivo tem um marcador de final.

Um arquivo, nada mais é que uma árvore balanceada.

Existem métodos para percorrer os arquivos e manipulá-los. Para tal, precisamos informar o modo de abertura que queremos utilizar.

## Modos de abertura

### r

abre para leitura; arquivo precisa existir.

### w

abre para escrita; cria se não existir e apaga todo conteúdo se existir.

### a (append)

abre para escrita no fim; cria se não existir, nunca apaga o que já tinha.

> Em a e a+, mesmo que você mova o cursor com fseek, a escrita continua indo para o final.

### r+

leitura e escrita; arquivo precisa existir; não apaga conteúdo.

> Em r+, você pode sobrescrever bytes no meio do arquivo.

### w+

leitura e escrita; cria se não existir e zera conteúdo se existir.

### a+

leitura e escrita; cria se não existir; escrita é sempre no fim.

### `<modo base>`b

Executa a mesma operação, só que o arquivo é binário. Ex. a+b, wb, r+b/rb+, etc.

## Métodos de manipulação

### fopen

retorna um ponteiro do tipo FILE

`FILE *fopen (char *nome_do_arquivo,char *modo);`

#### desafio do exemplo 01

troca a posição do código para o final, nos parâmetros passados no fopen()

### fclose

libera o ponteiro alocado para a abertura do arquivo, sempre deve ser chamado

`int fclose (FILE *fp);`

### feof

informa o fim do arquivo

`int feof (FILE *fp);`

### fscanf

lê dados formatados de um arquivo

`int fscanf (FILE *fp,char *str,variavél);`

### fprintf

`int fprintf (FILE *fp,char *str,...);`

#### desafio do exemplo 02

Se o número for par, imprimir "par"

### fgetc

Lê o caractere presente na posição atual do fluxo interno. Após a leitura, a posição atual é avançada para o próximo caractere.

`int fgetc (FILE * fp);`

> extremamente lento

#### desafio do exemplo 04

se tiver um a minúsculo, trocar por um X

TODO
[x] revisar os exemplos, anotar os códigos pertinentes
[x] Atividade 01
[x] Atividade 02

> dica: usar um vetor, alocação manual

[x] Atividade 03
[x] Atividade 04

02/03

### fgets

`<adicionar a descrição>`

`int fgetc (FILE * fp);`

### strtok

`<adicionar a descrição>`

`<adicionar a sintaxe>`

> Qual o tamanho indicado? para a linha
> 4K

> BOA QUESTÃO PARA PROVA
> como faz um programa que conta quantas vezes uma palavra aparece num texto?

# 02/03 - 02 Tipos de alocação de memória. Representação dos dados. Listas. Pilhas. Filas.

## Tipos de dados

Dados primitivos: tipo de dado vinculado a uma determinada variável.

simples são dados com uma posição de mem
oria

dados compostos homogêneos são estruturas de vários dados de um mesmo tipo (vetores)

dados compostos heterogêneos: conjuntos de dados formados por tupos de dados primitidos diferentes organizados em uma mesma estrutura

## Resgistros / Structures

Todo vetor é um ponteiro, daí posso atribuir um vetor a um ponteiro.
Atribuir uma variável a um ponteiro, dará erro, pois a variável armazena o seu endereço e o seu valor.

& é utilizado pra 

Variável tem endereço e dado

## Arquivos Binários

### fwrite

Escrever em arquivos binários

```c
size_t fwrite(
  void * dados, 
  size_t tamanho,
  size_t numero_de_itens,
  FILE * arquivo);
```

### fread

Escrever em arquivos binários

```c
size_t fwrite(
  void * dados, 
  size_t tamanho,
  size_t numero_de_itens,
  FILE * arquivo);
```



PROVA: ler ordenar e gravar binário

PROVA: qual a vantagem de escrever em arq bin?

mat[5] == p*(mat+5)


## Alocação dinâmica
 Alocação em tempo de execução 

 malloc
`<adicionar a descrição>`

`<adicionar a sintaxe>`
 calloc
 `<adicionar a descrição>`

`<adicionar a sintaxe>`

 realloc
 `<adicionar a descrição>`

`<adicionar a sintaxe>`

> lento, fazer realocações de bloco 1000 / 10000

free

`<adicionar a descrição>`

`<adicionar a sintaxe>`

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

Questão de prova:
#include <stdio.h>
#include <stdlib.h> 
```c
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

TODO
[ ] Desafio em aula 01
[ ] Desafio em aula 02 (tá pronto)
[ ] Atividade 01
[ ] Atividade 02