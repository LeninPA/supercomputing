#include <stdio.h>

int main() {
	int A[3][3] = { {2, 0, 1} , {3, 0, 0} , {5, 1, 1} };
	int B[3][3] = { {1, 0, 1} , {1, 2, 1} , {1, 1, 0} };
	printf("A =\n");
	/*
	 * Visualización de matrices
	 */
	for ( int i = 0 ; i < 3 ; i++ ) {
		printf("| ");
		for ( int j = 0 ; j < 3 ; j++ ) {
			// Impresión A
			printf("%d ", A[i][j]);
		}
		printf("|\n");
	}
	printf("B =\n");
	for ( int i = 0 ; i < 3 ; i++ ) {
		printf("| ");
		for ( int j = 0 ; j < 3 ; j++ ) {
			// Impresión B
			printf("%d ", B[i][j]);
		}
		printf("|\n");
	}
	/*
	 *  Producto punto
	 */
	int n = 3, m = 3, l=3;
	int C[n][m];
	int suma=0;
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < l ; j++ ) {
			suma = 0;
			for ( int k = 0 ; k < m ; k++ ) {
				suma += A[i][k]*B[k][j];
			}
			C[i][j] = suma;
		}
	}
	/*
	 *  Visualizar matriz C
	 */
	printf("C=\n");
	for ( int i = 0 ; i < n ; i++ ) {
		printf("| ");
		for ( int j = 0 ; j < m ; j++ ) {
			// Impresión B
			printf("%d ", C[i][j]);
		}
		printf("|\n");
	}
	return 0;
}
