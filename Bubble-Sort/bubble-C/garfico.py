import matplotlib.pyplot as plt
import numpy as np

# Configurando o backend 'Agg' para não abrir janelas gráficas interativas
plt.switch_backend('Agg')

# Entradas em termos de quantidade de elementos
entradas = [100, 1000, 10000, 100000, 1000000]

# Tempos de execução fornecidos
tempos_execucao = [0.000034, 0.002787, 0.140726, 29.928465, 1218.734490]

# Criação do gráfico
plt.figure(figsize=(8, 6))

# Plotando os dados
plt.plot(entradas, tempos_execucao, marker='o', linestyle='-', color='b', label="Tempo de Execução")

# Definindo escalas logarítmicas para os eixos X e Y
plt.xscale("log")
plt.yscale("log")

# Definindo os rótulos e título
plt.xlabel("Número de Elementos")
plt.ylabel("Tempo de Execução (s)")
plt.title("Comparação de Tempo de Execução com Entradas em Escala Logarítmica")

# Adicionando a legenda
plt.legend()

# Exibindo a grade
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Apenas mostrar o gráfico
plt.show()
