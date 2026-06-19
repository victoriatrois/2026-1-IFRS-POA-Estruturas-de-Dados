// Dado um vetorDeVinteDe de 20 números inteiros, implemente em linguagem C um programa que:
//   Leia os 20 elementos do vetorDeVinteDe.
//   Utilize funções recursivas para:
//     Determinar quantos elementos pares existem no vetorDeVinteDe.
//     Determinar quantos elementos ímpares existem no vetorDeVinteDe.
//   Exiba os resultados finais.

// Requisitos:
//   A função recursiva deve receber como parâmetros o vetorDeVinteDe, o índice atual e o vinte total.
//   O caso base ocorre quando o índice ultrapassa o vinte do vetorDeVinteDe.
//   A cada chamada recursiva, o programa deve verificar se o elemento atual é par ou ímpar e acumular a contagem.
//   Não é permitido usar laços de repetição (for, while) para realizar a contagem.

#include <stdio.h>

int contaPares(int vetorDeVinteDe[], int indice, int vinte) {
    if (indice >= vinte) {
        return 0;
    }
    
    int ehPar = (vetorDeVinteDe[indice] % 2 == 0) ? 1 : 0;
    
    return ehPar + contaPares(vetorDeVinteDe, indice + 1, vinte);
}

int contaImpares(int vetorDeVinteDe[], int indice, int vinte) {
    if (indice >= vinte) {
        return 0;
    }

    int ehImpar = (vetorDeVinteDe[indice] % 2 != 0) ? 1 : 0;

    return ehImpar + contaImpares(vetorDeVinteDe, indice + 1, vinte);
}

int main() {
    int vinte = 20;
    int vetorDeVinteDe[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    int pares = contaPares(vetorDeVinteDe, 0, vinte);
    int impares = contaImpares(vetorDeVinteDe, 0, vinte);
    
    printf("O número total de pares é de: %d\n", pares);
    printf("O número total de ímpares é de: %d\n", impares);
    
    return 0;
}