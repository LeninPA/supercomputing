#include <stdio.h>

void peano(unsigned int n){
	if ( n == 0 ){
		printf("0 ");
	} else {
		peano(n - 1);
		printf("%d ", n);
	}
}

int main() {
	peano(10);
	return 0;
}
