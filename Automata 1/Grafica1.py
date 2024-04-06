import matplotlib.pyplot as plt
import re

frecuenciasa = []
frecuenciasb = []

patron = re.compile(r'\d+')
with open('../Frecuencia.txt', 'r') as file:
    for line in file:
        if 'Frecuencia a:' in line:
            frecuenciasa.extend([int(num) for num in patron.findall(line)])
        elif 'Frecuencia b:' in line:
            frecuenciasb.extend([int(num) for num in patron.findall(line)])

# Suponiendo que las frecuencias son agregadas correctamente,
# y queremos una comparación lado a lado de 'a' y 'b' para cada grupo

indices = range(len(frecuenciasa))
width = 0.3  # Ancho de las barras

plt.bar([i - width/2 for i in indices], frecuenciasa, width=width, label='Frecuencia a', color='blue')
plt.bar([i + width/2 for i in indices], frecuenciasb, width=width, label='Frecuencia b', color='green')

plt.xlabel('Índice')
plt.ylabel('Frecuencia')
plt.title('Comparación de Frecuencias de a y b')
plt.legend()

plt.show()
