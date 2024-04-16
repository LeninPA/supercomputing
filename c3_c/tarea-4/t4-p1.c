#include <stdio.h>
#include <stdlib.h>

int* fib ( unsigned int n ) {
	if ( n < 2 ) {
		int *terminos = calloc(2, sizeof(int));
		terminos[0] = 1;
		terminos[1] = 1;
		return terminos;
	}
	int *terminos = calloc(n, sizeof(int));
	terminos[0] = 1;
	terminos[1] = 1;
	for ( int i = 2 ; i < n ; i++ ) {
		terminos[i] = terminos[i-1] + terminos[i-2];
	}
	return terminos;
}
void ver_arr ( int arr[] , unsigned int n ) {
	if ( n != 0 ){
		ver_arr(arr, n-1);
	}
	printf("%d ", arr[n]);
	return ;
}
int main() {
	int n;
	printf("Ingresa un número entero: \n");
	scanf("%d", &n);
	int* terminos = fib(n);
	printf("Los primeros %d números de la serie son: \n", n);
	ver_arr(terminos, n - 1);
	printf("\n");
	return 0;
}
