#include <stdio.h>

int main() {
	int a, b, res;
	char op, opg;
	// Menú
	printf("Lista de operaciones\n");
	printf("1  :  Suma\n");
	printf("2  :  Resta\n");
	printf("3  :  Multiplicación\n");
	printf("4  :  División\n");
	printf("Indique una operación a realizar: \n");
	scanf("%c", &op);
	if ( op != '1' && op != '2' &&  op != '3' && op != '4' ){
		printf("Operación seleccionada no es válida\n");
		return 2;
	}
	// Operaciones
	printf("Ingrese el primer  operando: \n");
	scanf("%d", &a);
	printf("Ingrese el segundo operando: \n");
	scanf("%d", &b);
	switch ( op ) {
		case '1':
			res = a + b;
			opg = '+';
			break;
		case '2':
			res = a - b;
			opg = '-';
			break;
		case '3':
			res = a * b;
			opg = '*';
			break;
		case '4':
			if ( b != 0 ){
				res = a / b;
				opg = '/';
			} else {
				printf("Operando no válido\n");
				return 1;
			}
			break;
		default :
			printf("Operación seleccionada no válida\n");
			return 2;
	}
	printf("El resultado de %d %c %d es %d\n", a, opg, b, res);
	return 0;
}
