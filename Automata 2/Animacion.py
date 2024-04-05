import pygame
import re
def verificar(fila_1, columna_1, fila_2, columna_2):
    if fila_1 == fila_2 and columna_1 == columna_2:
        return True
    

def dibujar_tablero(ventana):
    NEGRO = (0, 0, 0)
    ROJO = (255, 0, 0)
    FILAS = 4
    COLUMNAS = 4
    ANCHO_TABLERO = 400
    ALTO_TABLERO = 400

    for fila in range(FILAS):
        for columna in range(COLUMNAS):
            color = NEGRO if (fila + columna) % 2 == 0 else ROJO
            pygame.draw.rect(ventana, color, (columna * ANCHO_TABLERO / COLUMNAS, fila * ALTO_TABLERO / FILAS, ANCHO_TABLERO / COLUMNAS, ALTO_TABLERO / FILAS))

def dibujar_pieza_1(ventana, fila, columna):
    AZUL = (0, 0, 255)
    ANCHO_TABLERO = 400
    ALTO_TABLERO = 400
    FILAS = 4
    COLUMNAS = 4

    pygame.draw.polygon(ventana, AZUL, [(columna * ANCHO_TABLERO / COLUMNAS + ANCHO_TABLERO / (2 * COLUMNAS), fila * ALTO_TABLERO / FILAS), ((columna + 1) * ANCHO_TABLERO / COLUMNAS, (fila + 1) * ALTO_TABLERO / FILAS), (columna * ANCHO_TABLERO / COLUMNAS, (fila + 1) * ALTO_TABLERO / FILAS)])

def dibujar_pieza_2(ventana, fila, columna):
    VERDE = (0, 255, 0)
    ANCHO_TABLERO = 400
    ALTO_TABLERO = 400
    FILAS = 4
    COLUMNAS = 4

    pygame.draw.circle(ventana, VERDE, (int((columna * ANCHO_TABLERO / COLUMNAS) + (ANCHO_TABLERO / (2 * COLUMNAS))), int((fila * ALTO_TABLERO / FILAS) + (ALTO_TABLERO / (2 * FILAS)))), int(min(ANCHO_TABLERO / COLUMNAS, ALTO_TABLERO / FILAS) * 0.4))


def main():

    ANCHO_VENTANA = 400
    ALTO_VENTANA = 400
    COLUMNAS = 4

    movimientos_1 = leer_ruta_desde_archivo("winis.txt")
    movimientos_2 = leer_ruta_desde_archivo("Winis2.txt")

    ventana = pygame.display.set_mode((ANCHO_VENTANA, ALTO_VENTANA))
    pygame.display.set_caption("Tablero de Ajedrez")

    posicion_actual_1 = 0
    posicion_actual_2 = 0
    fila_1 = 0
    columna_1 = 0
    fila_2 = 0
    columna_2 = 4

    posicion_actual_1_T = 1
    posicion_actual_2_T = 1
    fila_1_T = 0
    columna_1_T = 0
    fila_2_T = 0
    columna_2_T = 4

    running = True
    while running:
        if running:
            dibujar_tablero(ventana)


            if posicion_actual_1 < len(movimientos_1):
                movimiento = movimientos_1[posicion_actual_1]
                fila_1 = (movimiento - 1) // COLUMNAS
                columna_1 = (movimiento - 1) % COLUMNAS
                dibujar_pieza_1(ventana, fila_1, columna_1)
            
            if posicion_actual_2 < len(movimientos_2):
                movimiento = movimientos_2[posicion_actual_2]
                fila_2 = (movimiento - 1) // COLUMNAS
                columna_2 = (movimiento - 1) % COLUMNAS
                dibujar_pieza_2(ventana, fila_2, columna_2)


            if posicion_actual_1_T < len(movimientos_1):
                movimiento = movimientos_1[posicion_actual_1_T]
                fila_1_T = (movimiento - 1) // COLUMNAS
                columna_1_T = (movimiento - 1) % COLUMNAS
            
            if posicion_actual_2_T < len(movimientos_2):
                movimiento = movimientos_2[posicion_actual_2_T]
                fila_2_T = (movimiento - 1) // COLUMNAS
                columna_2_T = (movimiento - 1) % COLUMNAS

            
             # Verificar si las piezas están a punto de llegar a la misma casilla
            if verificar(fila_1_T, columna_1_T, fila_2_T, columna_2_T):
                print("¡Las piezas están a punto de llegar a la misma casilla!")
                print("Movimiento",movimientos_1[posicion_actual_1], posicion_actual_1)
                movimientos_1  = ruta_nueva("winis.txt",movimientos_1[posicion_actual_1],posicion_actual_1)
                print(movimientos_1)
                posicion_actual_1 = posicion_actual_1 -1
                movimiento = movimientos_1[posicion_actual_1]
                pygame.time.wait(10000) 
            
             
            pygame.display.flip()
            pygame.time.delay(1500)
            posicion_actual_1 += 1
            posicion_actual_2 += 1
            posicion_actual_1_T += 1
            posicion_actual_2_T += 1
                

            max_len = [len(movimientos_1), len(movimientos_2)]

            # Cerrar ventana
            if max(max_len) == posicion_actual_1:
                pygame.time.delay(2500)
                running = False
    pygame.quit()


def leer_ruta_desde_archivo(nombre_archivo):
    
    with open(nombre_archivo, "r") as archivo:
        primera_linea = archivo.readline()
        ruta = list(map(int, primera_linea.strip().strip("[q<-|br']").split(", ")))
    return ruta

def ruta_nueva(nombre_archivo, movimiento, posicion):

    with open(nombre_archivo, "r") as archivo:
        lineas = archivo.readlines()

        # Procesar cada línea del archivo
        for linea in lineas:
            ruta = list(map(int, linea.strip().strip("[]").split(",")))
            if movimiento != ruta[posicion]:
                print(f"{movimiento} != {ruta[posicion]}")
                return ruta

if __name__ == "__main__":
    main()
