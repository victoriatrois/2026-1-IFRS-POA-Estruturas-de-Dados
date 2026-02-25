#include <stdio.h>
#include <stdlib.h>

main()
{
    int codigo;
    char empresa[10];
    char sobre[12];
    char nome[10];
    char funcao[10];

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
                fscanf(txt, "%s %s %s %s %d", &empresa, sobre, nome, funcao, &codigo);
                printf("%-10s %-12s %-10s %-10s \t %d\n", empresa, sobre, nome, funcao, codigo);
                }
            fclose(txt);
        }
    system("pause");
}
