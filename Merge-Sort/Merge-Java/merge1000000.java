import java.util.Random;

public class Merge1000000 {

    // Função para mesclar dois subarrays
    static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

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
    static void mergeSort(int[] arr, int left, int right) {
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
    static double measureExecutionTime(int[] arr) {
        long start = System.nanoTime();  // Marca o início
        mergeSort(arr, 0, arr.length - 1);  // Executa o Merge Sort
        long end = System.nanoTime();  // Marca o final

        double executionTime = (end - start) / 1e9;  // Tempo em segundos
        return executionTime;  // Retorna o tempo em segundos
    }

    // Função principal
    public static void main(String[] args) {
        int[] arr = new int[1000000];

        // Gerar números aleatórios
        Random rand = new Random();
        for (int i = 0; i < 1000000; i++) {
            arr[i] = rand.nextInt(1000);  // Números aleatórios entre 0 e 999
        }

        // Medir o tempo de execução do Merge Sort
        double timeTaken = measureExecutionTime(arr);

        // Exibir o tempo de execução com 6 casas decimais
        System.out.printf("Tempo de execução: %.6f segundos%n", timeTaken);
    }
}