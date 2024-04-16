#include <stdio.h>

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int *ptr;
	int pares = 0, impares = 0;
	ptr = arr;
	for ( int i = 0 ; i < 10 ; i++ ) {
		if ( *ptr % 2 == 0 ) {
			pares++;
		} else {
			impares++;
		}
		ptr++;
	}
	printf("La cantidad de   pares es %d\n",   pares);
	printf("La cantidad de impares es %d\n", impares);
	return 0;
}
