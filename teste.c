#include <stdio.h>

// Função para trocar dois elementos no array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função para realizar a partição do array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Escolhe o pivô como o primeiro elemento
    int i = low + 1;      // Índice para os elementos maiores que o pivô
    int j = high;         // Índice para os elementos menores que o pivô

    while (i <= j) {
        // Encontra um elemento maior que o pivô
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        // Encontra um elemento menor que o pivô
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        // Troca os elementos encontrados
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô na posição correta
    swap(&arr[low], &arr[j]);
    return j;
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Realiza a partição do array
        int pi = partition(arr, low, high);

        // Ordena as sub-partições
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Array ordenado: ");
    printArray(arr, n);
    return 0;
}
