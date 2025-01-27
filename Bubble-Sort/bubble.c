#include <stdio.h>

// Função Bubble Sort
void bubbleSort(int arr[], int n) {
    int x, y, temp;
    int troca;
    for (x = 0; x < n - 1; x++) {
        troca = 0; // Verifica se houve troca
        for (y = 0; y < n - 1 - x; y++) {
            if (arr[y] > arr[y + 1]) {
                // Troca os elementos
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
                troca = 1;
            }
        }
        
        if (!troca) {
            break;
        }
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

    bubbleSort(numeros, n);

    printf("Array após a ordenação:\n");
    imprimirArray(numeros, n);

    return 0;
}
