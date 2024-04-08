#include <stdio.h>

int main() {
	unsigned int temp = 0, f1 = 0, f2 = 1, n = 1;
	printf("Ingresa un número entero no negativo: \n");
	scanf("%d", &n);
	printf("Los primeros %d términos (y el cero) de la sucesión de fibonacci son\n", n);
	printf("%d %d ", f1, f2);
	for ( int i = 0 ; i < n - 1 ; i++ ) {
		// Code
		temp = f1;
		f1 = f2;
		f2 = temp + f1;
		printf("%d ", f2);
	}
	printf("\n");
	return 0;
}
