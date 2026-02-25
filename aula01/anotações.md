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

### desafio do exemplo 02

Se o número for par, imprimir "par"

### fgetc

Lê o caractere presente na posição atual do fluxo interno. Após a leitura, a posição atual é avançada para o próximo caractere.

`int fgetc (FILE * fp);`

> extremamente lento

#### desafio do exemplo 04

se tiver um a minúsculo, trocar por um X

TODO
[ ] revisar os exemplos, anotar os códigos pertinentes
[ ] Atividade 01
[ ] Atividade 02

> dica: usar um vetor, alocação manual

[ ] Acividade 03
[ ] Acividade 04
