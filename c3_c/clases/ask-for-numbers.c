#include <stdio.h>

int main(void){
	// fgets (variable, limite, stream)
	int a,b;
	printf("Ingrese un número: ");
	scanf("%d", &a);
	printf("Ingrese otro número: ");
	scanf("%d", &b);
	printf("El mayor es: %d\nEl menor es: %d\n", a > b ? a : b,a <= b ? a : b);
	return 0;
}

