import time
import random

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivo = arr[0]
    menores = []
    maiores = []

    for i in range(1, len(arr)):  
        if arr[i] <= pivo:
            menores.append(arr[i])
        else:
            maiores.append(arr[i])

    return quick_sort(menores) + [pivo] + quick_sort(maiores)

def quick_time():
    # gera um array de 100 elementos aleatórios
    arr = [random.randint(0, 10000) for i in range(1000)]


    start_time = time.time()
    quick_sort(arr)
    end_time = time.time()

    # Calcula o tempo de execução
    execution_time = end_time - start_time
    print(f"Tempo de execução: {execution_time:.6f} segundos")

# Executa a função para medir o tempo
quick_time()