#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

/* Input: Apuntador de caracteres
 * Output: Tamaño de la cadena
 * Obtiene la cantidad de caracteres en una cadena
 * sin tomar en cuenta el caracter de pausa \0
 */
int tamano_cadena(char *s) {
        int tamano = 0;
        while(*s) {
                tamano++;
                s++;
        }
        return tamano;
}


int main ( int argc , char *argv[] ) {
	// Obtenemos cadena
	char cadena[MAX_LENGTH + 1];
	char new_cadena[MAX_LENGTH + 1];
	printf("Proporcione una cadena: \n");
	fgets(cadena, sizeof(cadena), stdin);
	printf("La cadena ingresada es: \n");
	puts(cadena);
	// Invertimos cadena
	int tamagno = tamano_cadena(cadena);
	for ( int i = 0 ; i < tamagno ; i++ ) {
		new_cadena[tamagno - i - 1] = cadena[i];
	}
	printf("La cadena invertida es: ");
	puts(new_cadena);

	return EXIT_SUCCESS;
}
