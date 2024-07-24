#include <stdio.h>
#include <stdlib.h>

// Função principal que implementa o merge sort
void mergesort(int *v, int n);

// Função auxiliar que realiza a recursão para dividir o vetor
void sort(int *v, int *c, int i, int f);

// Função que mescla os sub-vetores ordenados
void merge(int *v, int *c, int i, int m, int f);

int main(void)
{
    int i;
    // Vetor exemplo (substitua pelos pratos de Juninho: [6, 1, 3, 4, 2, 5])
    int v[6] = {6, 1, 3, 4, 2, 5};

    // Chama a função mergesort para ordenar o vetor
    mergesort(v, 6);

    // Imprime o vetor ordenado
    for (i = 0; i < 6; i++)
        printf("%d ", v[i]);

    putchar('\n');

    return 0;
}

// Função mergesort: Inicializa um vetor auxiliar e chama a função de ordenação
void mergesort(int *v, int n)
{
    // Aloca memória para o vetor auxiliar
    int *c = malloc(sizeof(int) * n);

    // Chama a função de ordenação
    sort(v, c, 0, n - 1);

    // Libera a memória alocada para o vetor auxiliar
    free(c);
}

// Função sort: Realiza a divisão recursiva do vetor
void sort(int *v, int *c, int i, int f)
{
    // Caso base: Se o sub-vetor tem 1 ou 0 elementos, já está ordenado
    if (i >= f)
        return;

    // Calcula o índice do meio do vetor
    int m = (i + f) / 2;

    // Ordena recursivamente a primeira metade
    sort(v, c, i, m);

    // Ordena recursivamente a segunda metade
    sort(v, c, m + 1, f);

    // Se o último elemento da primeira metade é menor ou igual ao primeiro da segunda metade, já está ordenado
    if (v[m] <= v[m + 1])
        return;

    // Mescla os sub-vetores ordenados
    merge(v, c, i, m, f);
}

// Função merge: Mescla dois sub-vetores ordenados em um único vetor ordenado
void merge(int *v, int *c, int i, int m, int f)
{
    int z, iv = i, ic = m + 1;

    // Copia os elementos do vetor original para o vetor auxiliar
    for (z = i; z <= f; z++)
        c[z] = v[z];

    z = i;

    // Mescla os dois sub-vetores ordenados
    while (iv <= m && ic <= f)
    {
        // Compara os elementos e coloca o menor no vetor original
        if (c[iv] <= c[ic])
            v[z++] = c[iv++];
        else
            v[z++] = c[ic++];
    }

    // Copia os elementos restantes da primeira metade, se houver
    while (iv <= m)
        v[z++] = c[iv++];

    // Copia os elementos restantes da segunda metade, se houver
    while (ic <= f)
        v[z++] = c[ic++];
}
