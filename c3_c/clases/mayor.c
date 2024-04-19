#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char *argv[] ) {
	if ( argc != 4 ){
		printf("ERROR: Ingrese 3 números enteros exactamente\n");
		return EXIT_FAILURE;

	}
	int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]);
	int maxi = a > b ? a : b;
	printf("a: %d, b: %d, c: %d\n", a, b, c);
	printf("El máximo de los tres números es: %d\n", maxi > c ? maxi : c);
	return EXIT_SUCCESS;
}
