// Crie um programa que apresente um menu com as seguintes opções:

// Carregar arquivo na memória
// Ordenar dados
// Procurar registro por código
// Sair
// a) Utilize realocação dinâmica de memória (função realloc) para carregar os dados do arquivo, garantindo o correto uso de ponteiros.

// b) Implemente um algoritmo de ordenação dos dados.

// c) Implemente uma função eficiente para localizar registros.

// d) Obedeça à seguinte estrutura do arquivo binário a ser lido:

//     typedef struct {
//         int icodigo;
//         char sproduto[100];
//         char scategoria[30];
//         float fpreco;
//         int iestoque;
//     } DADOS;