## 11 Dado a seguinte TAD abaixo, contendo uma estrutura chamada Triangulo,  falta implementar a função (ou método) que cria o objeto triangulo e retorna o valor conforme especifico no cabeçalho do TAD

```c
#include <stdlib.h>
#include <stdio.h>
typedef struct triangulo Triangulo;
Triangulo * cria_triangulo(int a, int b, int c);
void free_triangulo(Triangulo ** t);
void set_triangulo(Triangulo * t, int a, int b, int c);
void get_triangulo(Triangulo * t);
struct triangulo
{
   int ladoa;
   int ladob;
   int ladoc;
};
Triangulo * cria_triangulo(int a, int b, int c)
{
.
.
.
.
.
.
.

}
void free_triangulo(Triangulo ** t)
{
  free(*t);
  *t = NULL;
}
void set_triangulo(Triangulo * t, int a, int b, int c){
   t->ladoa = a;
   t->ladob = b;
   t->ladoc = c;
}
void get_triangulo(Triangulo * t)
{if (t == NULL){
   printf("Erro de alocacao de memoria!\n");
}
else
{
   int a, b, c;
   a = t->ladoa;
   b = t->ladob;
   c = t->ladoc;
   if ((a == b) and (b == c))
    printf ("\nequilatero\n");
   else if ((a!=b) and (b!=c) and (c != a))
    printf ("\nescaleno\n");
   else
   printf ("\nisosceles\n");
}
}
```
Qual opção representa a forma correta de implementação da função Cria Triangulo?

a.
```c
Triangulo  cria_triangulo(int a, int b, int c)

{

 Triangulo * t = (Triangulo *) malloc (sizeof(Triangulo));

 if (t == NULL)

    {

     printf("Erro de alocacao de memoria!\n");

     exit(1);

    }

    else

    {

     t->ladoa = a;

     t->ladob = b;

     t->ladoc = c;

     return Triangulo;

    }

}
```

b.
```c
Triangulo * cria_triangulo(int a, int b, int c)

{

 Triangulo * t = (Triangulo *) malloc (sizeof(Triangulo));

 if (t != NULL)

    {

     printf("Erro de alocacao de memoria!\n");

     exit(1);

    }

    else

    {

     t->ladoa = a;

     t->ladob = b;

     t->ladoc = c;

     return * Triangulo;

    }
```

c.
```c
Triangulo * cria_triangulo(int a, int b, int c)

{

 Triangulo * t = (Triangulo *) malloc (sizeof(Triangulo));

 if (t == NULL)

    {

     printf("Erro de alocacao de memoria!\n");

     exit(1);

    }

    else

    {

     t->ladoa = a;

     t->ladob = b;

     t->ladoc = c;

     return * Triangulo;

    }

}
```

d.
```c
Triangulo * cria_triangulo(int a, int b, int c)

{

 Triangulo * t = (Triangulo *) malloc (sizeof(Triangulo));

 if (t == NULL)

    {

     printf("Erro de alocacao de memoria!\n");

     exit(1);

    }

    else

    {

     t->ladoa = a;

     t->ladob = b;

     t->ladoc = c;

     return t;

    }

}
```

e.
```c
Triangulo * cria_triangulo(int a, int b, int c)

{

 Triangulo * t = (Triangulo *) malloc (sizeof(Triangulo));

 if (t != NULL)

    {

     printf("Erro de alocacao de memoria!\n");

     exit(1);

    }

    else

    {

     t->ladoa = a;

     t->ladob = b;

     t->ladoc = c;

     return t;

    }

}
```

## 12 Se declararmos um array a de 10 inteiros, o compilador vai reservar um bloco de memória consecutivo que permita guardar esses 10 inteiros

Caso um inteiro ocupar 4 bytes, o compilador terá de reservar um bloco de 40 bytes (por exemplo, do endereço E100 até ao endereço E139.

Marque a opção de comando utilizado para reservar um bloco consecutivo de 40 Bytes acessado por um ponteiro inteiro p:

a.
```c
int p= (int *)malloc(40*sizeof(int));
```

b.
```c
int *p= (int *)malloc(40);
```

c.
```c
int &p= (int *)malloc(40));
```

d.
```c
int *p= (int *)malloc(40*sizeof(int));
```
e.
```c
int p= (int *)malloc(40*sizeof(int));
```

## 13 Marque a opção que completa que definição

"Uma estrutura de dados em lista encadeada permite na cadeia movimentos para..." 

a. para anterior, apenas.
b. para próximo, apenas.
c. para o próximo e para anterior, apenas.
d. par acima e para abaixo, apenas.
e. NDE

## 14 Dado o algoritmo de ordenação abaixo conhecido como ordenação por seleção ou selection sort que consiste em selecionar o menor item e colocar na primeira posição, selecionar o segundo menor item e colocar na segunda posição, seguindo estes passos até que reste um único elemento. Porém o gerente de TI solicitou que o código seja alterado, de forma que a partir de uma procedure (procedimento) seja impresso todo o vetor

Quais destas opções atende a solicitação do Gerente de TI?

```c
#include <stdio.h>

#include <stdlib.h>

 

main ()

{

    int num[5]= {5,4,3,2,1}, tam=5;

 

  int i, j, min;

  for (i = 0; i < (tam-1); i++) {

    min = i;

    for (j = (i+1); j < tam; j++) {

      if(num[j] < num[min]) {

        min = j;

      }

    }

    if (i != min) {

      int swap = num[i];

      num[i] = num[min];

      num[min] = swap;

    }

  }

      

       for (int q=0; q<5; q++)

       {

        printf("%d \n",num[q]);

    }

    system("pause");

}
```

a.
Chamada da Função
ver (num[5]);
Estrutura do procedimento
void ver (int vt)
{
for (int q=0; q>5; q++)
{
printf("%d ",(vt)+q);
}
}

b.
Chamada da Função
ver (num);
Estrutura do procedimento
void ver (int *vt)
{
for (int q=0; q<5; q++)
{
printf("%d ",*(vt+q));
}
}

c.
Chamada da Função
ver (*num);
Estrutura do procedimento
void ver (int vt)
{
for (int q=0; q<5; q++)
{
printf("%d ",(vt+q));
}
}

d.
Chamada da Função
ver (&num);
Estrutura do procedimento
void ver (int vt)
{
for (int q=0; q<5; q++)
{
printf("%d ",(vt)+q);
}
}

e.
Chamada da Função
ver (num);
Estrutura do procedimento
void ver (int vt)
{
for (int q=0; q>5; q++)
{
printf("%d ",*(vt)+q);
}
}

## 15 Considerando o programa abaixo, responda:

```c
main()... {
  int x[10] = {10, 11, 21, 31, 41, 51, 61, 71, 81, 91};
  int *p, a, *i;
  i = x;
  *i = 10;

  a = 10;
  i = &a;
  p = &a;
  a = 30;
  p = x;
  p = (int *) malloc(a*sizeof(int));

  if (!p) {
    printf("** Erro: Memoria Insuficiente **");
    exit (1);
  }
}
```

Qual é resultado de impressão de do conteúdo do ponteiro i no final do programa?

a. 21
b. 30
c. 91
d. 10
e. 11

## 16 Do mesmo modo que dizemos que o endereço da variável x é 0x0E20, podemos dizer que o endereço do array a é 0x0E60.

 Isto é, o endereço do array é o endereço do primeiro byte que o array ocupa.

 De fato, quando declararmos:

```c
...
int a[10];    
int *p;
p = a
...
```

 onde

```c
*p = 10; 
```

é equivalente:

a.

```c
*a[0] = 10;
```

b.

```c
&a = 10;
```

c.
N.D.A.

d.

```c
a= 10;
```

e.

```c
a[0] = 10 ;
```

## 17 Considerando a TAB abaixo, implementada por um programador Pleno, foi removido de forma acidenta a definição do registro (struct) e não há backup para recuperar o Código original.

 

Qual das opções abaixo, define corretamente a struct usada na TAD?

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista Lista;
struct lista
{
.
.
.
.
.
.
 };

```c
Lista * cria_lista(void)
{
 return (NULL); 
}
Lista * set_lista(Lista * l, int a, char s[50])
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 novo->matricula = a; 
 strcpy (novo->pessoa, s );
 novo->proximo = l;
 novo->anterior = NULL;
 if (l != NULL)
 l->anterior = novo;
 return(novo);
}
void view_lista(Lista * l)
{
Lista * pl;
 for (pl = l; pl != NULL; pl = pl->proximo)
 {
 printf("No %x Proximo: %x Anterior: %x \n", pl, pl->proximo, pl->anterior);
 }
}
int verifica_lista(Lista * l)
{
if (l == NULL) 
 printf("\nLista Vazia\n"); 
else
 printf("\nLista nao Vazia\n"); 
}
Lista * find_lista(Lista * l, int argumento)
{
 Lista * pl;
 for (pl = l; pl != NULL; pl = pl->proximo)
 {
 if (pl->matricula == argumento)
 return (pl);
 }
 return(NULL);
}

Lista * delete_elemento(Lista * pl, int argumento)
{
 Lista * anterior = NULL;
 Lista * atual = pl;
 
 while (atual != NULL && atual->matricula != argumento)
 {
 anterior = atual;
 atual = atual->proximo;
 }
if (atual == NULL)
 {
 printf ("Elemento noo localizado!\n"); 
 return(pl);
 }
 
 if (anterior == NULL)
 pl = pl->proximo; 
 else
 {
 anterior->proximo = atual->proximo;
 }
 
 free(atual);
 return(pl);
}

void free_lista(Lista ** pl)
{
 while (*pl != NULL)
 {
 Lista * t = (*pl)->proximo;
 *pl = NULL;
 free(*pl);
 *pl = t;
 }
 }

void imprime_circular_rev (Lista* l)
{
 Lista* p = l; 
if (p) 
{ 
 do {
 printf("Matricula: %d Nome: %s\n", p->matricula, p->pessoa) ; 
 p = p->proximo;
 }
 while (p != NULL);
} 
}
```

Question 17Select one:

a.
struct Lista
{
int valor;
struct Lista * proximo;
struct Lista * anterior;
char * pessoa[50];
};

b.
struct Lista
{
int matricula;
struct lista * proximo;
struct lista * anterior;
char * pessoa[50];
};

c.
struct lista
{
int * matricula;
struct Lista * proximo;
struct Lista * anterior;
char pessoa[50];
};

d.
struct lista
{
int * matricula;
struct lista * proximo;
struct lista * anterior;
char * pessoa[50];
};

e.
struct lista
{
int matricula;
struct lista * proximo;
struct lista * anterior;
char pessoa[50];
};

## 18 Marque a alternativa correta:

Question 18Select one:

a.
N.D.A.


b.
O operador * tem como significado o endereço de. O segundo operador é &, que é o complemento de &. O & é um operador unário que devolve o valor da variável localizada no endereço que indica. 


c.
O operador & tem como significado o endereço de. O segundo operador é *, que é o complemento de &. O * é um operador unário que devolve o valor da variável localizada no endereço que indica.


d.
O operador * tem como significado o valor de. O segundo operador é &, que é o complemento de *. O * é um operador unário que devolve o endereço da variável que indica.


e.
O operador & tem como significado o valor de. O segundo operador é *, que é o complemento de &. O * é um operador unário que devolve o endereço da variável que indica. 

## 19 Marque a alternativa correta:

Question 19Select one:

a.
Em uma lista circular, o primeiro elemento tem como anterior o valor NULL para indicar o primeiro nó  da lista.


b.
Em uma lista circular, o último elemento tem como próximo o primeiro elemento da lista, o que forma um ciclo.


c.
Em uma lista encadeada, o último elemento tem como próximo o primeiro elemento da lista, o que forma um ciclo.


d.
Em uma lista circular, o último elemento tem como próximo o valor NULL para indicar o final da lista.


e.
N.D.A.

## 20 Complete o espaço em branco (______) com a palavra correta:

homogeneos, somente um valor, estática, estática e sequencial, índice, dinâmica

A matriz é uma estrutura de dados que necessita de um _______para referenciar a linha e outro para referenciar a coluna para que seus elementos sejam endereçados.

Answer 1 Question 20
Choose...
A alocação _______ ocorre em tempo de compilação, ou seja, no momento em que se define uma variável ou estrutura é necessário que se definam seu tipo e tamanho. 

Answer 2 Question 20
Choose...
Uma matriz é um arranjo bidimensional ou multidimensional de alocação __________.

Answer 3 Question 20
Choose...
Em uma matriz  cada célula contém ___________e os tamanhos dos valores são os mesmos.

Answer 4 Question 20
Choose...
A alocação _______ ocorre em tempo de execução, ou seja, as variáveis e estruturas são declaradas sem a necessidade de se definir seu tamanho, pois nenhuma memória será reservada ao colocar o programa em execução.

Answer 5 Question 20
Choose...
Da mesma forma que um vetor, uma matriz é definida com um tamanho fixo, todos os elementos são________,