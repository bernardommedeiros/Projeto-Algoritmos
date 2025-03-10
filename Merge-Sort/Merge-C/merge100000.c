#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar dois subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    // Elementos são inseridos nos arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    // Mescla os arrays temporários de volta no array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para dividir e ordenar o array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Ordenar a primeira metade
        mergeSort(arr, left, mid);
        
        // Ordenar a segunda metade
        mergeSort(arr, mid + 1, right);
        
        // Mesclar as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função para medir o tempo de execução do Merge Sort
double measureExecutionTime(int arr[], int size) {
    clock_t start = clock();  // Marca o início
    mergeSort(arr, 0, size - 1);  // Executa o Merge Sort
    clock_t end = clock();  // Marca o final
    
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;  // Tempo em segundos
    return executionTime;  // Retorna o tempo em segundos
}

// Função principal
int main() {
    int arr[100000];
    
    // Gerar números aleatórios
    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 1000000;  // Números aleatórios entre 0 e 999
    }
    
    // Medir o tempo de execução do Merge Sort
    double timeTaken = measureExecutionTime(arr, 100000);
    
    // Exibir o tempo de execução com 6 casas decimais
    printf("Tempo de execução: %.6f segundos\n", timeTaken);
    
    return 0;
}