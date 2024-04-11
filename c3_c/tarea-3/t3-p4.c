#include <stdio.h>

int main() {
		int n, exp, cifras;
		exp = 1;
		cifras = 0;
		printf("Ingresa el número entero:\n");
		scanf("%d", &n);
		while ( n / exp != 0){
				cifras += 1;
				exp *= 10;
		}
		int vals[cifras];
		exp/=10;
		for ( int i = cifras ; i > 0 ; i-- ) {
				vals[i - 1] = n / exp;
				n -= (n / exp) * exp;
				exp /= 10;
		}
		printf("Escribiendo el número de manera inversa:\n");
		for ( int j = 0 ; j < cifras ; j++ ) {
				printf("%d",vals[j]);
		}
		printf("\n");
		return 0;
}
