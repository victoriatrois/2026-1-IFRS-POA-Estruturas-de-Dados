// Atividade 02 - Árvores
// Atividade – Geração de Palavras Utilizando Grafos

// Considere o seguinte Grafo, que representa as conexões entre letras:

// {
//  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
//  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//  {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
//  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//  {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
// }

// Deseja-se verificar todas as combinações possíveis que podem formar palavras a partir de cada letra inicial.

// Para isso, utilize um vetor auxiliar, em que cada índice corresponde a uma letra:

// vetor[0] = A
// vetor[1] = C
// vetor[2] = M
// vetor[3] = N
// vetor[4] = O
// vetor[5] = R
// vetor[6] = S
// vetor[7] = T

// A saída do programa deverá apresentar o caminho percorrido utilizando os índices do vetor e sua respectiva conversão para caracteres.

// Exemplo:

// Se o percurso encontrado for:

// 7 → 4 → 5 → 0 → 2

// A saída deverá ser exibida como:

// 7[T] → 4[O] → 5[R] → 0[A] → 2[M]

// ou, de forma textual:

// TORAM

// O programa deve percorrer o grafo e imprimir todas as combinações válidas encontradas.


// Critérios de Correção
// • 1,0 ponto
// Se o programa compilar e executar corretamente, e se o arquivo for nomeado conforme o padrão: <matricula>-prv02_q02.cpp  onde <matricula> corresponde à matrícula do estudante no SIGAA.

// • 1,0 pontos
// Se o programa apresentar a saída,  numérica. 

// • 2,0 pontos
// Se o programa apresentar a saída correta, utilizando caracteres. 

// • 1,0 ponto

// Entrada a partir de uma letra inicial, com validação de entrada (existente).