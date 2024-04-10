#include <stdio.h>
#include "mis_funciones.h"

int main() {
	int num1, num2;
	printf("Dame un número:\n");
	scanf("%d", &num1);
	printf("Dame otro número:\n");
	scanf("%d", &num2);

	printf("La suma de %d y %d es %d\n", num1, num2, suma(num1, num2));
	printf("La resta de %d y %d es %d\n", num1, num2, resta(num1, num2));
	printf("La multiplicación de %d y %d es %d\n", num1, num2, multiplica(num1, num2));
	printf("La división de %d y %d es %f\n", num1, num2, divide(num1, num2));
	return 0;
}
