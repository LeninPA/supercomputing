#include <stdio.h>
#include "funciones.h"

int main() {
		// Declaración de variables
		int n, suma, maxi, mini;
		float prom;
		suma = 0;
		// Creación de arreglos
		printf("Ingrese el número de elementos a capturar: ");
		scanf("%d", &n);
		int vals[n];
		for ( int i = 0 ; i < n ; i++ ) {
				// Escaneo de elementos
				printf("Ingrese el elemento %d: ", i + 1);
				scanf("%d", &vals[i]);
				// Total
				suma += vals[i];
				// Mínimo y máximo
				if ( i == 0 ) {
						maxi = vals[0];
						mini = vals[0];
				} else {
						maxi = maximo( maxi, vals[i] );
						mini = minimo( mini, vals[i] );
				}
		}
		printf("\n*****\nResultados\n*****\n");
		printf("Total:    %d\n", suma);
		printf("Máximo:   %d\n", maxi);
		printf("Mínimo:   %d\n", mini);
		printf("Promedio: %f\n", (float) suma/n );
		return 0;
}
