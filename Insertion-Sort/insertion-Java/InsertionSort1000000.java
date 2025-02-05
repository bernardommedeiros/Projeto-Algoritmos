import java.util.Random;

public class InsertionSort1000000 {

    public static void insertionSort(int arr[]) {
        int x, y, chave;
        for (x = 1; x < arr.length; x++) {
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

    public static void main(String[] args) {
        Random rand = new Random();

        int[] numerosAleatorios = new int[1000000]; // Array com 1.000.000 de elementos

        for (int i = 0; i < 1000000; i++) {
            numerosAleatorios[i] = rand.nextInt(1000001); // Gera valores aleatórios entre 0 e 1.000.000
        }

        int n = numerosAleatorios.length;

        long inicio = System.currentTimeMillis();

        // Ordenar o array
        insertionSort(numerosAleatorios);

        long fim = System.currentTimeMillis();

        double tempoExecucao = (fim - inicio) / 1000.0;

        System.out.printf("Tempo de execução do Insertion Sort: %.6f segundos%n", tempoExecucao);
    }
}
