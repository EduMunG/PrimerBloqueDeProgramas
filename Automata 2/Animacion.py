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
        ruta=list(map(int,patron.findall(linea)))
        #int(n) for n in patron.findall(linea)
        return ruta
    
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
    estados1 = leer_ruta_desde_archivo("Ganadores_1.txt")
    print(estados1)
    estados2 = leer_ruta_desde_archivo("Ganadores_2.txt")
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

        # Add a boolean flag to indicate if the game is esperar for a piece to move
        esperar = False

        if not fin_del_juego:
            if indice1 < len(estados1) and indice2 < len(estados2):
                # Check for collision
                if estados1[indice1] == estados2[indice2]:
                    print("Choque potencia detectado")

                    # Se decide Aleatoriamente que pieza va a esperar\
                    if random.choice([True, False]):
                        # Pieza 1 espera, mientras pieza 2 avanza
                        #restamos el indice, para que busque desde el movimiento pasdado, asi pueda continuar a otro
                        nueva_ruta2 = ruta_nueva("Ganadores_2.txt", estados2[indice2], indice2)
                        while nueva_ruta2[indice2-1]!= estados2[indice2-1]:
                            if nueva_ruta2 is not None:
                                nueva_ruta2= ruta_nueva("Ganadores_2.txt",estados2[indice2], indice2)
                            else: break
                        indice2-=1
                        if nueva_ruta2 is not None:
                            estados2 = nueva_ruta2
                            print("La segunda pieza ha encontrado otro camino.", nueva_ruta2)
                        else:
                            print("No se ha encontrado otra ruta, esperando...")
                            esperar = True
                    else:
                        # Piece 2 waits, Piece 1 finds a new route
                        nueva_ruta1 = ruta_nueva("Ganadores_1.txt", estados1[indice1], indice1)
                        while nueva_ruta1[indice1-1]!= estados1[indice1-1]:
                            if nueva_ruta1 is not None:
                                nueva_ruta1= ruta_nueva("Ganadores_1.txt",estados1[indice1], indice1)
                            else: break
                        indice1-=1
                        if nueva_ruta1 is not None:
                            estados1 = nueva_ruta1
                            print("La primera pieza ha encontrado otro camino.",nueva_ruta1)
                        else:
                            print("No se ha encontrado otra ruta, esperando...")
                            esperar = True
                    
                    # Si una nueva ruta se ha encontrado, se mueven de inmediato
                    #sino, esperan

                # Si no esperan, muevelas
                if not esperar:
                    if indice1 < len(estados1):
                        dibujar_pieza(ventana, estados1[indice1], "AZUL")
                        indice1 += 1
                    if indice2 < len(estados2):
                        dibujar_pieza(ventana, estados2[indice2], "VERDE")
                        indice2 += 1
            elif indice1 < len(estados1):  #si la otra pieza acabo, que solo se mueva la 1
                dibujar_pieza(ventana, estados1[indice1], "AZUL")
                indice1 += 1
            elif indice2 < len(estados2):  # si la otra pieza acabo, que solamente se mueva la 2
                dibujar_pieza(ventana, estados2[indice2], "VERDE")
                indice2 += 1
            else:
                # No hay mas movimeintos, terminar el juego
                fin_del_juego = True
        else:
            mensaje = fuente.render('Fin del juego, no hay más rutas', True, (255, 255, 255))
            rect = mensaje.get_rect(center=(200, 200))
            ventana.blit(mensaje, rect)

        pygame.display.flip()
        clock.tick(1)  

    pygame.quit()


if __name__ == "__main__":
    main()
