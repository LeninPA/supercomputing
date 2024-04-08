#include <stdio.h>

int main(void){
	char c;
	printf("Escriba un caracter: ");
	c = getchar();
	printf("El caracter que escribió: ");
	putchar(c);
	printf("\n");
	return 0;
}

