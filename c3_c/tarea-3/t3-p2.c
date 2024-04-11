#include <stdio.h>

int main() {
		unsigned int n;
		printf("Ingrese el número de elementos a capturar: ");
		scanf("%d", &n);
		if ( n == 0 ) {
				printf("La suma de los números impares es: 0\n");
				printf("La suma de los números impares es: 0\n");
		} else {
				int pares, impares;
				pares = n / 2;
				impares = pares + n % 2;
				printf("La suma de los números impares del 1 al %d es: %d\n", n, impares * impares);
				printf("La suma de los números   pares del 1 al %d es: %d\n", n, pares * (pares+1));
		}
		return 0;
}
