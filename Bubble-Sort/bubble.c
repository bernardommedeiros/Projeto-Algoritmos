#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


int main() {
    srand(time(0));

    int numerosAleatorios[100];

    for(int i = 0; i < 100; i++) {
        numerosAleatorios[i] = rand() % 101;
    }

    int n = sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]);

    // Inicia o temporizador
    clock_t inicio = clock();

    // Chama a função bubbleSort para ordenar o array
    bubbleSort(numerosAleatorios, n);

    clock_t fim = clock();

    // Calcula o tempo de execução em segundos
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do Bubble Sort: %f segundos\n", tempo_execucao);

    return 0;
}
