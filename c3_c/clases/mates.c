#include <stdio.h>
#include <math.h>

int suma (int s1, int s2) {
	return s1 + s2;
}

int main() {
	printf("Biblioteca math.h\n");
	printf("2^3 = %f\n", pow(2,3));
	printf("2^(1/2) = %f\n", pow(2,0.5));
	printf("2^(1/2) = %f\n", sqrt(2));
	int a, b;
	printf("Dame un número: \n");
	scanf("%d", &a);
	printf("Dame otro número: \n");
	scanf("%d", &b);
	printf("La suma de %d y %d es %d\n", a, b, suma(a,b));
	return 0;
}
