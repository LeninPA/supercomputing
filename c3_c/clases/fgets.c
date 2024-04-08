#include <stdio.h>

int main(void){
	// fgets (variable, limite, stream)
	char nombre[30];
	printf("EScriba su nombre");
	fgets(nombre, 30, stdin);
	puts(nombre);
	return 0;
}

