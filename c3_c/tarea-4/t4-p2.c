#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int menu(){
	unsigned int n;
	printf("Selecciona una de las siguientes opciones del menú:\n");
	printf("1) Calcular el cuadrado de un número\n");
	printf("2) Calcular el área de un círculo proporcionando el valor del radio\n");
	printf("3) Calcular el área de un rectángulo dando el largo y el ancho\n");
	printf("4) Calcular la velocidad con base en el tiempo y la distancia\n");
	printf("5) Salir\n");
	printf("Opción: ");
	scanf("%d", &n);
	return n;
}

void cuadrado() {
	float f;
	//system("clear");
	printf("Ingrese un número: ");
	scanf("%f", &f);
	printf("Su cuadrado es %f\n", f * f);
}
void circulo() {
	float f;
	//system("clear");
	printf("Ingrese el radio del círculo: ");
	scanf("%f", &f);
	printf("El área del círculo es %f\n",PI * f * f);
}
void rectangulo(){
	float f,g;
	printf("Ingrese la base   del rectángulo: ");
	scanf("%f", &f);
	printf("Ingrese la altura del rectángulo: ");
	scanf("%f", &g);
	printf("El área del rectángulo es %f\n", f * g);
}

void velocidad(){
	float d,t;
	printf("Ingrese la distancia recorrida: ");
	scanf("%f", &d);
	printf("Ingrese la altura del rectángulo: ");
	scanf("%f", &t);
	if ( t != 0 ){
		printf("El valor de la velocidad es: %f\n", d / t);
	} else {
		printf("No se puede calcular la velocidad para tiempo cero\n");
	}
}

int main() {
	unsigned int n;
	do {
		n = menu();
		switch ( n ) {
		case 1 :
			cuadrado();
			break;
		case 2 :
			circulo();
			break;
		case 3 :
			rectangulo();
			break;
		case 4 :
			velocidad();
			break;
		default :
			printf("Regresando al menú principal...\n");
		}
	} while ( n != 5);
	system("clear");
	printf("Programa finalizado con éxito\n");
	return 0;
}
