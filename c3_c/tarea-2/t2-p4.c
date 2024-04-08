#include <stdio.h>

int main() {
	unsigned int a,b;
	printf("Ingresa un número: \n");
	scanf("%d", &a);
	printf("Ingresa otro número: \n");
	scanf("%d", &b);
	printf("El máximo común divisor de %d y %d es ", a, b);
	while ( a != b ) {
		if ( a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	printf("%d\n", a);
	return 0;
}
