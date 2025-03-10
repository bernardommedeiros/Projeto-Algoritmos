import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline  # Para suavização
import numpy as np

plt.switch_backend('tkAgg')

# Medir tempos de execução para diferentes tamanhos de entrada
entradas = [100, 1000, 10000, 100000, 1000000]
tempos = [0.000080, 0.000875, 0.011023, 0.156112, 2.437116]

# Converter para numpy arrays para manipulação
entradas = np.array(entradas)
tempos = np.array(tempos)

# Criar uma interpolação spline
x_novo = np.logspace(np.log10(entradas.min()), np.log10(entradas.max()), 500)
spline = make_interp_spline(entradas, tempos)
y_suave = spline(x_novo)

# Criar o gráfico
plt.figure(figsize=(8, 5))
plt.plot(x_novo, y_suave, label="Tempo de execução", color="blue")
plt.scatter(entradas, tempos, color="red", label="Entrada")  # Mostrar os pontos reais
plt.xscale("log")  # Escala logarítmica para o eixo X
plt.yscale("linear")
plt.title("Entrada x Tempo de execução em Python", fontsize=18)
plt.xlabel("Tamanho da entrada (n)", fontsize=12)
plt.ylabel("Tempo de execução (s)", fontsize=12)
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.legend()
plt.show()