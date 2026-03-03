#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// imprimir ao contrário

typedef struct {
  char nome[20];
  int idade;
} Cpessoa;

int main(void) {
	Cpessoa aluno[4];
  // alocando memória dinamicamente
  // paluno = (struct Cpessoa *) malloc(4*sizeof(struct Cpessoa));
	Cpessoa *paluno = aluno;
	
	strcpy(paluno->nome, "Celso de Melo");
	paluno->idade = 22;
	paluno++;
	
	strcpy(paluno->nome, "Augusto Nunes");
	paluno->idade = 22;
	paluno++;
	
	strcpy(paluno->nome, "Julia Cleria");
	paluno->idade = 23;
	paluno++;
	
	strcpy(paluno->nome, "Lucas Barroso");
	paluno->idade = 24;
	// paluno++;
	
	// paluno = aluno;
	
	for (int i = 0; i<4 ; i++) {
		printf("%s \t %d \n", paluno->nome, paluno->idade);
		paluno--;
	}

	getchar();
}
