# Programa-5-Connecting-Towns

## Descripción del problema
Las ciudades en un mapa están conectadas por varias carreteras. El número de carreteras entre cada ciudad está en un arreglo y la ciudad es 0 la ubicación inicial. El número de carreteras de ciudad 0 a ciudad es 1 el primer valor del arreglo, de ciudad 1 a ciudad 2 es el segundo, y así sucesivamente.

¿Cuántos caminos hay desde la ciudad 0 hasta la última ciudad de la lista, módulo 1234567?

### Ejemplo
n = 4

rutas = [3,4,5]

Hay 3 caminos a la ciudad 1, 4 caminos a la ciudad 2 y 5 caminos a la ciudad 3. El número total de caminos es 3x4x5 mod 1234567 = 60.

int n: el número de ciudades int rutas[n-1]: el número de rutas entre ciudades

## Instrucciones de uso
Se descargara el archivo "Connecting_Towns.c" (código fuente) y el archivo "input5.txt" (entradas de muestra para el problema) y se colocarán en una misma carpeta. El archivo "town.c" se recomienda compilar en el programa Dev-C++, al compilar la consola directamente acabara el programa, pero habrá creado un nuevo archivo "output5.txt" que contendra el resultado del problema.
