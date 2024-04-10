#include <stdio.h>
#include "funciones.h"

int main() {
	int numero;
	printf("Dame un número\n");
	scanf("%d", &numero);
	printf("El factorial de %d es %lu\n", numero, factorial(numero));
	return 0;
}
