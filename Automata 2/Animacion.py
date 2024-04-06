import pygame
import re
import random

# Inicializa Pygame
pygame.init()
pygame.font.init()

def dibujar_tablero(ventana):
    NEGRO = (0, 0, 0)
    ROJO = (255, 0, 0)
    FILAS, COLUMNAS = 4, 4
    ANCHO_TABLERO, ALTO_TABLERO = 400, 400

    for fila in range(FILAS):
        for columna in range(COLUMNAS):
            color = NEGRO if (fila + columna) % 2 == 0 else ROJO
            rect = (columna * ANCHO_TABLERO / COLUMNAS, fila * ALTO_TABLERO / FILAS, ANCHO_TABLERO / COLUMNAS, ALTO_TABLERO / FILAS)
            pygame.draw.rect(ventana, color, rect)

def estado_a_posicion(estado):
    FILAS, COLUMNAS = 4, 4
    ANCHO_TABLERO, ALTO_TABLERO = 400, 400
    fila, columna = (estado - 1) // COLUMNAS, (estado - 1) % COLUMNAS
    return columna * ANCHO_TABLERO / COLUMNAS, fila * ALTO_TABLERO / FILAS

def dibujar_pieza(ventana, estado, color):
    x, y = estado_a_posicion(estado)
    if color == "AZUL":
        pygame.draw.polygon(ventana, (0, 0, 255), [(x + 50, y), (x + 100, y + 50), (x, y + 50)])
    elif color == "VERDE":
        centro = (int(x + 50), int(y + 25))
        pygame.draw.circle(ventana, (0, 255, 0), centro, 20)

def leer_ruta_desde_archivo(nombre_archivo):
    patron = re.compile(r'\b\d+\b')
    with open(nombre_archivo, "r") as archivo:
        linea = archivo.readline()
        return [int(n) for n in patron.findall(linea)]
    
def ruta_nueva(nombre_archivo, estado_buscado, indice_buscado):
    import re
    patron = re.compile(r'\b\d+\b')
    
    # Leer todas las rutas del archivo y convertirlas en listas de enteros
    with open(nombre_archivo, "r") as archivo:
        rutas = [list(map(int, patron.findall(linea))) for linea in archivo]

    # Filtrar las rutas para encontrar aquellas que tienen el estado buscado en el índice buscado
    rutas_validas = [ruta for ruta in rutas if len(ruta) > indice_buscado and ruta[indice_buscado] == estado_buscado]

    # Si no se encuentran rutas válidas, se puede retornar la ruta actual o manejar de otra manera
    if not rutas_validas:
        print("No se encontraron rutas válidas.")
        return None

    # Selecciona aleatoriamente una de las rutas válidas
    nueva_ruta = random.choice(rutas_validas)

    return nueva_ruta


def main():
    ventana = pygame.display.set_mode((400, 400))
    pygame.display.set_caption("Tablero de Ajedrez")

    # Supongamos que estas funciones leen los estados iniciales de las piezas desde los archivos
    estados1 = leer_ruta_desde_archivo("winis.txt")
    print(estados1)
    estados2 = leer_ruta_desde_archivo("Winis2.txt")
    print(estados2)
    clock = pygame.time.Clock()

    fuente =pygame.font.SysFont('arial', 30)
    fin_del_juego=False
    running = True
    indice1, indice2 = 0, 0  # Índices para seguir el progreso de cada pieza a través de sus estados

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        ventana.fill((255, 255, 255))
        dibujar_tablero(ventana)


        # Verifica si ambas piezas aún tienen movimientos restantes
        if indice1 < len(estados1) and indice2 < len(estados2):
            # Verifica colisión
            if estados1[indice1] == estados2[indice2]:
                print("Colisión detectada. Ajustando ruta...")
                # Aquí necesitas lógica para ajustar la ruta. Esta es una función de ejemplo
                # que necesitarías implementar según las reglas de tu juego
                estados1 = ruta_nueva("winis.txt", estados1, indice1)
                if estados1 is None:
                    estados2 = ruta_nueva("Winis2.txt",estados2,indice2)
                if estados2 is None and estados1 is None:
                    #escribir "fin de juego " en pantalla
                    fin_del_juego=True
            else:
                # Dibuja las piezas en sus posiciones actuales si no hay colisión
                dibujar_pieza(ventana, estados1[indice1], "AZUL")
                dibujar_pieza(ventana, estados2[indice2], "VERDE")
                indice1 += 1  # Avanza la pieza 1
                indice2 += 1  # Avanza la pieza 2
        elif indice1 < len(estados1):  # Solo la pieza 1 tiene movimientos restantes
            dibujar_pieza(ventana, estados1[indice1], "AZUL")
            indice1 += 1
        elif indice2 < len(estados2):  # Solo la pieza 2 tiene movimientos restantes
            dibujar_pieza(ventana, estados2[indice2], "VERDE")
            indice2 += 1
        else:
            # Ninguna pieza tiene movimientos restantes, el juego puede terminar
            running = False
        if fin_del_juego:
            mensaje = fuente.render('Fin del juego, no hay mas rutas', True, (255,255,255))
            rect= mensaje.get_rect(center=(400/2,400/2))
            ventana.blit(mensaje,rect)


        pygame.display.flip()
        clock.tick(1)  # Ralentiza el bucle para visualizar el movimiento

    pygame.quit()


if __name__ == "__main__":
    main()
