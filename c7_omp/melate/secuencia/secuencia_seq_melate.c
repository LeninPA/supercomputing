#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_ROWS 3959
#define MAX_COLS 9


// Comparison function
void ordenar(int *numeros, int n) { 
	int i, j, temp;
	for ( i = 0 ; i < n - 1 ; i++ ) {
		for ( j = i + 1 ; j < n ; j++ ) {
			if ( numeros[i] > numeros[j] ){
				temp = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = temp;
			}
		}
	}
}

// Calcula frecuencia
int count_ones(int* mascara, int n){
	int suma = 0;
	for ( int i = 0 ; i < n ; i++ ) {
		suma += mascara[i];
	}
	return suma;
}
// Visualizar vector
void plista(int* lista, int n)
{
	for ( int i = 0 ; i < n ; i++ ) {
		printf("%d,", lista[i]);
	}
	printf("\n");
}
// Read CSV
void leer_csv(char *filename, int *numeros, int n_args){
	FILE *file;
	char line[256];
	int nproducto, concurso, R[7];
	float bolsa;
	char fecha[11];
	int i, j, fila_actual = -1;
	int filas_validas[MAX_ROWS];
	int counter = 0, frecuencia[7] = {0};
	int total[7][MAX_ROWS] = {0};
	int mascara[7][MAX_ROWS] = {0};

	// Abrir el archivo CSV por primera vez
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: No se pudo abrir el archivo %s\n", filename);
		exit(1);
	}
	// Primera lectura línea por línea
	while( fgets( line, sizeof(line), file ) )
	{
		sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%s", &nproducto, &concurso, &R[0], &R[1], &R[2], &R[3], &R[4], &R[5], &R[6], &bolsa, fecha);
		// Búsqueda del primer número
		if (fila_actual > -1)
		{
			for ( j = 0 ; j < 7 ; j++ ) {
				total[j][fila_actual] = R[j];
				if ( numeros[0] == R[j] )
					mascara[0][fila_actual] = 1;
			}
		}
		fila_actual++;
	}
	fclose(file);
	concurso = 0;
	int parcial = 0;
	int apariciones = 0;
	for ( int k = 1 ; k < 57 ; k++ ) {
		apariciones = 0;
		for ( fila_actual = 0 ; i < MAX_ROWS ; i++ ) {
			if ( total[6][fila_actual] == k ) 
			{
				apariciones ++;
			}
		}
		parcial += apariciones;
		printf("El %2d aparece %4d veces\n", k, apariciones);
	}
	printf("El total de concursos es %d\n", parcial);
	frecuencia[0] = count_ones(mascara[0], MAX_ROWS);
	printf("Frecuencia de %2d: %3d\n",numeros[0], frecuencia[0]);
	// Lectura demás números
	for ( i = 1 ; i < n_args ; i++ )
	{
		for ( fila_actual = 0 ; fila_actual < MAX_ROWS ; fila_actual++ )
		{
			if ( i == 6)
			{
				if ( mascara[5][fila_actual] == 1 && numeros[6] == total[6][fila_actual] )
				{
					mascara[6][fila_actual] = 1;
				}
			}
			else
			{
				for ( j = 0 ; j < 6 ; j++)
				{
					if ( mascara[i-1][fila_actual] == 1 && numeros[i] == total[j][fila_actual] )
					{
						mascara[i][fila_actual] = 1;
					}
				}
			}
		}
		frecuencia[i] = count_ones(mascara[i], MAX_ROWS);
		printf("Frecuencia de %2d: %3d\n",numeros[i], frecuencia[i]);
	}
}

int main(int argc, char *argv[]) {
	struct timeval stop, start;
	int numeros[7] = {0};
	int i;
	if ( argc < 2 || argc > 8 )
	{
		printf("Error: El programa acepta entre 1 y 7 números.\n");
		return 1;
	}
	// Leer argumentos
	for (i = 1; i < argc; i++) {
		numeros[i - 1] = atoi(argv[i]);
		if (numeros[i - 1] < 1 || numeros[i - 1] > 56) {
			printf("Error: Los números deben estar entre 1 y 56.\n");
			return 1;
		}
	}
	// Leer CSV
	gettimeofday(&start, NULL);
	leer_csv("historico.csv", numeros, argc - 1);
	gettimeofday(&stop, NULL);
	printf("Time: %lu\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
	return 0;
}
