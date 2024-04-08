#include <stdio.h>

int main(void){
	char nombre[30];
	printf("Escriba su nombre: ");
	gets(nombre);
	printf("Hola %s\n", nombre);
	return 0;
}

