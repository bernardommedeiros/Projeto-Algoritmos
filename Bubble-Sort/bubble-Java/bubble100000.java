import java.util.Random;

public class bubble100000 {

    public static void bubbleSort(int arr[]) {
        int x, y, temp;
        boolean troca;
        int n = arr.length;

        for (x = 0; x < n - 1; x++) {
            troca = false; // verifica troca
            for (y = 0; y < n - 1 - x; y++) {
                if (arr[y] > arr[y + 1]) {
                    // Troca os elementos
                    temp = arr[y];
                    arr[y] = arr[y + 1];
                    arr[y + 1] = temp;
                    troca = true;
                }
            }

            if (!troca) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();

        int[] numerosAleatorios = new int[100000]; 

        for (int i = 0; i < 100000; i++) {
            numerosAleatorios[i] = rand.nextInt(101);
        }

        int n = numerosAleatorios.length;

        long inicio = System.currentTimeMillis();

        // ordenar o array
        bubbleSort(numerosAleatorios);

        long fim = System.currentTimeMillis();

        double tempoExecucao = (fim - inicio) / 100000.0;

        System.out.printf("Tempo de execução: %.6f segundos%n", tempoExecucao);
    }
}
