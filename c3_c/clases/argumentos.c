#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char *argv[] ) {
	printf("Total de argumentos: %d\n", argc);
	for ( int i = 0 ; i < argc ; i++ ) {
		printf("argv[%d] es %s\n", i, *(argv + i));
	}
	return EXIT_SUCCESS;
}
