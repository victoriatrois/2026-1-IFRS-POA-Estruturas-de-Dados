#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigo;
    char empresa[10];
    char sobre[12];
    // Tem alguns nomes e funções que precisam de mais do que 13 bytes para serem armazenadas
    char nome[12];
    // char funcao[10];
    // faz o buffer estourar e imprimir io em lugares que não deveria
    char funcao[20];

    FILE *txt;

    // ao trabalhar com o modo r, o arquivo precisa EXISTIR, em outros modos, o arquivo é criado
    // ele deve existir no mesmo diretório do executável
    if((txt = fopen("arquivo_colunas.txt","r")) == NULL)
        {
            printf("Erro ao abrir arquivo");
        }
    else
        {
            while (!feof(txt)) {
                fscanf(txt, "%d %s %s %s %s ", &codigo, empresa, sobre, nome, funcao);
                printf("%-10s %-12s %-10s %-13s %d\n", empresa, sobre, nome, funcao, codigo);
                }
            fclose(txt);
        }
    system("pause");
}
