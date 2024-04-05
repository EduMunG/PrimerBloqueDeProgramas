## BLoque de programas 1
# ESCOM <Eduardo Muñoz González>


Primer bloque de programas.
# Automata 1
Programa 1: universo

Programar el universo de las cadenas binarias (\Sigma^n). Dada una "n" que introduzca el usuario o que el programa lo determine automáticamente. El rango de "n" debe de estar en el intervalo de [0, 1000].

1. Debe de correr en modo automático (todo) y de forma manual.
2. El programa debe de preguntar si quiere calcular otra "n" o no y salir hasta que se le especifique.
3. La salida debe ser expresada en notación de conjunto, debe ir a un archivo de texto.
4. Del archivo de salida, graficar el número de unos de cada cadena. El eje de las "x" se representan las cadenas y el eje de las "y" el número de unos que tiene esa cadena. Específicamente en el reporte, explicar, calcular y graficar cuando n=28. Adicionalmente, con los mismos valores, calcular la gráfica pero ahora con logaritmo base 10.
5. En el reporte debe de estar también el código fuente de la implementación en latex.

# Automata 2
Elaborar un programa para realizar movimientos ortogonales y diagonales en un tablero de ajedrez de 4x4 con dos piezas. Los movimientos y las reglas están explicadas en las láminas del curso de Stanford.

Adicionalmente, el programa debe de contar con las siguientes características:

1. Debe de correr en modo automático (todo) y de forma manual.
2. En el caso de forma manual, el usuario podrá introducir la cadena de movimientos o generarla aleatoriamente.
3. El programa debe de correr con dos jugadores.
4. El primer jugador inicia en la posición 1 y su estado final es en la posición 16, el segundo jugador iniciará en el estado 4 y su estado final es el estado 13.
5. Cuando inicie el juego, de manera aleatoria el programa debe decidir quién inicia.
6. Una vez definida la cadena de movimientos para uno o dos piezas, se deben generar los archivos de todos los movimientos posibles por pieza, generar otro archivo con todos los movimientos ganadores por pieza. Estos dos últimos archivos servirán para reconfigurar las rutas.
7. Si se reconfigura una ruta y aún así no se puede avanzar, entonces habrá que esperar una iteración para continuar.
8. Graficar el tablero y mostrar los movimientos.
9. Graficar toda la red (NFA) generada por los movimientos de ambos jugadores.
10. El número máximo de movimientos deberá de ser entre 4 y 100 símbolos.
11. Incluir en el reporte el código fuente en latex.

# Automata 3
Programar el autómata que reconozca todas las palabras del siguiente conjunto de palabras {ferminal, feminazi, tonta, torta, vieja, feminista}.

1. Diseñar el NFA y transformarlo a DFA mostrando todo los cálculos en el reporte.
2. Realizar la conversión a DFA mostrando todo el proceso a través de los subconjuntos y tablas.
3. El programa deberá de leer un archivo de texto (o de internet), podría ser de una página web.
4. El autómata deberá de identificar cada palabra reservada con el DFA, contarlas e indicar dónde las encontró (posición (x,y) en el archivo). Enumerar, contar y anotar donde están las palabras encontradas.
5. En un archivo imprimir la evaluación del autómata por cada carácter que lea y el cambio de estado, es decir, toda la historia del proceso.
7. Graficar el DFA.
8. Incluir en el reporte el código fuente en latex.