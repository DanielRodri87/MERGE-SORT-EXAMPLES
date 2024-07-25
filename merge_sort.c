#include <stdio.h>
#include <stdlib.h>

// Função principal que implementa o merge sort
void mergesort(int *vetor, int tamanho);

// Função auxiliar que realiza a recursão para dividir o vetor
void ordenar(int *vetor, int *auxiliar, int inicio, int fim);

// Função que mescla os sub-vetores ordenados
void mesclar(int *vetor, int *auxiliar, int inicio, int meio, int fim);

int main(void)
{
    int i;
    // Vetor exemplo (substitua pelos pratos de Juninho: [6, 1, 3, 4, 2, 5])
    int vetor[6] = {6, 1, 3, 4, 2, 5};

    // Chama a função mergesort para ordenar o vetor

    // Imprime o vetor desordenado
    printf("Vetor original: ");
    for (i = 0; i < 6; i++)
        printf("%d ", vetor[i]);

    
    // Chama a função mergesort para ordenar o vetor
    mergesort(vetor, 6);


    // Imprime o vetor ordenado
    printf("\nVetor ordenado: ");
    for (i = 0; i < 6; i++)
        printf("%d ", vetor[i]);

    putchar('\n');

    return 0;
}

// Função mergesort: Inicializa um vetor auxiliar e chama a função de ordenação
void mergesort(int *vetor, int tamanho)
{
    // Aloca memória para o vetor auxiliar
    int *auxiliar = malloc(sizeof(int) * tamanho);

    // Chama a função de ordenação
    ordenar(vetor, auxiliar, 0, tamanho - 1);

    // Libera a memória alocada para o vetor auxiliar
    free(auxiliar);
}

// Função ordenar: Realiza a divisão recursiva do vetor
/*

vetor = vetor original
auxiliar = vetor auxiliar
inicio = índice inicial
fim = índice final

*/
void ordenar(int *vetor, int *auxiliar, int inicio, int fim)
{
    // Caso base: Se o sub-vetor tem 1 ou 0 elementos, já está ordenado
    if (inicio >= fim)
        return;

    // Calcula o índice do meio do vetor
    int meio = (inicio + fim) / 2;

    // Ordena recursivamente a primeira metade
    ordenar(vetor, auxiliar, inicio, meio);

    // Ordena recursivamente a segunda metade
    ordenar(vetor, auxiliar, meio + 1, fim);

    // Se o último elemento da primeira metade é menor ou igual ao primeiro da segunda metade, já está ordenado
    if (vetor[meio] <= vetor[meio + 1])
        return;

    // Mescla os sub-vetores ordenados
    mesclar(vetor, auxiliar, inicio, meio, fim);
}

// Função mesclar: Mescla dois sub-vetores ordenados em um único vetor ordenado

/*
vetor = vetor original
auxiliar = vetor auxiliar
inicio = índice inicial
meio = índice do meio
fim = índice final

*/
void mesclar(int *vetor, int *auxiliar, int inicio, int meio, int fim)
{
    // indVetorInicio = índice da primeira metade, indVetorMeio = índice da segunda metade
    int z, indVetorInicio = inicio, indVetorMeio = meio + 1;

    // Copia os elementos do vetor original para o vetor auxiliar
    for (z = inicio; z <= fim; z++)
        auxiliar[z] = vetor[z];

    z = inicio;

    // Mescla os dois sub-vetores ordenados
    while (indVetorInicio <= meio && indVetorMeio <= fim)
    {
        // Compara os elementos e coloca o menor no vetor original
        if (auxiliar[indVetorInicio] <= auxiliar[indVetorMeio])
        {
            vetor[z++] = auxiliar[indVetorInicio++];
        }
        else
            vetor[z++] = auxiliar[indVetorMeio++];
    }

    // Copia os elementos restantes da primeira metade, se houver
    while (indVetorInicio <= meio)
    {
        vetor[z++] = auxiliar[indVetorInicio++];
    }

    // Copia os elementos restantes da segunda metade, se houver
    while (indVetorMeio <= fim)
    {
        vetor[z++] = auxiliar[indVetorMeio++];
    }
}
