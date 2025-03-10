#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int pivo = arr[0];
    int menores[n], maiores[n];
    int menores_n = 0, maiores_n = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] <= pivo) {
            menores[menores_n++] = arr[i];
        } else {
            maiores[maiores_n++] = arr[i];
        }
    }

    quick_sort(menores, menores_n);
    quick_sort(maiores, maiores_n);

    for (int i = 0; i < menores_n; i++) {
        arr[i] = menores[i];
    }
    arr[menores_n] = pivo;
    for (int i = 0; i < maiores_n; i++) {
        arr[menores_n + 1 + i] = maiores[i];
    }
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Números aleatórios entre 0 e 999
    }
}

int main() {
    int arr[100];
    int n = sizeof(arr) / sizeof(arr[0]);

    generate_random_array(arr, n);

    clock_t start = clock();
    quick_sort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", time_taken);

    return 0;
}