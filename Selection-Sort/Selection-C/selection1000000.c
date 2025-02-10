#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // move o limite da sublista não classificada
    for (i = 0; i < n-1; i++) {
        // Encontre o menor elemento na sublista não classificada
        min_idx = i;
        for (j = i+1; j < n; j++) {
            // Verifica se o elemento arr[j] é menor que o elemento no índice min_idx
            if (arr[j] < arr[min_idx]) {
                // Atualiza min_idx para o índice do novo menor elemento
                min_idx = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento da sublista não classificada
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


int main() {
    srand(time(0));

    int numerosAleatorios[1000000];

    for (int i = 0; i < 1000000; i++) {
        numerosAleatorios[i] = rand() % 1000001;
    }

    int n = sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]);

    clock_t inicio = clock();

    // ordenar o array
    selectionSort(numerosAleatorios, n);

    clock_t fim = clock();

    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execução do Selection Sort: %f segundos\n", tempo_execucao);

    return 0;
}
