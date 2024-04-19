#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invierte ( char* cadena ) {
	char* ncadena = calloc(sizeof(cadena),sizeof(char));
	strcpy(ncadena, cadena);
	int n = sizeof(cadena) - 1;
	char *inicio, *fin, temp;
	inicio = ncadena;
	fin = ncadena + n - 1;
	for ( int i = 0 ; i < ( n - 1 ) / 2 ; i++ ) {
		// swap
		temp = *fin;
		*fin = *inicio;
		*inicio = temp;
		// actualización punterior
		inicio++;
		fin--;
	}
	return ncadena;
}

int main ( int argc , char *argv[] ) {
	printf("Cadena a invertir: %s\n", argv[0]);
	printf("Cadena invertida:  %s\n", invierte(argv[0]));
	printf("Cadena original:   %s\n", argv[0]);
	return EXIT_SUCCESS;
}
