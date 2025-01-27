#include <stdio.h>

// Função Insertion Sort
void insertionSort(int arr[], int n) {
    int x, y, chave;
    for (x = 1; x < n; x++) {
        chave = arr[x];
        y = x - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (y >= 0 && arr[y] > chave) {
            arr[y + 1] = arr[y];
            y = y - 1;
        }
        arr[y + 1] = chave;
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int n) {
    for (int x = 0; x < n; x++) {
        printf("%d ", arr[x]);
    }
    printf("\n");
}

// Função principal
int main() {
    int numeros[] = {5, 3, 8, 4, 2};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    printf("Array antes da ordenação:\n");
    imprimirArray(numeros, n);

    insertionSort(numeros, n);

    printf("Array após a ordenação:\n");
    imprimirArray(numeros, n);

    return 0;
}
