#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSort(int arr[], int n) {
    int x, y, chave;
    for (x = 1; x < n; x++) {
        chave = arr[x];
        y = x - 1;

        // move os elementos maiores que a chave uma posição à frente
        while (y >= 0 && arr[y] > chave) {
            arr[y + 1] = arr[y];
            y = y - 1;
        }
        arr[y + 1] = chave;
    }
}

int main() {
    srand(time(0));

    int numerosAleatorios[10000];

    for (int i = 0; i < 10000; i++) {
        numerosAleatorios[i] = rand() % 10001;
    }

    int n = sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]);

    clock_t inicio = clock();

    // ordenar o array
    insertionSort(numerosAleatorios, n);

    clock_t fim = clock();

    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execução do Insertion Sort: %f segundos\n", tempo_execucao);

    return 0;
}
