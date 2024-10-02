#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define MAX_ROWS 3959
#define MAX_COLS 9

// Función para ordenar los números de menor a mayor
void ordenar(int *numeros, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (numeros[i] > numeros[j]) {
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

// Función para leer y procesar el archivo CSV en paralelo
void leer_csv_paralelo(char *filename, int *numeros, int n_args) {
    FILE *file;
    char line[256];
    int nproducto, concurso, R[6];
    float bolsa;
    char fecha[11];
    int i, j, fila_actual = 0;
    int filas_validas[MAX_ROWS];
    int counter = 0, frecuencia[7] = {0};

    // Abrir el archivo CSV
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        exit(1);
    }

    // Leer el archivo en paralelo
    #pragma omp parallel private(i, j, R, fecha) shared(counter, filas_validas, frecuencia)
    {
        #pragma omp for
        for (fila_actual = 0; fila_actual < MAX_ROWS; fila_actual++) {
            
            sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%s", &nproducto, &concurso, &R[0], &R[1], &R[2], &R[3], &R[4],&R[5],&R[6],&bolsa, fecha);
            if (nproducto != 40) continue;

            // Verificar si el primer número aparece en las columnas R1-R6
            for (j = 0; j < 6; j++) {
                if (numeros[0] == R[j]) {
                    #pragma omp critical
                    {
                        frecuencia[0]++;
                        filas_validas[counter] = fila_actual;
			counter++;
                    }
                    break;
                }
            }
        }
    }
    fclose(file);

    // Procesar los números restantes si existen
    for (i = 1; i < n_args; i++) {
        int aux_counter = 0;
        int nuevas_filas_validas[MAX_ROWS];

        // Reabrir el archivo para filtrar las filas válidas
        file = fopen(filename, "r");
        fila_actual = 0;

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%s", &nproducto, &concurso, &R[0], &R[1], &R[2], &R[3], &R[4],&R[5],&R[6],&bolsa, fecha);
            if (nproducto != 40) continue;

            // Filtrar solo las filas previamente válidas
            for (j = 0; j < counter; j++) {
                if (fila_actual == filas_validas[j]) {
                    // Verificar si el número actual está en R1-R6
                    for (int k = 0; k < 6; k++) {
                        if (numeros[i] == R[k]) {
			    #pragma omp critical
			    {
                            frecuencia[i]++;
                            nuevas_filas_validas[aux_counter++] = fila_actual;
			    }
                            break;
                        }
                    }
                    break;
                }
            }

            fila_actual++;
        }
        fclose(file);

        // Actualizar las filas válidas para la siguiente búsqueda
        memcpy(filas_validas, nuevas_filas_validas, aux_counter * sizeof(int));
        counter = aux_counter;
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
        numeros[i-1] = atoi(argv[i]);
        if (numeros[i-1] < 1 || numeros[i-1] > 56) {
            printf("Error: Los números deben estar entre 1 y 56.\n");
            return 1;
        }
    }

    // Ordenar los números
    ordenar(numeros, argc - 1);

    // Leer el archivo CSV y procesar los números
    leer_csv_paralelo("historico.csv", numeros, argc - 1);

    return 0;
}
