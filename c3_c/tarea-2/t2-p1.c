#include <stdio.h>

#define max(x,y) ( x > y ? x : y )

int main() {
	int a,b,c, m;
	printf("Ingresa un número: ");
	scanf("%d", &a);
	printf("Ingresa otro número: ");
	scanf("%d", &b);
	printf("Ingresa un último número: ");
	scanf("%d", &c);
	if ( a < b ){
		m = max(b,c);
	} else {
		m = max(a,c);
	}
	printf("El número más grande es %d\n", m);
	return 0;
}
