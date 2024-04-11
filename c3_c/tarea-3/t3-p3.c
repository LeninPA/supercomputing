#include <stdio.h>

int main() {
		unsigned int n;
		printf("Ingrese el entero para aplicar el factorial: \n");
		scanf("%d", &n);
		int vals[n + 1];
		vals[0] = 1;
		for ( int i = 1 ; i < n + 1 ; i++ ) {
				vals[i] = i * vals[i-1];
		}
		printf("El fatorial de %d es: %d\n", n, vals[n]);
		return 0;
}
