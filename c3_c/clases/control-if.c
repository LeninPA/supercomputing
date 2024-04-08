#include <stdio.h>

int main(void){
	if (400 > 35){
		// Usar if en caso de que importe más el flujo que el valor
		printf ("Mayor\n"); 
	} else if (400 < 35) {
		printf ("Acabas de romper las matemáticas");
	}
	char nivel;
	printf("Dame tu nivel de acceso: ");
	scanf("%c", &nivel);
	switch ( nivel ) {
		case 'A':
			printf("Acceso clase ejecutivo\n");
			break;
		case 'B':
			printf("Acceso clase turista top\n");
			break;
		case 'C':
			printf("Acceso clase turista\n");
			break;
		default :
			printf("Mantenimiento\n");
	}
	return 0;
}
