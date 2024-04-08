#include <stdio.h>

int main() {
	int lim;
	printf("Ingresa límite: \n");
	scanf("%d",&lim);
	for ( int i = 0; i <= lim ; i++ ) {
		// Code
		if ( i % 2 == 0 ) {
			printf("%d\n", i);
		} 
	}
	return 0;
}
