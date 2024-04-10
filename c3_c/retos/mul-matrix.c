#include <stdio.h>

int main() {
		// A ∈ Mat(n,m), B ∈ Mat(m,l)
		int n = 3, m = 3, l = 2;
		int A[3][3] = { { 3, 2, 1 }, { 1, 1, 3 }, { 0, 2, 1} };
		int B[3][2] = { { 2, 1 }, { 1, 0 }, { 3, 2 } };
		int C[3][2];
		printf("C=\n");
		// Producto de matrices
		for ( int i = 0 ; i < n ; i++ ) {
				printf("| ");
				for ( int j = 0 ; j < l ; j++ ) {
						C[i][j] = 0;
						for ( int k = 0 ; k < m ; k++ ) {
								C[i][j] += A[i][k]*B[k][j];
						}
						printf("%d ", C[i][j]);
				}
				printf("|\n");
		}
		return 0;
}
