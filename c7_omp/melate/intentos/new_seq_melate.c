#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 3959
#define MAX_COLS 9

// Función para ordenar los números de menor a mayor
void ordenar(int *numeros, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (numeros[i] > numeros[j]) {
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

// Función para contar los 1s en la máscara
int contar_ones(int *mascara, int n_filas) {
    int count = 0;
    for (int i = 0; i < n_filas; i++) {
        if (mascara[i] == 1) {
            count++;
        }
    }
    return count;
}

// Función para leer y procesar el archivo CSV utilizando máscaras
void leer_csv(char *filename, int *numeros, int n_args) {
    FILE *file;
    char line[256];
    int nproducto, concurso, R[7];
    float bolsa;
    char fecha[11];
    int i, j, fila_actual = 0;
    int filas_validas[MAX_ROWS];
    int counter = 0, frecuencia[7] = {0};
    int mascara[MAX_ROWS] = {0};

    // Abrir el archivo CSV
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        exit(1);
    }

    // Leer el archivo línea por línea
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%s", &nproducto, &concurso, &R[0], &R[1], &R[2], &R[3], &R[4], &R[5], &R[6], &bolsa, fecha);
        if (nproducto != 40) continue;

        // Verificar si el primer número aparece en las columnas R1-R6
        for (j = 0; j < 6; j++) {
            if (numeros[0] == R[j]) {
                frecuencia[0]++;
                mascara[fila_actual] = 1;  // Activar la máscara para esta fila
                break;
            }
        }
        fila_actual++;
    }
    fclose(file);

    // Procesar los números restantes si existen
    for (i = 1; i < n_args; i++) {
        int nueva_mascara[MAX_ROWS] = {0};
        int aux_counter = 0;

        // Reabrir el archivo para filtrar las filas válidas
        file = fopen(filename, "r");
        fila_actual = 0;

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%f,%s", &nproducto, &concurso, &R[0], &R[1], &R[2], &R[3], &R[4], &R[5], &bolsa, fecha);
            if (nproducto != 40) continue;

            // Si la fila está activada en la máscara, proceder a verificar
            if (mascara[fila_actual] == 1) {
                if (i < 6) { // Para los primeros 6 números buscar en R1-R6
                    for (j = 0; j < 6; j++) {
                        if (numeros[i] == R[j]) {
                            frecuencia[i]++;
                            nueva_mascara[fila_actual] = 1;  // Activar la nueva máscara
                            aux_counter++;
                            break;
                        }
                    }
                } else { // Para el séptimo número solo buscar en R7 (R[6])
                    if (numeros[i] == R[6]) {
                        frecuencia[i]++;
                        nueva_mascara[fila_actual] = 1;
                        aux_counter++;
                    }
                }
            }
            fila_actual++;
        }
        fclose(file);

        // Actualizar la máscara
        memcpy(mascara, nueva_mascara, MAX_ROWS * sizeof(int));
    }

    // Imprimir las frecuencias
    printf("Frecuencia del primer número: %d\n", frecuencia[0]);
    for (i = 1; i < n_args; i++) {
        printf("Frecuencia del número %d: %d\n", i + 1, frecuencia[i]);
    }
}

int main(int argc, char *argv[]) {
    int numeros[7];
    int i;

    // Verificar el número de argumentos
    if (argc < 2 || argc > 8) {
        printf("Error: El programa acepta entre 1 y 7 números.\n");
        return 1;
    }

    // Leer los argumentos y verificar que estén entre 1 y 56
    for (i = 1; i < argc; i++) {
        numeros[i - 1] = atoi(argv[i]);
        if (numeros[i - 1] < 1 || numeros[i - 1] > 56) {
            printf("Error: Los números deben estar entre 1 y 56.\n");
            return 1;
        }
    }

    // Ordenar los números
    ordenar(numeros, argc - 1);

    // Leer el archivo CSV y procesar los números
    leer_csv("historico.csv", numeros, argc - 1);

    return 0;
}
