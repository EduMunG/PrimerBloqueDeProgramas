import requests
from bs4 import BeautifulSoup
import shutil

automata = {
    'q0': {'f': 'q1', 't': 'q16', 'v': 'q22'},
    'q1': {'e': 'q2'},
    'q2': {'m': 'q3', 'r': 'q11'},
    'q3': {'i': 'q4'},  
    'q4': {'n': 'q5'},  
    'q5': {'a': 'q6', 'i': 'q8'},
    'q6': {'z': 'q7'},
    'q7': {'i': 'qf1'},  
    'q8': {'s': 'q9'},
    'q9': {'t': 'q10'},
    'q10': {'a': 'qf2'},  
    'q11': {'m': 'q12'},  
    'q12': {'i': 'q13'},  
    'q13': {'n': 'q14'}, 
    'q14': {'a': 'q15'},
    'q15': {'l': 'qf3'}, 
    'q16': {'o': 'q17'},
    'q17': {'n': 'q18', 'r':'q20'},
    'q18': {'t': 'q19'},
    'q19': {'a': 'qf4' }, 
    'q20': {'t': 'q21'}, 
    'q21': {'a': 'qf5'}, 
    'q22': {'i': 'q23'}, 
    'q23': {'e': 'q24'},
    'q24': {'j': 'q25'}, 
    'q25': {'a': 'qf6'},
    'qf1' : ' ', # Estado final para "feminazi"
    'qf2' : ' ', # Estado final para "feminista"
    'qf3' : ' ', # Estado final para  "ferminal"
    'qf4' : ' ', # Estado final para  "tonta"
    'qf5' : ' ', # Estado final para  "torta"
    'qf6' : ' ', # Estado final para  "vieja"
}

def verificar_palabra(texto, archivo_historial):
    archivo_historial.write("\n\n")
    estado_actual = 'q0'
    for caracter in texto:
        archivo_historial.write(f"Caracter leído: {caracter}, Nuevo estado: {estado_actual}\n")
        if caracter in automata[estado_actual]:
            estado_actual = automata[estado_actual][caracter]
        else:
            return False
    return estado_actual in ['qf1', 'qf2', 'qf3', 'qf4', 'qf5', 'qf6']

def dividir_texto(url, archivo_historial, archivo_conteo):
    archivo_historial.write("Historial del Automata\n\n")
    archivo_conteo.write("\nPalabras contadas:\n\n")
    response = requests.get(url)
    if response.status_code != 200:
        archivo_historial.write(f"No se pudo acceder a la página: {url}\n")
        return {}, 0

    soup = BeautifulSoup(response.text, 'html.parser')

    texto_pagina = soup.get_text()
    palabras_pagina = texto_pagina.split()
    frecuencia_palabras = {}
    contador_palabras = 0
    palabras_aceptadas = []

    for palabra in palabras_pagina:
        palabra = palabra.strip(",.!?;:«").lower()
        if verificar_palabra(palabra, archivo_historial):
            frecuencia_palabras[palabra] = frecuencia_palabras.get(palabra, 0) + 1
            archivo_conteo.write(f"{frecuencia_palabras}\n")
            palabras_aceptadas.append(palabra)
            contador_palabras += 1
            
    for palabra, frecuencia in frecuencia_palabras.items():
        archivo_conteo.write(f"{palabra}: {frecuencia}\n")
    archivo_conteo.write(f"\nTotal de palabras contadas: {contador_palabras}")
    ubicacion_palabra_en_texto(texto_pagina, palabras_aceptadas, archivo_conteo)
    return frecuencia_palabras

def ubicacion_palabra_en_texto(texto, palabras_aceptadas, archivo_conteo):
    archivo_conteo.write("\nUbicacion de las Palabras:\n\n")
    parrafos = texto.split('\n\n')
    palabras_aceptadas = set(palabras_aceptadas)  # Convertir a conjunto para eliminar duplicados
    for palabra in palabras_aceptadas:
        for num_parrafo, parrafo in enumerate(parrafos, 1):
            lineas = parrafo.split('\n')
            for num_renglon, linea in enumerate(lineas, 1):
                palabras_linea = set(linea.lower().split())
                if palabra.lower() in palabras_linea:
                    archivo_conteo.write(f"La palabra '{palabra}' se encuentra en el párrafo {num_parrafo}, renglón {num_renglon}.\n")




url = "https://es.wikipedia.org/wiki/Feminazi"
nombre_archivo_historial = "Historia_del_proceso.txt"
nombre_archivo_conteo = "Conteno_de_Palabra.txt"

with open(nombre_archivo_conteo, "w", encoding="utf-8") as archivo_conteo:
    with open(nombre_archivo_historial, "w", encoding="utf-8") as archivo_historial:
        frecuencia_palabras_pagina = dividir_texto(url, archivo_historial, archivo_conteo)


ruta_archivo_salida_1 = "./Programas Unidos/output/Historia_del_proceso.txt"
shutil.move("Historia_del_proceso.txt", ruta_archivo_salida_1)

ruta_archivo_salida_2 = "./Programas Unidos/output/Conteno_de_Palabra.txt"
shutil.move("Conteno_de_Palabra.txt", ruta_archivo_salida_2)


if frecuencia_palabras_pagina:
    print(f"Se han generado con exito los archios {nombre_archivo_conteo} y {nombre_archivo_historial} ")
else:
    print("No se encontraron palabras aceptadas por el autómata en la página web o se produjo un error al acceder a la página.")