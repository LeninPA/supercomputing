#include <stdio.h>

int mcd(int a, int b) {
	if ( b != 0 ){
		return mcd(b, a % b);
	} else {
		return a;
	}
}
int main() {
	unsigned int a,b;
	printf("Escribe un entero positivo: ");
	scanf("%d", &a);
	printf("Escribe otro entero positivo: ");
	scanf("%d", &b);
	if ( a != 0 && b != 0 ) {
		printf("El mcd de %d y %d es %d \n", a, b, mcd(a,b));
	} else if (a == 0 && b == 0) {
		printf("Como el cero se puede dividir por cualquier número, el mcd no está bien definido en este caso\n");
	} else {
		printf("El mcd de %d y %d es %d \n", a, b, a > b ? a : b);
	}
	return 0;
}
